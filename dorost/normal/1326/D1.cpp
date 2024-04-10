#include <bits/stdc++.h>

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size(), h = n / 2 - 1;
		string ans, t;
		if (n == 1){
			cout << s << endl;
			continue;
		}
		for (int i = 0; i < n / 2; i++){
			if (s[i] != s[n - 1 - i]){
				h = i - 1;
				break;
			}
			t += s[i];
		}
		///cout << h << endl;
		string f;
		int mx = 0;
		string b, g, k;
		for (int i = h + 1; i < n - h - 1; i++)
			f += s[i];
		//cout << f << endl;
		for (int i = 0; i < f.size(); i++){
			g += f[i];
			string l = g;
			reverse(l.begin(), l.end());
			if (l == g){
				if (g.size() > mx){
					mx = g.size();
					b = g;
				}
			}
		}
		for (int i = f.size() - 1; i >= 0; i--){
			k += f[i];
			string l = k;
			reverse(l.begin(), l.end());
			//cout << "#" << k << ' ' << l << ' ' << k.size() << endl;
			if (l == k){
				if (k.size() > mx){
					mx = k.size();
					b = k;
				}
			}
		}
		cout << t << b;
		reverse(t.begin(), t.end());
		cout << t << endl;
	}
}