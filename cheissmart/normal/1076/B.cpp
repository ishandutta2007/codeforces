#include <bits/stdc++.h>

using namespace std;

bool isprime(long long n) {
	if(n < 2) return false;
	for(long long i=2;i*i<=n;i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}

int isnp[100005];

int main()
{
	long long n, ans = 0;
	cin >> n;
	for(long long i=2;i*i<=100003;i++){
		if(isnp[i]) continue;
		for(long long j=i*i;j<=100003;j+=i) {
			isnp[j] = 1;
		}
	}
	
	while(n) {
		if(isprime(n)) {
			n -= n;
			ans++;
		} else {
			if(n%2==0) {
				ans += n/2;
				break;
			}
			for(long long i=2;i*i<=n;i++) {
				if(isnp[i]) continue;
				if(n % i == 0) {
					n -= i;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}