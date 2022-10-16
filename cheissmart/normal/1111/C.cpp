#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long int n, k, A, B;
vector<long long int> vec;

long long int rec(long long int l, long long int r) {
	long long i = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
	long long j = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
	j--;
	long long x = j - i + 1;
	if (l == r) {
		if (x != 0) {
			return B*x;
		} else if (x == 0) {
			return A;
		}
	}
	if (x == 0) {
		return A;
	} else {
		return min(B*x*(r-l+1), rec(l,(l+r)/2)+rec((l+r)/2+1,r));
	}
}

int main() {
	scanf("%lld %lld %lld %lld", &n ,&k, &A, &B);
	for (long long int i = 1; i <= k; i++) {
		long long int a; scanf("%lld", &a);
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	printf("%lld", rec(1, 1<<n));
	return 0;
}