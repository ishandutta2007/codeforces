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
const int Maxn=13;
int w[Maxn];
int c[4444][4444];
int W[4444];
int n,m,q;
int S[4444];
char ch[Maxn];
vector<pair<int,int> > Q[4444];
int ans[500000+5];
int cnt[105];
int main(){
	n=read();m=read();q=read();
	for (int i=0;i<n;i++){
		w[i]=read();
	}
	for (int i=0;i<(1<<n);i++){
		for (int j=0;j<n;j++){
			if (i>>j&1) W[i]+=w[j];
		}
	}
	for (int i=0;i<m;i++){
		scanf("%s",ch);
		int v=0;
		for (int j=0;j<n;j++){
			v+=(1<<j)*(ch[j]-'0');
		}
		S[v]++;
	}
	int al=(1<<n)-1;
	for (int i=0;i<(1<<n);i++){
		for (int j=0;j<(1<<n);j++){
			c[i][j]=W[al^i^j];
		}
	}
	for (int i=0;i<q;i++){
		scanf("%s",ch);
		int v=0;
		for (int j=0;j<n;j++){
			v+=(1<<j)*(ch[j]-'0');
		}
		int k;
		k=read();
		Q[v].pb(mp(k,i));
	}
	for (int i=0;i<(1<<n);i++){
		memset(cnt,0,sizeof(cnt));
		for (int j=0;j<(1<<n);j++){
			if (c[i][j]<=100)cnt[c[i][j]]+=S[j];
		}
		for (int j=1;j<=100;j++){
			cnt[j]+=cnt[j-1];
		}
		for (int j=0;j<Q[i].size();j++){
			ans[Q[i][j].second]=cnt[Q[i][j].first];
		}
	}
	for (int i=0;i<q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}