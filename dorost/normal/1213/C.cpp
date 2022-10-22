/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int q;
	cin >> q;
	while (q--){
		int n, m;
		cin >> n >> m;
		if (m > n){
			cout << 0 << endl;
			continue;
		}
		int x = n / m, y = m % 10, ans = 0;
		int an[10] = {};
		set <int> st;
		for (int i = 0; i < 10; i++){
			st.insert ((y * i) % 10);
		}
//		cerr << st.size() << endl;
		for (int i = 1; i <= 10; i++){
			int num = (x - ((i))) + 1;
//			cout << "$" << num << ' ';
			num = (num + ((int)st.size() - 1)) / (int)st.size();
//			cout << "#" << num << endl;
			an[(y * i) % 10] = max(an[(y * i) % 10], max(0ll, num) * ((y * i) % 10ll));
//			cout << (y * i) % 10 << ' ' << max(0ll, num) << ' ' << an[(y * i) % 10] << endl;;
		}
		for (int i = 0; i < 10; i++)
			ans += an[i];//, cerr << an[i] << ' ';
		cout << ans << endl;
	}
}