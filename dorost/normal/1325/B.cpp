#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		set <int> st;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			st.insert (x);
		}
		int ans = 0;
		for (auto x : st)
			ans++;
		cout << ans << endl;
	}		
}