#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
#ifndef MY
	#define putchar IO::_putchar
	#define getchar IO::_getchar
#endif
namespace IO
{
    const int sz=1<<15;
    char inbuf[sz],outbuf[sz];
    char *pinbuf=inbuf+sz;
    char *poutbuf=outbuf;
    inline char _getchar()
    {
        if (pinbuf==inbuf+sz)fread(inbuf,1,sz,stdin),pinbuf=inbuf;
        return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
        if (poutbuf==outbuf+sz)fwrite(outbuf,1,sz,stdout),poutbuf=outbuf;
        *(poutbuf++)=x;
    }
    inline void flush()
    {
        if (poutbuf!=outbuf)fwrite(outbuf,1,poutbuf-outbuf,stdout),poutbuf=outbuf;
    }
}
inline int read()
{
    int x=0,p=1;
	char c=getchar();
    while (c<'0' || c>'9'){
    	if (c=='-') p=-1;
    	c=getchar();
	}
    while (c>='0' && c<='9') x=x*10+c-48,c=getchar();
    return x*p;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                //xor:a[i+j]=x+y,a[i+j+d]=x-y;
	                //and:a[i+j]=x+y;
	                //or:a[i+j+d]=x+y;
	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
	                //and:a[i+j]=x-y;
	                //or:a[i+j+d]=y-x;
	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
namespace Maxflow{
	const int Maxn=1005;
	struct edge{
		int to,rev,cap;
		edge(int _to,int _rev,int _cap){
			to=_to,rev=_rev,cap=_cap;
		}
	};
	int src=1002,snk=1003;
	vector<edge> G[Maxn];
	int dist[Maxn],seen[Maxn];
	int n;
	void Clear(){
		for (int i=0;i<Maxn;i++) G[i].clear();
	}
	void bfs(int s){
		for (int i=0;i<Maxn;i++) dist[i]=-1;
		dist[s]=0;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty()){
			int x=Q.front();
			Q.pop();
			for (int i=0;i<G[x].size();i++){
				edge &e=G[x][i];
				if (e.cap && dist[e.to]==-1){
					dist[e.to]=dist[x]+1;
					Q.push(e.to);
				}
			}
		}
	}
	int dfs(int now,int dest,int fl){
		if (now==dest) return fl;
		for (int &i=seen[now];i<G[now].size();i++){
			edge &ed=G[now][i];
			if (ed.cap && dist[ed.to]==dist[now]+1){
				int f=dfs(ed.to,dest,min(fl,ed.cap));
				if (f){
					ed.cap-=f;
					G[ed.to][ed.rev].cap+=f;
					return f;
				}
			}
		}
		return 0;
	}
	int dinic(int s=src,int t=snk){
		int ret=0;
		while (1){
			memset(seen,0,sizeof(seen));
			bfs(s);
			if (dist[t]==-1) return ret;
			int f=dfs(s,t,INF);
			while(f){
				ret+=f;
				f=dfs(s,t,INF);
			}
		}
	}
};
namespace Geometry{
	struct iP{
		LL x,y;
		iP(LL _x,LL _y){
			x=_x,y=_y;
		}
		iP(){
			x=y=0;
		}
		iP operator +(iP p){
			return iP(x+p.x,y+p.y);
		}
		iP operator -(iP p){
			return iP(x-p.x,y-p.y);
		}
		iP operator *(LL k){
			return iP(x*k,y*k);
		}
		LL det(iP p){
			return x*p.y-y*p.x;
		}
		LL dot(iP p){
			return x*p.x+y*p.y;
		}
		LL dist(){
			return x*x+y*y;
		}
		bool operator <(const iP &p)const{
			if (x!=p.x) return x<p.x;
			return y<p.y;
		}
	};
	struct dP{
		double x,y;
		dP(double _x,double _y){
			x=_x,y=_y;
		}
		dP(){
			x=y=0.0;
		}
		dP operator +(dP p){
			return dP(x+p.x,y+p.y);
		}
		dP operator -(dP p){
			return dP(x-p.x,y-p.y);
		}
		dP operator *(double k){
			return dP(x*k,y*k);
		}
		double det(dP p){
			return x*p.y-y*p.x;
		}
		double dot(dP p){
			return x*p.x+y*p.y;
		}
		double dist(){
			return x*x+y*y;
		}
		bool operator <(const dP &p)const{
			if (x!=p.x) return x<p.x;
			return y<p.y;
		}
	};
	vector<iP> convex_hull(iP X[],int l){
		#define sz ret.size()
		vector<iP> ret;
		sort(X+1,X+1+l);
		ret.pb(X[1]);
		for (int i=2;i<=l;i++){
			while (sz>=2 && (ret[sz-2]-X[i]).det(ret[sz-1]-X[i])>=0){
				ret.pop_back();
			}
			ret.pb(X[i]);
		}
		int rs=ret.size()+1;
		for (int i=l-1;i>=1;i--){
			while (sz>=rs && (ret[sz-2]-X[i]).det(ret[sz-1]-X[i])>=0){
				ret.pop_back();
			}
			ret.pb(X[i]);
		}
		return ret;
	}
};
const int Maxn=1e7+5;
const ULL mod=4294967296ull;
LL a[Maxn];
LL mx[Maxn];
int pos[Maxn];
ULL b[Maxn];
int n;
LL l,r,x,y,z;
LL Solve(int lo,int hi){
	if (lo>hi) return 5e18;
	mx[lo-1]=1e18;
	for (int i=lo;i<=hi;i++){
		if (a[i]<mx[i-1]){
			mx[i]=a[i];
			pos[i]=i;
		}
		else{
			mx[i]=mx[i-1];
			pos[i]=pos[i-1];
		}
	}
	LL ret=5e18;
	while (lo<=hi){
		int cur=pos[hi];
	//	cout<<cur<<endl;
		for (int j=cur+1;j<=hi;j++){
			if (a[cur]<a[j])ret=min(ret,a[cur]*a[j]);
		}
		hi=cur-1;
	}
	return ret;
}
LL Solve2(int lo,int hi){
	if (lo>hi) return 5e18;
	for (int i=lo;i<=hi;i++){
		//t[i]=a[i];
		if (a[i]<0) a[i]=-a[i];
	}
	reverse(a+lo,a+hi+1);
	mx[lo-1]=1e18;
	for (int i=lo;i<=hi;i++){
		if (a[i]<mx[i-1]){
			mx[i]=a[i];
			pos[i]=i;
		}
		else{
			mx[i]=mx[i-1];
			pos[i]=pos[i-1];
		}
	}
	LL ret=5e18;
	while (lo<=hi){
		int cur=pos[hi];
		for (int j=cur+1;j<=hi;j++){
			if (a[cur]<a[j])ret=min(ret,a[cur]*a[j]);
		}
		hi=cur-1;
	}
	return ret;
}
void mian(){
	scanf("%d %lld %lld %lld %lld %lld %llu %llu",&n,&l,&r,&x,&y,&z,&b[1],&b[2]);
	for (int i=3;i<=n;i++){
		b[i]=b[i-2]*(ULL)x%mod+b[i-1]*(ULL)y%mod+z;
		
		b[i]%=mod;
	}
	LL dd=5e18;
	for (int i=1;i<=n;i++){
		a[i]=(LL)b[i];
		a[i]=a[i]%(r-l+1)+l;
		//cout<<a[i]<<' ';
	}
//	cout<<endl;
	/*
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (a[i]<a[j]) dd=min(dd,a[i]*a[j]);
		}
	}
	printf("%lld\n",dd);*/
	int st=1,ed=n;
	while (st<=n && a[st]>0){
		st++;
	}
	while (ed>0 && a[ed]<0){
		ed--;
	}
	bool flag=true;
	for (int i=1;i<=n-1;i++) if (a[i]<a[i+1]) flag=false;
	if (flag){
		printf("IMPOSSIBLE\n");
		return;
	}
	if (ed!=st-1){
		mx[0]=0;
		for (int i=1;i<=n;i++){
			mx[i]=min(mx[i-1],a[i]);
		}
		LL res=0;
		for (int i=1;i<=n;i++){
			if (a[i]>0){
				res=min(res,a[i]*mx[i-1]);
			}
		}
		printf("%lld\n",res);
		return;
	}
	LL res=5e18;
	res=min(res,Solve(1,st-1));
	res=min(res,Solve2(st,n));
	if (res==5e18){
		printf("IMPOSSIBLE\n");
		return;
	}
	printf("%lld\n",res);
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		mian();
	}
}
/*
1
4 -1 3 2 3 4 2 2
*/