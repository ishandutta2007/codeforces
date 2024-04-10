#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
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
const int N = 113456, M1 = 38, M2 = 1500, M = 666666;//TLE
int n,w,q,a[N],ans[N],pos[N],mx[N],mn[N],vmx[17][N],vmn[17][N];
struct Q{int ind,k;}que[N<<1],b[5500050];
bool cmp(Q a, Q b){return a.k<b.k;}
inline int max(int a, int b){return a>b?a:b;}
inline int min(int a, int b){return a<b?a:b;}
int nxt[N],jump[N],cnt[N],rt;//(jump,cnt)
Vi e[N];int mrk[N];
inline void dfs(int u, int dep){
	mrk[u]=dep;per(i,SZ(e[u])-1,0)dfs(e[u][i],dep+1);
}
inline void modify(int p, int q){
//	printf("modify %d %d\n",p,q);
	nxt[p]=q;if(q-p<=M1){
		int l=max(1,p-M1);//[l,p]
		rep(i,l,p)if(nxt[i]<=p)e[nxt[i]].pb(i);
		rt=p;dfs(p,0);
		for(register int i=l,j=p,t=0;i<=p;i++){
			while(nxt[j]-i<=M1)j=nxt[j],t++;if(mrk[i]>=0)jump[i]=j,cnt[i]=mrk[i]+t;
		}
		rep(i,l,p)e[i].clear(),mrk[i]=-1;
	}else {mx[p]=mn[p]=a[p];rep(i,p,q-1)mx[p]=max(mx[p],a[i]),mn[p]=min(mn[p],a[i]);}
}
inline void query(int p){//que[p]-->ans[que[p].ind]
//	printf("query %d\n",que[p].ind);
	int res=0,now=1;
	while(now<=n){
	//	printf("now = %d\n",now);
		if(nxt[now]-now<=M1){res+=cnt[now],now=jump[now];}
		else{
			while(nxt[now]-now<=M2&&nxt[now]<=n&&max(mx[now],a[nxt[now]])-min(mn[now],a[nxt[now]])<que[p].k)
				mx[now]=max(mx[now],a[nxt[now]]),mn[now]=min(mn[now],a[nxt[now]]),nxt[now]++;
			if(nxt[now]-now<=M2){now=nxt[now],res++;continue;}
			int q=now,mx=0,mn=1e9;
			per(i,16,0)if(q+(1<<i)-1<=n&&max(mx,vmx[i][q])-min(mn,vmn[i][q])<que[p].k)
				mx=max(mx,vmx[i][q]),mn=min(mn,vmn[i][q]),q+=1<<i;
			now=q;res++;//WA
		}
	}
	ans[que[p].ind]=res;
}
int main() {//freopen("1.in","r",stdin);
	memset(mrk,-1,sizeof(mrk));
	read(n);read(w);read(q);rep(i,1,n)read(a[i]);
	rep(i,1,n)vmx[0][i]=vmn[0][i]=a[i];
	rep(j,1,16)rep(i,1,n-(1<<j)+1){
		vmx[j][i]=max(vmx[j-1][i],vmx[j-1][i+(1<<j-1)]);
		vmn[j][i]=min(vmn[j-1][i],vmn[j-1][i+(1<<j-1)]);
	}
	rep(i,1,q){que[i].ind=i;int x;read(x);que[i].k=w-x+1;}//dif>=k
	sort(que+1,que+q+1,cmp);a[n+1]=2e9;nxt[n+1]=jump[n+1]=1e9;
	rep(i,1,n)pos[i]=nxt[i]=jump[i]=i+1,cnt[i]=1,mx[i]=mn[i]=a[i];
	per(i,n,1)modify(i,pos[i]);//init:jump
	int len=0;
	rep(i,1,n)while(pos[i]<=n&&pos[i]-i<=M1){
		mx[i]=max(mx[i],a[pos[i]]);mn[i]=min(mn[i],a[pos[i]]);
		b[++len]=(Q){i,mx[i]-mn[i]};pos[i]++;
	}
	rep(i,1,n)pos[i]=i+1,mx[i]=mn[i]=a[i];
	sort(b+1,b+len+1,cmp);int p=0;
	rep(t,1,q){
		while(p+1<=len&&b[p+1].k<que[t].k)p++,modify(b[p].ind,++pos[b[p].ind]);
		query(t);
	}
	rep(i,1,q)printf("%d\n",ans[i]-1);
	return 0;
}