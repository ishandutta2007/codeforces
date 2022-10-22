#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int MAXN = 1e5 + 10;

int n, p, v[MAXN], rem[MAXN];

bool ok(ld mid){
	ld sm = 0;
	for (int i = 0; i < n; i++)
		sm += max(ld(0), mid*v[i]-rem[i]);
	if (sm > mid*p) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p;
	ll sm = 0;
	for (int i = 0; i < n; i++){
		cin >> v[i] >> rem[i];
		sm += v[i];
	}
	if (sm <= p){
		cout << "-1\n";
		return 0;
	}

	ld lo = 0, hi = 2e10;
	for (int i = 0; i < 150; i++){
		ld mid = (hi+lo)/2.;
		if (ok(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << fixed << setprecision(9);
	cout << lo << "\n";
	return 0;
}