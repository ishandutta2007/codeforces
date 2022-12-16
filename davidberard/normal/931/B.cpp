#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int h = sizeof(int)*8 - __builtin_clz(n-1);
	int nn = 1 << h;
	int i = 0;
	if(a > b)
		swap(a, b);
	a+=nn, b+=nn;
	--a; --b;
	for(;a < b;++i, a/=2, b/=2) {
	}
	if(i == h) cout << "Final!" << endl;
	else cout << i << endl;
	return 0;
}