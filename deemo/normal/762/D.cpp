#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n;
ll d[3][MAXN], val[3][MAXN];

void smax(ll &a, ll b){a = max(a, b);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(d, -10, sizeof(d));
	cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)	cin >> val[i][j];

	d[0][0] = 0;
	for (int i = 0; i < n; i++){
		smax(d[0][i+1], d[0][i]+val[0][i]);
		smax(d[2][i+2], d[0][i]+val[0][i]+val[1][i]+val[2][i]+val[0][i+1]+val[1][i+1]+val[2][i+1]);
		smax(d[1][i+1], d[0][i]+val[0][i]+val[1][i]);
		smax(d[2][i+1], d[0][i]+val[0][i]+val[1][i]+val[2][i]);

		smax(d[0][i+1], d[1][i]+val[1][i]+val[0][i]);
		smax(d[2][i+1], d[1][i]+val[1][i]+val[2][i]);
		smax(d[1][i+1], d[1][i]+val[1][i]);

		smax(d[2][i+1], d[2][i]+val[2][i]);
		smax(d[0][i+2], d[2][i]+val[0][i]+val[1][i]+val[2][i]+val[0][i+1]+val[1][i+1]+val[2][i+1]);
		smax(d[1][i+1], d[2][i]+val[2][i]+val[1][i]);
		smax(d[0][i+1], d[2][i]+val[2][i]+val[1][i]+val[0][i]);
	}

	cout << d[2][n] << "\n";
	return 0;
}