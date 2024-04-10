#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define SZ(x) ((int)x.size())
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 202000,inf=0x3f3f3f3f;
int n,q,l[N],cnt[N]; char s[N],t[N];
Vi e[N]; int ch[N][26],fail[N],sz; int fin[N],mrk[N],L[N],R[N];
void ins(char *s, int n, int tp) {
	int now=0;
	rep(i,1,n) {
		int c=s[i]-'a';
		if (!ch[now][c]) ch[now][c]=++sz;
		now=ch[now][c];
	}
	fin[now]=tp;
}
int a[N],len;
void query(char *s, int n) {
	int now=0;
	rep(i,1,n) {
		int c=s[i]-'a'; now=ch[now][c]; mrk[now]=i;
	}
}
void getfail() {
	queue<int> q;
	rep(i,0,25) if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		rep(i,0,25) if (ch[u][i]) {
			int v=ch[u][i],x=fail[u]; q.push(v);
			while (x&&!ch[x][i]) x=fail[x];
			fail[v]=ch[x][i];
		}
	}
	rep(i,1,sz) e[fail[i]].push_back(i);
}
inline void dfs(int u) {
	int rec=len; if (mrk[u]) a[++len]=mrk[u];
	per(i,SZ(e[u])-1,0) dfs(e[u][i]);
	L[fin[u]]=rec+1; R[fin[u]]=len;
}
int pos[N],buc[452],tt[N];
inline void getans(int n, int &res, int tp) {
	memset(buc,0,sizeof(buc));
	rep(i,1,n) buc[pos[i]%450]++;
	rep(i,1,450) buc[i]+=buc[i-1];
	per(i,n,1) tt[buc[pos[i]%450]--]=pos[i];
	memset(buc,0,sizeof(buc));
	rep(i,1,n) buc[pos[i]/450]++;
	rep(i,1,450) buc[i]+=buc[i-1];
	per(i,n,1) pos[buc[tt[i]/450]--]=tt[i];
	rep(i,1,n-cnt[tp]+1) res=min(res,pos[i+cnt[tp]-1]-pos[i]+l[tp]);
}
int main() {
	scanf("%s",s+1); n=strlen(s+1); read(q); ins(s,n,0);
	rep(i,1,q) {
		read(cnt[i]);scanf("%s",t+1);
		l[i]=strlen(t+1);ins(t,l[i],i);
	}
	query(s,n); getfail(); dfs(0);
	rep(i,1,q) {
		int ans=inf;rep(j,L[i],R[i]) pos[j-L[i]+1]=a[j];
		getans(R[i]-L[i]+1,ans,i); printf("%d\n",ans<inf?ans:-1);
	}
	return 0;
}