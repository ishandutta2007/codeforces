#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, x[MAXN], y[MAXN], a[MAXN], b[MAXN];
map<pii, bool> mp;

bool check(int xx, int yy){
	for (int i = 0; i < n; i++)
		if (!mp.count({xx-x[i], yy-y[i]})) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i], mp[{a[i], b[i]}] = true;

	for (int j = 0; j < n; j++)
		if (check(x[0] + a[j], y[0] + b[j])){
			cout << x[0]+a[j] << " " << y[0] + b[j] << "\n";
			return 0;
		}
	return 0;
}