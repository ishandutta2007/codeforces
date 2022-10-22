#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
bool comp[2750132];
int cnt[2750132];
bool prime (int n) {
	for (int i = 2; i * i <= n; i++) if (n%i==0) return 0;
	return 1;
}
int big (int n) {
	for (int i = 2; i * i <= n; i++) if (n%i==0) return n/i;
	return 0;
}
int main() {
	vector<int> primes = {0};
	for (int i = 2; i <= 2750131; i++) if (!comp[i]){
		primes.push_back(i);
		if ((ll)i*i <= 2750131) for (int j = i*i; j <= 2750131; j += i) comp[j] = 1;
	}
	int n;
	scanf ("%d",&n);
	vector<int> a(2*n+1);
	for (int i = 1; i <= (n << 1); i++) scanf ("%d",&a[i]), ++cnt[a[i]];
	sort(a.begin()+1,a.end());
	vector<int> ret;
	for (int i = (n << 1); i >= 1; i--) {
		if (cnt[a[i]] && !prime(a[i])) {
			ret.push_back(a[i]);
			cnt[a[i]]--;
			cnt[big(a[i])]--;
		}
	}
	for (int i = 1; i <= (n << 1); i++) {
		if (cnt[a[i]] && prime(a[i])) {
			--cnt[a[i]];
			--cnt[primes[a[i]]];
			ret.push_back(a[i]);
		}
	}
	for (int i : ret) printf ("%d ",i);
	printf ("\n");
    return 0;
}