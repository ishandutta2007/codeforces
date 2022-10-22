#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fast ios::sync_with_stdio(false), cout.tie(), cin.tie();
#define sz(s) int(s.size())

int main(){
	int t;
	cin >> t;
	while (t--){
		ll n, d;
		cin >> n >> d;
		ll s = n / 2;
		if ((s + (d + s) / (s + 1)) <= n){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}