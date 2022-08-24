#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
vector<int> phis;
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (k==1){
		cout << 3 << endl;
		return 0;
	}
	if (k==2){
		cout << 6 << endl;
		return 0;
	}
	for (int i=0; i <= n; i++) phis.push_back(i);
	for (int i=2; i <= n; i++){
		if (phis[i] != i) continue;
		for (int j=i+i; j <= n; j+=i){
			phis[j] -= (phis[j] / i);
		}
		phis[i]--;
	}
	vector<int> eul;
	for (int i=5; i <= n; i++){
		eul.push_back(phis[i]);
	}
	sort(eul.begin(), eul.end());
	int ans = 6;
	for (int i=0; i < k-2; i++) ans += eul[i];
	cout << ans;
}