#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> A, B;
bool T[100005];

int main() {
	ll a, b; scanf("%lld%lld", &a, &b);
	ll x = a + b;
	ll s = 0, n = 1;
	for(; s <= x; n++) s += n;
	n -= 2;
	for(int i = n; i >= 1; i--) {
		if(i > a) continue;
		A.push_back(i); a -= i;
		T[i] = true;
	}
	for(int i = n; i >= 1; i--) {
		if(T[i]) continue;
		B.push_back(i);
	}
	printf("%d\n", A.size());
	for(int i : A) printf("%d ", i); puts("");
	printf("%d\n", B.size());
	for(int i : B) printf("%d ", i); puts("");
	return 0;
}