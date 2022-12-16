#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& x : a) cin >> x;
	cout << n+1 << "\n";
	int xtra = 100*n;
	cout << "1 " << n << " " << xtra << endl;
	for(int i=1;i<=n;++i)
	{
		cout << "2 " << i << " " << a[i-1]+xtra-i << "\n";
	}

	return 0;
}