#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; ++i) cin >> v[i];

	int ans = 0;

	for (int it=0; it < 2; ++it){
	
		vector<int> st;
		for (int i=0; i < n; ++i) {
			while (st.size() && st.back() < v[i]) {
				ans = max(ans, st.back() ^ v[i]);
				st.pop_back();
			}
			st.push_back(v[i]);
		}
		reverse(v.begin(), v.end());
	}

	cout << ans;

}