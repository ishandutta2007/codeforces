#include <bits/stdc++.h>

using namespace std;

int Link[500000];
int unioned;

int Find(int x) {
	if(Link[x]) 
		return Link[x] = Find(Link[x]);
	return x;
}
void Union(int a, int b) {
	a = Find(a); b = Find(b);
	Link[a] = b;
}


int ans = 0;
int n;

void TryUnion(int a, int b, int d) {
	if(a <= 0 || a > n || b <= 0 || b > n) return;

	int now = (a + b) % (n + 1);
	assert(now == d);

	a = Find(a); b = Find(b);
	if(a == b) return;

	Union(a, b);
	ans += now;
	++unioned;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	unioned = 0;
	for(int d = 0; ; ++d) {
		for(int i = 1; i <= n; ++i) {
			TryUnion(i, d - i, d);
			TryUnion(i, d + n + 1 - i, d);
			TryUnion(i, d + 2 * n + 2 - i, d);
		}

		if(unioned == n - 1)
			break;
	}
	cout << ans << endl;
	
	return 0;
}