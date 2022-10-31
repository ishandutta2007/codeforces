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
const int Maxn=1e5+5;
int n;
char c[Maxn];
LL ha[Maxn];
LL basepow[Maxn];
int Editpos,delta;
LL GetHash(int l,int r){
	if (l>Editpos || r<Editpos) return ha[r]-ha[l-1]*basepow[r-l+1];
	return ha[r]-ha[l-1]*basepow[r-l+1]+delta*basepow[r-Editpos]; 
}
bool isGray[Maxn][20];
int occ[Maxn][26];
int Graylen[26];
LL cntrbt[Maxn];
vector<pair<int,int> > Center[Maxn];
bool check(int l,int r){
	if (l<=0 || r>n) return false;
	int mid=l+r>>1;
	if (GetHash(l,mid-1)==GetHash(mid+1,r)){
		int id=c[mid]-'a';
		if ((Editpos<mid && occ[r][id]==occ[mid][id]) || (Editpos>mid && occ[mid-1][id]==occ[l-1][id])){
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	for (int i=1;i<=n;i++){
		ha[i]=ha[i-1]*201601163+c[i];
		for (int j=0;j<26;j++) occ[i][j]=occ[i-1][j];
		occ[i][c[i]-'a']++;
	}
	Graylen[0]=1;
	for (int i=1;i<26;i++){
		Graylen[i]=Graylen[i-1]*2+1; 
	}
	basepow[0]=1;
	for (int i=1;i<Maxn;i++){
		basepow[i]=basepow[i-1]*201601163;
	}
	LL ans=0;
	for (int i=1;i<=n;i++){
		isGray[i][0]=true;
		cntrbt[i]=1;
		ans++;
	}
	for (int i=1;i<20;i++){
		int len=(1<<(i+1))-1;
		for (int j=1;j<=n;j++){
			if (j+len-1>n) continue;
			int len0=len/2+1;
			if (isGray[j][i-1] && isGray[j+len0][i-1] && GetHash(j,j+len0-2)==GetHash(j+len0,j+len-1)){
				int ch=c[j+len0-1]-'a';
				if (occ[j+len-1][ch]-occ[j-1][ch]==1){
					isGray[j][i]=true;
					for (int k=j;k<=j+len-1;k++){
						cntrbt[k]+=1ll*len*len;
					}
					Center[j+len0-1].pb(mp(i,j));
					ans+=1ll*len*len;
					//cout<<len<<endl;
				}
			}
		}
	}
	//cout<<ans<<endl;
	LL res=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++){
			Editpos=i;
			delta=j-(c[i]-'a');
			LL nowans=ans-cntrbt[i];
			vector<pair<int,int> > V;
			V.pb(mp(i,0));
			for (int k=0;k<20;k++){
				int lo=i-Graylen[k],hi=i+Graylen[k];
				if (lo>0 && hi<=n){
					if (isGray[lo][k] && isGray[i+1][k]){
						if (GetHash(lo,i-1)==GetHash(i+1,hi)){
							if (occ[hi][j]-occ[i][j]==0){
								V.pb(mp(lo,k+1));
							}
						}
					}
				}
			}
			while (!V.empty()){
				pair<int,int> tmp=V.back();V.pop_back();
				int pos=tmp.first,len=Graylen[tmp.second],stage=tmp.second;
				nowans+=1ll*len*len;
				int nlen=len*2+1;
				if (check(pos,pos+nlen-1)){
					V.pb(mp(pos,stage+1));
				}
				if (check((pos+len-1)-(nlen)+1,pos+len-1)){
					V.pb(mp((pos+len-1)-(nlen)+1,stage+1));
				}
			}
			res=max(res,nowans);
			//cout<<i<<' '<<j<<' '<<nowans<<' '<<res<<endl;
		}
	}
	printf("%I64d\n",res);
	return 0;
}
/*
abababaaababababbabb
*/