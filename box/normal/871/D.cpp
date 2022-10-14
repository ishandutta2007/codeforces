// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;


#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)

using ll=long long;

int isc[10000007];
int primes[10000007]; int pc, c;
void sieve(int M) {
	isc[0]=isc[1]=1;
	iter(i, 2, M+1) {
		if(!isc[i]) {
			primes[pc++] = i;
			isc[i] = i;
		}
		if(!(i&1)&&(i<<1)<=M) {
			isc[i<<1] = 2;
			continue;
		}
		for(int j=0; j<pc; j+=5) {
			if(primes[j] * i > M+1) break;
			isc[primes[j] * i] = primes[j];
			if(!(i % primes[j]) || !primes[j+1] || (primes[j+1] * i > M+1)) break;
			isc[primes[j+1] * i] = primes[j+1];
			if(!(i % primes[j+1]) || !primes[j+2] || (primes[j+2] * i > M+1)) break;
			isc[primes[j+2] * i] = primes[j+2];
			if(!(i % primes[j+2]) || !primes[j+3] || (primes[j+3] * i > M+1)) break;
			isc[primes[j+3] * i] = primes[j+3];
			if(!(i % primes[j+3]) || !primes[j+4] || (primes[j+4] * i > M+1)) break;
			isc[primes[j+4] * i] = primes[j+4];
		}
	}
}
 
int mu[10000007];
 
void fm(int N) {
	rep1(i, N+1) {
		int j = i, cnt = 0, prev = 0;
		while(j != 1) {
			int v = isc[j];
			if(v == prev) {
				cnt = -1;
				break;
			} else {
				cnt++;
				prev = v;
			}
			j /= v;
		}
		if(cnt == -1) mu[i] = 0;
		else if(cnt%2 == 1) mu[i] = -1;
		else mu[i] = 1;
		mu[i] += mu[i-1];
	}
}

ll solve(ll n, ll m) {
	int r;
    ll ans=0;
	for(int l = 1; l <= min(n, m); l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		ans += (mu[r]-mu[l-1])*(n/l)*(m/l);
	}
	return ans;
}

int mpf[10000005];
int mpfc[10000007];
int n;
int tx[10000007];
ll cock(ll d, ll th){
    if(d!=1&&d*d<=n)return (th-1)*th;
    rep1(i,th)tx[i-1]=(mpf[i*d]);
    sort(tx,tx+th);
    int bb=0;
    rep(i,th)if(2*tx[i]<=n)bb++;
    ll ans=0;
    rep1(i,th){
        if(1ll*mpf[i*d]*mpf[i*d]<=n)ans-=2;
        else if(2*mpf[i*d]<=n)ans-=3;
    }
    int cnt=th;
    rep(i,th){
        int mxok=n/tx[i];
        while(cnt&&tx[cnt-1]>mxok)cnt--;
        ans+=2*cnt;
        if(2*tx[i]<=n&&bb>cnt)ans+=3*(bb-cnt);
    }
    //cout<<d<<' '<<th<<' '<<ans<<endl;
    return ans/2;
}
ll sv2(ll n,ll m){
    int r;
    ll ans=0;
	for(int l = 1; l <= min(n, m); l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		ans += (mu[r]-mu[l-1])*cock(l,n/l);
	}
	return ans;
}
signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    cin >> n;
    sieve(n);fm(n);
    rep1(i,n)mpf[i]=10000008;
    iter(i,2,n+1){
        if(mpf[i]!= 10000008)continue;
        for(int j=i;j<=n;j+=i)mpf[j]=min(mpf[j],i);
    }
    ll copr=solve(n,n);
    ll ncopr=1ll*n*n-copr;
    ll ncoprUneq=ncopr-(n-1);
    ll ncoprigjUneq=ncoprUneq/2;
    ll ans=ncoprigjUneq;
    cout<<ans+sv2(n,n)<<endl;
    // 50 1413
    // cout<<ans<<' '<<ans2<<endl;
}