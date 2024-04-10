// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=1e5+5,mod=998244353;
int n,m,mu[N],l[N],r[N],L[N],R[N],ans,prime[N],cnt,dp[N],f[N];
bool tag[N];

inline void pre(){
	mu[1]=tag[1]=1;
	for(re i=2;i<N;++i){
		if(!tag[i]) prime[++cnt]=i,mu[i]=-1;
		for(re j=1;j<=cnt&&prime[j]*i<N;++j){
			tag[i*prime[j]]=1;
			if(i%prime[j]==0) break;
			mu[i*prime[j]]=-mu[i];
		}
	}
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(m);pre();
	for(re i=1;i<=n;++i) rd(L[i]),rd(R[i]);
	for(re d=1;d<=m;++d)
		if(mu[d]){
			for(re i=1;i<=n;++i) l[i]=(L[i]+d-1)/d,r[i]=R[i]/d;
			int sum=m/d;
			for(re i=0;i<=sum;++i) dp[i]=1;
			for(re i=1;i<=n;++i){
				for(re j=1;j<=sum;++j) f[j]=0;
				for(re j=l[i];j<=sum;++j){
					f[j]=dp[j-l[i]];
					if(j-r[i]-1>=0) f[j]=(f[j]-dp[j-r[i]-1]+mod)%mod;
				}
				dp[0]=0;
				for(re j=1;j<=sum;++j) dp[j]=(dp[j-1]+f[j])%mod;
			}
			ans=(ans+dp[sum]*mu[d])%mod;ans=(ans+mod)%mod;
		}
	wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //