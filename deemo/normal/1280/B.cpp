#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 70;

int n, m;
string s[MAXN];
int cnt[2][MAXN];

bool check(){
	for (int i = 0; i < n; i++)
		if (cnt[0][i] == m)
			return true;
	for (int j = 0; j < m; j++)
		if (cnt[1][j] == n)
			return true;
	return false;
}

void solve() {
	cin >> n >> m;
	int ca = 0, cCorner = 0, cEdge = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'A'){
				ca++;
				cnt[0][i]++, cnt[1][j]++;
				if ((i==0 || i==n-1) && (j==0 || j==m-1))
					cCorner++;
				else if (i == 0 || j == 0 || i == n-1 || j == m-1)
					cEdge++;
			}
	}
	if (ca == 0)
		cout << "MORTAL\n";
	else if (ca == n*m)
		cout << "0\n";
	else if (cnt[0][0] == m || cnt[0][n-1] == m || cnt[1][0] == n || cnt[1][m-1] == n)
		cout << "1\n";
	else if (cCorner || check())
		cout << "2\n";
	else if (cEdge)
		cout << "3\n";
	else
		cout << "4\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}