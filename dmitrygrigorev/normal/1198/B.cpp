#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int q;
	cin >> q;
	vector<int> payment;
	vector<pair<int, int> > latest(n);
	for (int i=0; i < n; i++) latest[i] = {v[i], -1};
	for (int i=0; i < q; i++){
		int tp;
		cin >> tp;
		if (tp==1){
			payment.push_back(-1);
			int p, x;
			cin >> p >> x;
			latest[p-1] = {x, i};
		}
		else{
			int x;
			cin >> x;
			payment.push_back(x);
		}
	}
	for (int i=q-2; i >= 0; i--) payment[i] = max(payment[i+1], payment[i]);
	for (int i=0; i < n; i++){
		if (latest[i].second == q-1){
			cout << latest[i].first << " ";
		}
		else cout << max(latest[i].first, payment[latest[i].second+1]) << " ";
	}
}