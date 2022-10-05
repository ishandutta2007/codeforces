#include <cstdio>
using namespace std;
typedef long long LL;

int T, n, m;
int ok(LL k){
	LL t = k * m, cnt = 1, tmp = 1;
	for (LL i = 1; i <= k; i++){
		tmp = tmp * (k - i + 1) / i;
		if (i <= t / tmp) t -= i * tmp, cnt += tmp;
		else { cnt += t / i; break; }
	}
	return cnt >= n;
}

inline LL calc(){
	LL l = 0, r = n;
	while (l < r){
		LL mid = (l + r) >> 1;
		if (ok(mid)) r = mid; else l = mid + 1;
	}
	return r;
}

int main(){
	scanf("%d", &T); 
	while (T--){
		scanf("%d%d", &n, &m);
		if (m + m > n) m = n / 2;
		printf("%I64d\n", calc());
	}
}