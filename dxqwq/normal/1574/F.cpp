// Problem: F. Occurrences
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/F
// Memory Limit: 512 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
namespace fgz
{
const long long p=998244353;
long long qp(long long x,int y)
{
    long long res=1;
    for(long long now=x; y; now=now*now%p,y>>=1)
     if(y&1) res=res*now%p;
    return res;
}
long long A[1<<22],B[1<<22],ans[2][1<<22];
int rev[1<<22],N,M;
void init()
{
    int d=N>>1;
    rev[0]=0,rev[1]=N>>1;
    for(int i=2; i<=N; i<<=1)
    {
        d>>=1;
        for(int j=0; j<i; ++j) rev[i+j]=rev[j]|d;
    }
    return ;
}
void NTT(long long* F,int op)
{
    for(int i=0; i<N; ++i) if(rev[i]>i) swap(F[i],F[rev[i]]);
    for(int len=2,M=1; len<=N; len<<=1,M<<=1)
    {
        long long w=qp(op?3:332748118,998244352/len);
        //omega(m,1)
        for(int l=0,r=len-1; l<=N; l+=len,r+=len)
        {
            long long w0=1;
            for(int i=l; i<l+M; ++i)
            {
                long long x=(F[i]+w0*F[i+M]%p)%p,y=(F[i]+p-w0*F[i+M]%p)%p;
                F[i]=x,F[i+M]=y,w0=w0*w%p;
            }
        }
    }
}
void getinv(long long* BB,int len)
{
	int t=1;
    ans[0][0]=qp(BB[0],998244351);
    for(N=2,M=1; M<(len<<1); t^=1)
    {
        init();
        for(int i=0; i<M; ++i) ans[t][i]=(ans[t^1][i]<<1)%p;
        for(int i=0; i<M; ++i) A[i]=BB[i];
        NTT(ans[t^1],1),NTT(A,1);
        for(int i=0; i<N; ++i) ans[t^1][i]=ans[t^1][i]*ans[t^1][i]%p*A[i]%p;
        NTT(ans[t^1],0);
        long long inv=qp(N,998244351);
        for(int i=0; i<N; ++i) ans[t^1][i]=ans[t^1][i]*inv%p;  
        for(int i=0; i<M; ++i) ans[t][i]=(ans[t][i]+p-ans[t^1][i])%p;
        N<<=1,M<<=1;      
    }
    memset(A,0,sizeof(A));
    for(int i=0; i<1048576; ++i) A[i]=ans[t^1][i];
    return ;
}
long long cnt[1<<22];
void main(vector<long long>&Q,int MMM)
{
	for(int i:Q) if(i<=MMM) ++cnt[i];
	int M=1;
	for(;M<=MMM;M<<=1);
	cnt[0]=1;
	for(int i=1; i<M; ++i) cnt[i]=(p-cnt[i])%p;
	getinv(cnt,M);
	printf("%lld\n",A[MMM]%p);
}
};
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
vector<int> a[300003];
vector<int> Q;
int sz[1000003];
vector<int> e[1000003];
int in[1000003],out[1000003];
map<pair<int,int>,bool> mp;
void add(int x,int y)
{
	if(mp[make_pair(x,y)]) return ;
	e[x].push_back(y);
	e[y].push_back(x);
++in[y],++out[x];
	mp[make_pair(x,y)]=1;
	return ;
}
int res=1;
bool vis1[1000003],vis2[1000003];
int gg=0,sss=0;
void dfs1(int x)
{
	if(vis1[x]) return ;
	vis1[x]=1;++gg;
	if(!in[x]) sss|=1;
	if(!out[x]) sss|=2;
	if(in[x]>1||out[x]>1) res=0;
	for(int i:e[x]) dfs1(i);
	return ;
}
void dfs2(int x)
{
	if(vis2[x]) return ;
	vis2[x]=1;sz[x]=gg;
	for(int i:e[x]) dfs2(i);
	return ;
}
signed main()
{
	int n=read(),m=read(),k=read();
	for(int i=1; i<=k; ++i) sz[i]=1;
	for(int i=1; i<=n; ++i)
	{
		int T=read();
		a[i].resize(T);
		for(int j=0; j<T; ++j) a[i][j]=read();
		for(int j=0; j+1<T; ++j) 
			add(a[i][j],a[i][j+1]);
	}
	for(int i=1; i<=k; ++i) if(!vis1[i]) 
	{
		res=1;gg=0;sss=0;
		dfs1(i);
		if(sss!=3) res=0;
		if(res) dfs2(i);
	}
	for(int i=1; i<=k; ++i) if(!in[i]&&vis2[i])
	Q.push_back(sz[i]); 
	fgz::main(Q,m);
	return 0;
}