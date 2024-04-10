/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, q;
	cin >> n >> q;
	set <pair <int, int>> st;
	int ans = 0;
	while (q--){
		int r, c;
		cin >> r >> c;
		r --;
		c --;
		if (!st.count ({r, c})){
			st.insert ({r, c});
			for (int i = max (0, c - 1); i <= min (n, c + 1); i ++){
				if (st.count ({1 - r, i}))
					ans ++;
			}
		}else{
			st.erase ({r, c});
			for (int i = max (0, c - 1); i <= min (n, c + 1); i ++){
				if (st.count ({1 - r, i}))
					ans --;
			}
		}
		if (ans != 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}