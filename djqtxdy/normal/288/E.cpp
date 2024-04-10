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
using namespace Mymath;
const int Maxn=100005;
const LL mod=1e9+7;
char tmp[Maxn];
LL p10[Maxn*2],S[Maxn],S_2[Maxn];
int n;
struct lucky{
	int val[Maxn];
	lucky(){
		;
	}
	void Plus(){
		for (int i=n-1;i>=0;i--){
			if (val[i]==4){
				val[i]=7;
				return;
			}
			val[i]=4;
		}
	}
	void Minus(){
		//cout<<n<<endl;
		for (int i=n-1;i>=0;i--){
			//cout<<"FUCK"<<endl;
			if (val[i]==7){
				val[i]=4;
				return;
			}
			val[i]=7;
		}
	}
}L,R;
void _init(){
	p10[0]=1;
	for (int i=1;i<Maxn*2;i++){
		p10[i]=p10[i-1]*10%mod;
	}
	S[0]=0;
	for (int i=1;i<Maxn;i++){
		S[i]=S[i-1]*2+p10[i-1]*11%mod*qp(2,i-1,mod)%mod;
		S[i]%=mod;
	}
	S_2[0]=0;
	for (int i=1;i<Maxn;i++){
		S_2[i]=S_2[i-1]*2+p10[2*(i-1)]*65%mod*qp(2,i-1,mod)+22LL*p10[i-1]%mod*S[i-1];
		S_2[i]%=mod;
	}
//	cout<<S_2[2]<<endl;
}
LL Sqr(LL x){
	return x*x%mod;
}
LL sqrsum(lucky X){
	//return Min^2+...+X^2
	LL ret=0;
	LL pre=0;
//	for (int i=0;i<n;i++) cout<<"debug"<<' '<<X.val[i]<<endl;
	bool flag=false;
	for (int i=0;i<n;i++){
		if (X.val[i]==4){
		//	cout<<111<<endl;
			pre+=4*p10[n-i-1];
			pre%=mod;
			flag=true;
		}
		else{
			pre+=4*p10[n-i-1];
			pre%=mod;
			ret+=Sqr(pre)*qp(2,n-i-1,mod);
			ret%=mod;
		//	cout<<S_2[n-i-1]<<' '<<S[n-i-1]<<endl;
			ret+=S_2[n-i-1];
			ret+=pre*2*S[n-i-1];
			ret%=mod;
			pre+=3*p10[n-i-1];
			pre%=mod;
		}
//		cout<<i<< ' '<<ret<<endl;
	}
//	cout<<flag<<' '<<pre<<endl;
	if (!flag) return 0;
	ret+=pre*pre;
	ret%=mod;
	return ret;
}
LL rangesum[Maxn][2][2],rangecnt[Maxn];
bool issg[Maxn];
int main(){
	_init();
	scanf("%s",tmp);
	n=strlen(tmp);
	for (int i=0;i<n;i++){
		L.val[i]=tmp[i]-'0';
	}
	scanf("%s",tmp);
	for (int i=0;i<n;i++){
		R.val[i]=tmp[i]-'0';
	}
//	for (int i=0;i<n;i++) cout<<L.val[i]<<' '<<R.val[i]<<endl;
	R.Minus();
	L.Minus();
	
//	cout<<sqrsum(R)<<endl;
	LL ans=sqrsum(R)-sqrsum(L);
	ans=(ans%mod+mod)%mod;
	L.Plus();
//	cout<<ans<<endl;
	//for (int i=0;i<n;i++) cout<<L.val[i]<<' '<<R.val[i]<<endl;
	LL nowL=0,nowR=0;
	rangecnt[0]=1;
	bool Sig=true;
	for (int i=1;i<=n;i++){
		LL ini=rangesum[i-1][0][0]*2+11*rangecnt[i-1]%mod*p10[n-i];
		rangecnt[i]=rangecnt[i-1]*2;
		rangecnt[i]%=mod;
		ini%=mod;
		
		nowL=nowL+p10[n-i]*L.val[i-1];
		nowL%=mod;
		nowR=nowR+p10[n-i]*R.val[i-1];
		nowR%=mod;
		if (L.val[i-1]==7){
			ini-=nowL-3*p10[n-i];rangecnt[i]--;
		}
		if (R.val[i-1]==4){
			ini-=nowR+3*p10[n-i];rangecnt[i]--;
		}
		if (rangecnt[i]!=1) Sig=false;
		ini=(ini%mod+mod)%mod;
		//cout<<i<<' '<<ini<<endl;
		for (int j=0;j<2;j++){
			for (int k=0;k<2;k++){
				rangesum[i][j][k]=ini-((j==0)?0:nowL)-((k==0)?0:nowR);
				rangesum[i][j][k]=(rangesum[i][j][k]%mod+mod)%mod;
				if (Sig && j==1 && k==1) rangesum[i][j][k]=0;
			}
		}
		issg[i]=Sig;
	}
	LL dlt=0;
	int l=0,r=0;
	LL Delta=3;
	LL nowval=4; 
	for (int i=n-1;i>=0;i--){
		
		int curl=l,curr=r;
		if (L.val[i]==7){
			curl=1;
		}
		if (R.val[i]==7){
			curr=0;
		}
	//	cout<<i<<' '<<curl<<' '<<curr<<endl;
		LL fuck=rangecnt[i];
		if (curl || curr){
			if (issg[i]){
				fuck=0;
			}
			else{
				fuck=fuck-curl-curr;
				if (fuck<0) fuck+=mod;
			}
		}
		dlt+=Delta*(rangesum[i][curl][curr]+fuck*nowval%mod);
		dlt%=mod;
		if (L.val[i]==4){
			l=0;
		}
		if (R.val[i]==4){
			r=1;
		}
		Delta=Delta*10-3;
		Delta=(Delta%mod+mod)%mod;
		nowval=nowval*10+7;
		nowval%=mod;
	//	cout<<dlt<<endl;
	}
	ans+=dlt;
	ans%=mod;
	printf("%lld\n",ans);
	return ~~(0^_^0);
}
/*
474
747
*/