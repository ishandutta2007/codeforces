#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	set<string> S;
	int n;
	cin >> n;
	while(n--) {
		string a;
		cin >> a;
		if (S.count(a) == 0) {
			cout << "NO\n";
			S.insert(a);
		}
		else cout << "YES\n";
	}
}