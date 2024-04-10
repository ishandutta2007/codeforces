#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	map <pair<pair <int, int>, char>, bool> mp;
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		mp.clear();
		int x = 0, y = 0, ans = 0;
		for (int i = 0; i < (int)s.size(); i++){
			char c = s[i], ch;
			int a = x, b = y;
			if (c == 'S')
				y++, ch = 'N';
			else if (c == 'N')
				y--, ch = 'S';
			else if (c == 'W')
				x++, ch = 'E';
			else if (c == 'E')
				x--, ch = 'W';
			mp[{{a, b}, ch}] = true;
			if (mp[{{x, y}, c}]){
				ans ++;
			}else{
				ans += 5;
				mp[{{x, y}, c}] = true;
			}
//			cout << x << ' ' << y << endl;
		}
		cout << ans << endl;
	}
}