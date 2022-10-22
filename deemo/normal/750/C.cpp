#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e9;

int n;
ll sm = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll lo = -INF, hi = INF;
	for (int i = 0; i < n; i++){
		ll a, b;	cin >> a >> b;
		if (b == 1){
			lo = max(lo, 1900ll-sm);
		}
		else{
			hi = min(hi, 1899ll-sm);
		}
		sm += a;
	}

	if (hi < lo)
		cout << "Impossible\n";
	else if (hi==INF)
		cout << "Infinity\n";
	else
		cout << hi+sm << "\n";
	return 0;
}