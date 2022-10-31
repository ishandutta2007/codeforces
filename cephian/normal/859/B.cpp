#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;



int main() {
	fio;	
	ll s;
	cin >> s;
	ll ans = 1LL << 60;
	for(ll l = 1; l <= s; ++l) {
		ll h = (s+(l-1))/l;
		ans = min(ans,2*(l+h));
	}
	cout << ans << "\n";
}