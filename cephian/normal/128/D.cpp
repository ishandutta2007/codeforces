#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map<int,int> m;
int n;

void rem(int a) {
	--m[a];
	if(m[a] == 0)
		m.erase(a);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int mn=0x7fffffff,mx=0;
	while(n--) {
		int a;
		cin >> a;
		++m[a];
		mn = min(a,mn);
		mx = max(a,mx);
	}
	for(int a = mn; a < mx; ++a) {
		if(!m.count(a)) {
			cout << "NO\n";
			return 0;
		}
		rem(a);
	}
	int a = mn;
	int lst = mn;
	while(!m.empty()) {
		if(m.count(a-1)) {
			rem(a-1);
			--a;
		} else if(m.count(a+1)) {
			rem(a+1);
			++a;
		} else {
			cout << "NO\n";
			return 0;
		}
	}
	if(a == mx) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}