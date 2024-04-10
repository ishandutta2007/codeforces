/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int mx = 0;
		for (char a = '0'; a <= '9'; a++){
			for (char b = '0'; b <= '9'; b++){
				char f = a;
				int num = 0;
				for (int i = 0; i < n; i++) {
					if (s[i] == f) {
						if (f == a) 
							f = b;
						else
							f = a;
						num++;
					}
				}
				if (num % 2 && a != b)
					num--;
				mx = max(mx, num);
			}
		}
		cout << n - mx << endl;
	}
}