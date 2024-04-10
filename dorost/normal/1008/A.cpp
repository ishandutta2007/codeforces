#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	string s;
	cin >> s;
	int n = s.size();
	set <char> st = {'e','a', 'o', 'u', 'i'};
	bool f = true;
	for (int i = 0; i < n - 1; i++){
		if (!st.count(s[i]) && s[i] != 'n'){
			if (!st.count(s[i + 1]))
				f = false;
		}
	}
	if (!st.count(s[n - 1]) && s[n - 1] != 'n'){
		f = false;
	}
	cout << (f ? "YES" : "NO");
}