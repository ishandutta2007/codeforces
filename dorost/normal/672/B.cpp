/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	string s;
	cin >> n >> s;
	if (n > 26)
		return cout << -1, 0;
	set <char> st;
	for (int i = 0; i < n; i++){
		st.insert (s[i]);
	}
	cout << n - st.size();
}