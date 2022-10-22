#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 3;

int n, m, a[MAXN][MAXN], b[MAXN][MAXN];

int get(int x, bool type = 0){
	int ret = x;
	if (type)
		for (int i = 0; i < x; i++)
			cout << "row 1\n";
	memcpy(b, a, sizeof(a));
	for (int j = 0; j < m; j++){
		b[0][j] -= x;
		if (b[0][j] < 0)
			return (int)2e9;
	}

	for (int j = 0; j < m; j++){
		ret += b[0][j];
		if (type)
			for (int w = 0; w < b[0][j]; w++)
				cout << "col " << j+1 << "\n";
		for (int i = n-1; ~i; i--){
			b[i][j] -= b[0][j];
			if (b[i][j] < 0)
				return (int)2e9;
		}
	}

	for (int i = 1; i < n; i++){
		ret += b[i][0];
		if (type)
			for (int w = 0; w < b[i][0]; w++)
				cout << "row " << i+1 << "\n";
		for (int j = m-1; ~j; j--){
			b[i][j] -= b[i][0];
			if (b[i][j] < 0)
				return (int)2e9;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (b[i][j]) return (int)2e9;

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	cin >> a[i][j];

	pii ans(2e9, -1);
	for (int i = 0; i <= a[0][0]; i++)
		ans = min(ans, {get(i), i});
	if (ans.F > 1e9){
		cout << "-1\n";
		return 0;
	}
	cout << ans.F << "\n";
	get(ans.S, 1);
	return 0;
}