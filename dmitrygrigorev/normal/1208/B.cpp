#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;
bool was[5000];
int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; i++) cin >> v[i];
	map<int, int> tet;
	for (int i=0; i < n; i++){
		if (tet.count(v[i])) continue;
		int S = tet.size();
		tet[v[i]] = S;
	} 
	for (int i=0; i < n; i++) v[i] = tet[v[i]];
	int ans = n;
	for (int pref=0; pref <= n; pref++){
		bool can = true;
		for (int i=0; i < n; i++) was[i] = false;
		for (int i=0; i < pref; i++){
			if (was[v[i]]) can = false;
			was[v[i]] = true;
		}
		if (!can) continue;
		int cur = n-1;
		while (cur >= 0 && !was[v[cur]]){
			was[v[cur]] = true;
			cur--;
		}
		//cout << pref << " " << cur << endl;
		int taken = n-cur-1;
		ans = min(ans, n-taken-pref);
	}
	cout << ans;
}