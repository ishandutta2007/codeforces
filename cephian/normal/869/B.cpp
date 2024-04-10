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
	ll a,b;
	cin >> a >> b;
	ll ans = 1;
	for(ll i = a+1; ans != 0 && i <= b; ++i)
		ans = ans * (i % 10) % 10;
	cout << ans << "\n";
}