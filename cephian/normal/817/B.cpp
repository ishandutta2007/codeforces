#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map<ll,ll> f;
const int N = 1e5+5; 
ll a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		++f[a[i]];
	}
	sort(a,a+n);

	if(a[0]==a[2]) {
		ll k = f[a[0]];
		cout << k*(k-1)*(k-2)/6 << "\n";
	} else if(a[1]==a[2]) {
		ll k = f[a[1]];
		cout << k*(k-1)/2 << "\n";
	} else {
		ll k = f[a[2]];
		cout << k << "\n";
	}

	return 0;
}