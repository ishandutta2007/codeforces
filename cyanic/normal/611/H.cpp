#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define loop(k,a) for(int k=a;~k;k=link[k])
#define qwq(x) cerr<<" #"<<#x<<" = "<<x<<endl;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
 
int prufer[7],c[7],e[7][7],cc[7];
int tmp[7][7],cur[7],owo[7];
int n,m,a,b,cnt;
char s[7],t[7];
 
const int N=105,M=405,inf=1e9;
struct Edge{int u,v,f,c;};
struct ISAP{
	int n,m,s,t,res;
	int num[N],cur[N],d[N];
	int link[M],h[N],p[N];
	Edge e[M];
	inline void init(int _n){
		n=_n,m=0,res=0;
		memset(h,-1,sizeof h);
		memset(cur,-1,sizeof cur);
	}
	inline void add(int u,int v,int w){
		e[m]=(Edge){u,v,0,w};
		link[m]=h[u],cur[u]=h[u]=m++;
		e[m]=(Edge){v,u,0,0};
		link[m]=h[v],cur[v]=h[v]=m++;
	}
	inline int aug(){
		int mn=inf;
		for(int x=t;x!=s;x=e[p[x]].u)
			mn=min(mn,e[p[x]].c-e[p[x]].f);
		for(int x=t;x!=s;x=e[p[x]].u)
			e[p[x]].f+=mn,e[p[x]^1].f-=mn;
		return mn;
	}
	int Maxflow(int _s,int _t){
		int u=_s;s=_s,t=_t;
		memset(num,0,sizeof num);
		memset(d,0,sizeof d),num[0]=n;
		while(d[s]<n){
			if(u==t)res+=aug(),u=s;
			int flag=0;
			loop(k,cur[u])
				if(e[k].f<e[k].c&&d[u]==d[e[k].v]+1){
					cur[u]=k,p[u=e[k].v]=k;
					flag=1;break;
				}
			if(flag)continue;
			int mn=n;
			loop(k,cur[u]=h[u])if(e[k].f<e[k].c)
				mn=min(mn,d[e[k].v]+1);
			if(!(--num[d[u]]))return res;
			num[d[u]=mn]++,u=(u==s?s:e[p[u]].u);
		}
		return res;
	}
}G;
 
int id[7][7],tot;
void doit(){
	vector<pii> E;
	memcpy(tmp,e,sizeof e);
	memcpy(cc,c,sizeof c);
	vi vec; rep(i,1,m)vec.pb(i);
	rep(i,1,m-2){
		int u=prufer[i],t=-1;
		REP(j,vec.size()){
			int appear=0;
			rep(k,i,m-2)
				if(prufer[k]==vec[j]){
					appear=1;break;
				}
			if(!appear){
				t=j;break;
			}
		}
		E.pb(mp(u,vec[t]));
		vec.erase(vec.begin()+t);
	}
	E.pb(mp(vec[0],vec[1]));
	REP(i,E.size()){
		if(E[i].fi>E[i].se)swap(E[i].fi,E[i].se);
		tmp[E[i].fi][E[i].se]--;
		if(tmp[E[i].fi][E[i].se]<0)return;
	}
	int aim=0;
	rep(i,1,m)cc[i]--,aim+=cc[i];
	int S,T; tot=m;
	rep(i,1,m)rep(j,i,m)
		id[i][j]=++tot;
	S=++tot,T=++tot;
	G.init(T);
	rep(i,1,m)rep(j,i,m){
		G.add(S,id[i][j],tmp[i][j]);
		G.add(id[i][j],i,inf);
		G.add(id[i][j],j,inf);
	}
	rep(i,1,m)G.add(i,T,cc[i]);
	if(G.Maxflow(S,T)!=aim)return;
	owo[1]=cur[1]=1;
	rep(i,2,m+1)owo[i]=cur[i]=cur[i-1]*10;
	for(auto x:E)printf("%d %d\n",owo[x.fi],owo[x.se]);
	rep(i,1,m)rep(j,i,m){
		int A=0,B=0;
		for(int k=G.h[id[i][j]];~k;k=G.link[k]){
			if(G.e[k].v==i)B+=G.e[k].f;
			else if(G.e[k].v==j)A+=G.e[k].f;
		}
		rep(k,1,A){
			printf("%d %d\n",owo[i],++cur[j]);
			cc[j]--,tmp[i][j]--;
		}
		rep(k,1,B){
			printf("%d %d\n",owo[j],++cur[i]);
			cc[i]--,tmp[i][j]--;
		}
	}
	exit(0);
}
 
void dfs(int k){
	if(k==m-1){
		doit();
		return;
	}
	rep(i,1,m){
		prufer[k]=i;
		dfs(k+1);
	}
}
 
int main(){
	read(n);
	if(n<=9){
		rep(i,1,n-1)printf("%d %d\n",i,i+1);
		return 0;
	}
	for(int t=1;t<=n;t*=10,m++);
	c[m]=n-9,c[1]=9;
	rep(i,2,m-1){
		c[i]=c[i-1]*10;
		c[m]-=c[i];
	}
	rep(i,1,n-1){
		scanf("%s%s",s,t);
		a=strlen(s),b=strlen(t);
		if(a>b)swap(a,b);
		e[a][b]++;
	}
	dfs(1),puts("-1");
	return 0;
}