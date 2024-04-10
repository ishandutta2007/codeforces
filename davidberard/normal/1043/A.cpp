#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> a(N);
	int mx = 0;
	int sm = 0;
	for(auto& x: a) {
		cin >> x;
		mx = max(mx, x);
		sm += x;
	}

	int ans = max((2*sm+N)/N, mx);
	cout << ans << endl;
	/*
	int bot = mx;
	int top = 1000;
	while(top-bot > 1)
	{
		
	} */
	return 0;
}