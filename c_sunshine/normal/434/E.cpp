#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
template<class T>inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T>inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}
inline void readi(int &x);
const int maxn=100005;
int n,nn,P,K,X;
int c[maxn],kp[maxn],ki[maxn];
int head[maxn],adj[maxn*2],next[maxn*2],tot;
int fa[maxn],siz[maxn],ss[maxn],used[maxn];
LL ans1[maxn],ans2[maxn];

struct node
{
	int v,id;
	node(){}
	node(const int &_a,const int &_b):v(_a),id(_b){}
	bool operator<(const node &o)const{return v<o.v;}
}A[maxn],B[maxn];
int cnt;

int pow(int a,int b,int c=P)
{
	int s=1;
	for(;b;b>>=1,a=(LL)a*a%c)
		if(b&1)s=(LL)s*a%c;
	return s;
}

void addedge(int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;
tot++;adj[tot]=u;next[tot]=head[v];head[v]=tot;}

int getroot(const int &x)
{
	int res=0;ss[x]=0;siz[x]=1;
	for(int t,i=head[x];i;i=next[i])
		if(!used[adj[i]]&&adj[i]!=fa[x])
		{
			fa[adj[i]]=x;
			t=getroot(adj[i]);
			siz[x]+=siz[adj[i]];
			rel(ss[x],siz[adj[i]]);
			if(!res||ss[t]<ss[res])res=t;
		}
	rel(ss[x],nn-siz[x]);
	if(!res||ss[x]<ss[res])res=x;
	return res;
}

void dfs(int x,int dep,int s1,int s2)
{
	s1=((LL)s1*K+c[x])%P;
	s2=((LL)kp[dep]*c[x]+s2)%P;
	cnt++;
	A[cnt]=node(((LL)X+P-s1)*ki[dep]%P,x);
	B[cnt]=node(s2,x);
	for(int i=head[x];i;i=next[i])
		if(!used[adj[i]]&&adj[i]!=fa[x])
		{
			fa[adj[i]]=x;
			dfs(adj[i],dep+1,s1,s2);
		}
}

void calc(int l,int r,int sgn)
{
	sort(A+l,A+r+1);
	sort(B+l,B+r+1);
	for(int i=l,j=l,p,q;i<=r;)
	{
		for(;j<=r&&B[j].v<A[i].v;j++);
		for(p=i;p<=r&&A[p].v==A[i].v;p++);
		for(q=j;q<=r&&B[q].v==A[i].v;q++);
    for(int k=i;k<p;k++)ans1[A[k].id]+=sgn*(q-j);
    for(int k=j;k<q;k++)ans2[B[k].id]+=sgn*(p-i);
    i=p,j=q;
	}
}

void solve(const int &x)
{
	used[x]=1;
	cnt=0;
	for(int lcnt,i=head[x];i;i=next[i])
		if(!used[adj[i]])
		{
			lcnt=cnt;
			fa[adj[i]]=x;
			dfs(adj[i],1,0,c[x]);
			calc(lcnt+1,cnt,-1);
		}
	cnt++;
	A[cnt]=node(X,x);
	B[cnt]=node(c[x],x);
	calc(1,cnt,1);
	for(int i=head[x];i;i=next[i])
		if(!used[adj[i]])
		{
			nn=siz[adj[i]];
			fa[adj[i]]=0,solve(getroot(adj[i]));
		}
}

int main()
{
	readi(n),readi(P),readi(K),readi(X);
	int KI=pow(K,P-2,P);
	kp[0]=ki[0]=1;
	for(int i=1;i<=n;i++)
		readi(c[i]),kp[i]=(LL)kp[i-1]*K%P,ki[i]=(LL)ki[i-1]*KI%P;
	for(int u,v,i=1;i<n;i++)
		readi(u),readi(v),addedge(u,v);
	nn=n;
	solve(getroot(1));
	LL ans=(LL)n*n*n*2;
	for(int i=1,p,q;i<=n;i++)
	{
		ans-=2LL*ans2[i]*(n-ans2[i]);
		ans-=2LL*ans1[i]*(n-ans1[i]);
		ans-=(LL)ans1[i]*(n-ans2[i]);
		ans-=(LL)ans2[i]*(n-ans1[i]);
	}
	ans>>=1;
	printf("%I64d\n",ans);
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c-'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';}