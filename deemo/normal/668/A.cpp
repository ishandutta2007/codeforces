#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 2;

int n, m, q, t[MAXN * MAXN], x[MAXN * MAXN];
int mat[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++){
		cin >> t[i];
		if (t[i] < 3){
			cin >> x[i], x[i]--;
			continue;
		}

		int a, b, c;	cin >> a >> b >> c, a--, b--;
		for (int j = i - 1; j >= 0; j--)
			if (t[j] < 3){
				if (t[j] == 1 && x[j] == a)	b = (b + 1) % m;
				if (t[j] == 2 && x[j] == b)	a = (a + 1) % n;
			}
		mat[a][b] = c;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cout << mat[i][j] << " ";
		cout << "\n";
	}
	return 0;
}