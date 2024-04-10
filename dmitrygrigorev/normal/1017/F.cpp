#include <bits/stdc++.h>
using namespace std;
const int SQRT_MAXN = 50000; //     N
const int S = 10000;
bool nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt;
int n, A, B, C, D;
int get(int hr){
    return A*hr*hr*hr + B*hr*hr + C*hr + D;
}
int check(int e){
    int ans = 0;
    long long i = e, cf=1;
	    while (true){
    	    if (i > n) break;
    	    int hr = 0;
    	    long long G = i*e;
    	    int pol = (long long)n / G;
    	    hr += pol * (e-1);
    	    int ost = (long long)n % G;
    	    hr += ost / i;
    	    ans += cf*get(e)*hr;
    	    //cout << i << " " << hr << " " << ans << endl;
    	    i*=e;
    	    cf++;
	    }
    return ans;
    	   
}
int main() {
    int ans = 0;
	cin >> n >> A >> B >> C >> D;
	int nsqrt = (int) sqrt (n + .0);
	for (int i=2; i<=nsqrt; ++i)
		if (!nprime[i]) {
			primes[cnt++] = i;
			if (i * 1ll * i <= nsqrt)
				for (int j=i*i; j<=nsqrt; j+=i)
					nprime[j] = true;
		}
 
	int result = 0;
	for (int k=0, maxk=n/S; k<=maxk; ++k) {
		memset (bl, 0, sizeof bl);
		int start = k * S;
		for (int i=0; i<cnt; ++i) {
			int start_idx = (start + primes[i] - 1) / primes[i];
			int j = max(start_idx,2) * primes[i] - start;
			for (; j<S; j+=primes[i])
				bl[j] = true;
		}
		if (k == 0)
			bl[0] = bl[1] = true;
		for (int i=0; i<S && start+i<=n; ++i)
			if (!bl[i])
				ans += check(start+i);
	}
	long long hh = ans;
	if (ans < 0) hh += (1LL<<32);
	cout << hh;
 
}