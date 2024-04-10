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
	ll l,r,x,y,k;
	cin >>l>>r>>x>>y>>k;
	for(ll i = x; i <= y; ++i) {
		if(l <= i*k && i*k <= r) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}