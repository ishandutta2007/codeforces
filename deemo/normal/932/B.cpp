#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;
const int C = 10;

int g[MAXN], pt[MAXN][C];

int f(int x){
	int ret = 1;
	while (x){
		if (x % 10)
			ret *= x%10;
		x /= 10;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < MAXN; i++){
		if (i < 10)
			g[i] = i;
		else
			g[i] = g[f(i)];
	}
	for (int i = 1; i < MAXN; i++){
		for (int j = 0; j < C; j++)
			pt[i][j] = pt[i-1][j];
		pt[i][g[i]]++;
	}
	int q; cin >> q;
	while (q--){
		int l, r, c; cin >> l >> r >> c, l--;
		cout << pt[r][c] - pt[l][c] << "\n";
	}
	return 0;
}