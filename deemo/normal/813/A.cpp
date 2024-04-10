#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	int sm = 0;
	while (n--){
		int x;	cin >> x;
		sm += x;
	}

	int m;	cin >> m;
	int mn = 1e9;
	while (m--){
		int l, r; cin >> l >> r;
		if (r >= sm){
			mn = min(mn, max(l, sm));
		}
	}

	if (mn > 1e8)
		cout << "-1\n";
	else
		cout << mn << "\n";
	return 0;
}