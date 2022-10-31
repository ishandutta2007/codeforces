#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 2e5+5;
ll x[N], t[N];
ll chose[N];
int ans[N];

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n+m; ++i) cin >> x[i];
	for(int i = 0; i < n+m; ++i) cin >> t[i];

	int last = -1;
	for(int i = 0; i < n+m; ++i) {
		if(t[i] == 1)
			last = i;
		chose[i] = last;
	}

	last = -1;
	for(int i = n+m-1; i >= 0; --i) {
		if(t[i] == 1) last = i;
		if(chose[i] == -1 || (last != -1 && x[i] - x[chose[i]] > x[last] - x[i]))
			chose[i] = last;
		if(t[i] == 0)
			++ans[chose[i]];

	}

	for(int i = 0; i < n+m; ++i) {
		if(t[i]) cout << ans[i] << " ";
	}
	cout << "\n";
	
}