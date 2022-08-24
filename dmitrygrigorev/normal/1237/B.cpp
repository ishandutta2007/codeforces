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
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i=0; i < n; ++i){
		cin >> a[i];
		a[i]--;
	}
	for (int i=0; i < n; ++i){
		cin >> b[i];
		b[i]--;
	}

	vector<int> pos(n);
	for (int i=0;i<n;++i) pos[b[i]] = i;
	int ans=0;
	int mx = -1;
	for (int i=0; i < n; ++i){
		if (pos[a[i]] < mx) ans++;
		mx = max(mx, pos[a[i]]);
	}
	cout << ans;

}