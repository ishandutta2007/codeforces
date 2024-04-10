#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(s) (int)s.size()
#define fast  ios_base::sync_with_stdio(false), cin.tie(), cout.tie()

int main(){
	ll n, m;
	cin >> n >> m;
	string s[n], t[m];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < m; i++){
		cin >> t[i];
	}
	ll q;
	cin >> q;
	while(q--){
		ll y;
		cin >> y;
		cout << s[(y - 1) % n] << t[(y - 1) % m] << endl;
	}
}