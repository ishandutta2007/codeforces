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
	int n, k;
	string s;
	set <char> st;
	cin >> n >> k >> s;
	for (int i = 0; i < k; i++){
		char c;
		cin >> c;
		st.insert (c);
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		int x = i;
		while (st.count(s[i])){
			i ++;
			if (i >= n)
				break;
		}
		int d = i - x;
		ans += (d * (d + 1)) / 2;
	}
	cout << ans << endl;
}