#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
typedef long long ll;
typedef long double ld;

int r, s, p;
ld a[3][101][101][101];

void solve(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	memset(a, 0, sizeof(a));
	cin>>r>>s>>p;
	FOR(i, r + 1) FOR(j, s + 1) FOR(k, p + 1){
		if (i == 0 && j == 0 && k == 0) continue;
		if (i == 0 && j == 0) {a[0][i][j][k] = 0; a[1][i][j][k] = 0; a[2][i][j][k] = 1; continue;}
		if (j == 0 && k == 0) {a[0][i][j][k] = 1; a[1][i][j][k] = 0; a[2][i][j][k] = 0; continue;}
		if (k == 0 && i == 0) {a[0][i][j][k] = 0; a[1][i][j][k] = 1; a[2][i][j][k] = 0; continue;}
		FOR(l, 3){
			if (i > 0 && j > 0) a[l][i][j][k] += a[l][i][j - 1][k] * i * j / (i * j + j * k + k * i);
			if (j > 0 && k > 0) a[l][i][j][k] += a[l][i][j][k - 1] * j * k / (i * j + j * k + k * i);
			if (k > 0 && i > 0) a[l][i][j][k] += a[l][i - 1][j][k] * k * i / (i * j + j * k + k * i);
		}
	}
	printf("%0.12f %0.12f %0.12f", a[0][r][s][p], a[1][r][s][p], a[2][r][s][p]);
}

int main(){
	solve();
	return 0;
}