#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 600005;
int n,m,h;
int a[N],c[N][2];
bool mtr[2][2];

int head[N],edgenum,to[N<<1],nxt[N<<1];
inline void add(int u, int v) { //printf("e %d %d\n",u,v);
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline int ff(int a, int b) {return a+b>=h?a+b-h:a+b;}
inline int inv(int a) {return a<=n?a+n:a-n;}

int dfn[N],tot,cnt;
int sta[N],top,ans[N];
inline bool dfs(int u) { //printf("dfs %d\n",u);
	sta[++top]=u; dfn[u]=dfn[inv(u)]=1;
	ans[u]=1; ans[inv(u)]=0; tot++; cnt+=(u>n);
	L(i,u) if (!dfn[to[i]]) {
		if (!dfs(to[i])) return 0;
	}
	else if (!ans[to[i]]) return 0;
	return 1;
}
void clear() {
	while (top) {dfn[sta[top]]=0; ans[sta[top]]=0; dfn[inv(sta[top])]=0; ans[inv(sta[top])]=0; top--;}
	tot=0; cnt=0; top=0; //WA1
}

Vi dot[N];
int low[N],num,col[N],stack[N],col_num,deg[N],size[N];
bool instack[N];
inline void tarjan(int u) {
	dfn[u]=low[u]=++num; stack[++top]=u; instack[u]=1;
	L(i,u)
		if (!dfn[to[i]]) {
			tarjan(to[i]);
			low[u]=min(low[u],low[to[i]]);
		}
		else if (instack[to[i]]) low[u]=min(low[u],dfn[to[i]]);
	if (low[u]==dfn[u]) {
		++col_num; size[col_num]=1;
		while (stack[top]!=u) {
			instack[stack[top]]=0; dot[col_num].push_back(stack[top]);
			col[stack[top--]]=col_num; size[col_num]++;
		}
		top--; instack[u]=0; col[u]=col_num; dot[col_num].push_back(u);
	}
}
bool gun[N];
int s[N];
int main() { //freopen("1.in","r",stdin); //freopen("1.out","w",stdout);
	read(n); read(m); read(h);
	rep(i,1,n) read(a[i]);
	rep(i,1,m) rep(j,0,1) read(c[i][j]);
	rep(i,1,m) {
		rep(j,0,1) rep(k,0,1)
			mtr[j][k]=(ff(a[c[i][0]],j)!=ff(a[c[i][1]],k));
		rep(j,0,1) rep(k,0,1) if (mtr[j][k]&&!mtr[j][k^1]) add(c[i][0]+j*n,c[i][1]+k*n);
		rep(j,0,1) rep(k,0,1) if (mtr[j][k]&&!mtr[j^1][k]) add(c[i][1]+k*n,c[i][0]+j*n);
	}
//	puts("OwO");
	rep(i,1,n) if (!dfn[i]) {
		if (dfs(i)) {
			int CNT=cnt;
			clear();
			if (!dfs(i+n)||cnt>CNT) {
				clear(); dfs(i);
			}
		}
		else {
			clear();
			dfs(i+n);
		}
		tot=0; cnt=0; top=0;
	//	printf("[%d %d %d]\n",tot,cnt,top);
	//	while (top) printf("<%d>\n",sta[top--]);
	//	printf("ans[%d]=%d\n",i,ans[i]);
	}
	int len=0; rep(i,1,n)if(ans[i+n])s[++len]=i;
//	printf("len = %d\n",len);
	if (!len) {
		memset(dfn,0,sizeof(dfn)); clear();
		memset(size,0x3f3f3f3f,sizeof(size));
		rep(i,n+1,n*2) if (!dfn[i]) {
			tarjan(i);
		}
		rep(u,n+1,n*2) L(i,u) if (col[u]!=col[to[i]]) gun[col[u]]=1;
	//	rep(i,1,col_num) printf("%d %d\n",size[i],gun[i]);
	//	return 0;
		int mn=0; rep(i,1,col_num) if (!gun[i]&&(mn==0||size[i]<size[mn])) mn=i;
		printf("%d\n",size[mn]); sort(dot[mn].begin(),dot[mn].end());
		rep(i,0,size[mn]-1) printf("%d ",dot[mn][i]-n);
		return 0;
	}
	printf("%d\n",len);
	rep(i,1,len) printf("%d ",s[i]);
	return 0;
}