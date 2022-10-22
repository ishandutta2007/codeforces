/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, x;
		cin >> n;
		n *= 2;
		set <int> st;
		for (int i = 0; i < n; i++){
			cin >> x;
			if (st.count (x))
				continue;
			cout << x << ' ';
			st.insert (x);
		}
		cout << endl;
	}
}