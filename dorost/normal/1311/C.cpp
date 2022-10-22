#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

signed main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	signed t = 1;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		int p[m];
		int as[26] = {};
		for (int i = 0; i < m; i++){
			cin >> p[i];
		}
		sort(p, p + m);
		int h = 0;
		int x = m;
		for (int i = 0; i < n; i++){
			as[s[i] - 'a'] += x  + 1;
			while (i + 1 >= p[h]){
				h++;
				x--;
			}
		}
		for (int i = 0; i < 26; i++){
			cout << as[i] << ' ';
		}
		cout << endl;
	}	
}