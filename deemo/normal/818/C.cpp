#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, w, h, x[MAXN], y[MAXN], xx[MAXN], yy[MAXN], sec[4][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> w >> h;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> xx[i] >> yy[i];
		sec[0][i] = min(x[i], xx[i]);
		sec[1][i] = max(x[i], xx[i]);
		sec[2][i] = min(y[i], yy[i]);
		sec[3][i] = max(y[i], yy[i]);
	}
	for (int w = 0; w < 4; w++)
		sort(sec[w], sec[w]+n);

	int l, r, u, d; cin >> l >> r >> d >> u;
	
	for (int i = 0; i < n; i++){
		int temp = lower_bound(sec[0], sec[0]+n, max(x[i], xx[i]))-sec[0];
		if (min(x[i], xx[i]) != max(x[i], xx[i])) temp--;
		if (temp != l) continue;
		temp = n-(upper_bound(sec[1], sec[1]+n, min(x[i], xx[i]))-sec[1]);
		if (min(x[i], xx[i]) != max(x[i], xx[i])) temp--;
		if (temp != r) continue;
		temp = lower_bound(sec[2], sec[2]+n, max(y[i], yy[i]))-sec[2];
		if (min(y[i], yy[i]) != max(y[i], yy[i])) temp--;
		if (temp != d) continue;
		temp = n-(upper_bound(sec[3], sec[3]+n, min(y[i], yy[i]))-sec[3]);
		if (min(y[i], yy[i]) != max(y[i], yy[i])) temp--;
		if (temp != u) continue;

		cout << i+1 << endl;
		return 0;
	}
	
	cout << "-1\n";
	return 0;
}