#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const int N = 2005;
ll x[N], y[N];

void gone(vector<int>& v, int i) {
	swap(v[i], v.back());
	v.resize(v.size()-1);
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	string s;
	cin >> s;
	vector<int> ans;
	vector<int> remaining;
	for(int i = 0; i < n; ++i)
		remaining.push_back(i);

	// start with leftmost point
	int cur = 0;
	for(int i = 1; i < n; ++i) {
		if(x[i] < x[cur])
			cur = i;
	}

	ans.push_back(cur);
	gone(remaining, cur);

	for(char c : s) {
		// sort from left --> right
		sort(remaining.begin(), remaining.end(),
				[cur](int i, int j) -> bool {
					const ll ux = x[i] - x[cur];
					const ll uy = y[i] - y[cur];
					const ll vx = x[j] - x[i];
					const ll vy = y[j] - y[i];
					return ux*vy - uy*vx < 0;
				}
		);
		int nxt;
		if(c == 'L') {
			// choose rightmost
			nxt = remaining.back();
			gone(remaining, remaining.size()-1);
		} else {
			// choose leftmost
			nxt = remaining[0];
			gone(remaining, 0);
			
		}
		ans.push_back(nxt);
		cur = nxt;
	}
	ans.push_back(remaining[0]);
	for(int x : ans)
		cout << x+1 << ' ';
	cout << '\n';
}