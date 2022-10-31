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
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
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
const int Maxn=2e5+5;
int n,m,k;
vector<int> G[Maxn],Gr[Maxn];
int r[Maxn];
int lo[Maxn],hi[Maxn];
int ord[Maxn];
vector<pair<int,int> > R[Maxn];
int ans[Maxn];
bool hav[Maxn];
int deg[Maxn];
int main(){
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++){
		r[i]=read();
		if (r[i]) lo[i]=hi[i]=r[i],hav[r[i]]=true;
		else{
			lo[i]=1;
			hi[i]=k;
		}
	}
	for (int i=0;i<m;i++){
		int u,v;
		u=read();v=read();G[u].pb(v);
		Gr[v].pb(u);
		deg[v]++;
	}
	int co=0;
	vector<int> V;
	for (int i=1;i<=n;i++){
		if (!deg[i]){
			V.pb(i);
		}
	}
	while (!V.empty()){
		int x=V.back();V.pop_back();
		ord[++co]=x;
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i];
			deg[v]--;
			if (!deg[v]){
				V.pb(v);
			}
		}
	}
	if (co!=n){
		puts("-1");
		return 0;
	}
	//cerr<<123<<endl;
	for (int i=n;i>=1;i--){
		int v=ord[i];
		for (int j=0;j<G[v].size();j++){
			lo[v]=max(lo[v],lo[G[v][j]]+1);
		}
	}
	for (int i=1;i<=n;i++){
		int v=ord[i];
		for (int j=0;j<Gr[v].size();j++){
			hi[v]=min(hi[v],hi[Gr[v][j]]-1);
		}
	}
	//cerr<<213<<endl;
	for (int i=1;i<=n;i++){
	//	cout<<i<<' '<<lo[i]<<' '<<hi[i]<<endl;
		if (lo[i]>hi[i]){
			puts("-1");return 0;
		}
		R[lo[i]].pb(mp(-hi[i],i));
	}
	priority_queue<pair<int,int> > Q;
	//cerr<<123<<endl;
	for (int i=1;i<=k;i++){
		for (int j=0;j<R[i].size();j++){
			Q.push(R[i][j]);
		}
		if (hav[i]){
			//cout<<i<<endl;
			while (!Q.empty() && Q.top().first==-i){
				ans[Q.top().second]=i;
				//cout<<i<<' '<<Q.top().second<<endl;
				Q.pop(); 
			}
		}
		else{
			if (Q.empty()){
				puts("-1");
				return 0;
			}
			pii tmp=Q.top();
			ans[tmp.second]=i;
			//cout<<tmp.second<<' '<<i<<endl;
			Q.pop();
			while (!Q.empty() && Q.top().first==-i){
				ans[Q.top().second]=i;
				Q.pop(); 
			}
		}
	}
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}