//Please don't let go, can't we stay for a while?
//It's just too hard to say goodbye..

#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<cstring>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second
#define up pu
#define count makingsure

const int MAXN = 2e3 + 100;
const int MOD = 1e9 + 7;

int n;
ll ss[4][3 * MAXN];
ld tt[4][3 * MAXN];
int p[4][MAXN][MAXN], le[MAXN][MAXN], ri[MAXN][MAXN], dn[MAXN][MAXN], up[MAXN][MAXN];
char s[MAXN][MAXN], t[MAXN][MAXN];
bool ok[MAXN][MAXN];

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < n;}

pair<int, int>	mx(pair<int, int> a, pair<int, int> b){
	ld aa = tt[2][a.F] + tt[3][a.S];
	ld bb = tt[2][b.F] + tt[3][b.S];
	return (aa < bb?b:a);
}

int count (int w, int a, int b, int aa, int bb){
	return p[w][aa][bb] - p[w][a][bb] - p[w][aa][b] + p[w][a][b];}

pair<int, int>	get(){
	for (int j = 0; j < n; j++)
		up[0][j] = s[0][j] != '0';
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
			up[i][j] = (s[i][j] == '0'?0:up[i - 1][j] + 1);
	
	for (int j = 0; j < n; j++)
		dn[n - 1][j] = s[n - 1][j] != '0';
	for (int i = n - 2; ~i; i--)
		for (int j = 0; j < n; j++)
			dn[i][j] = (s[i][j] == '0'?0:dn[i + 1][j] + 1);

	for (int i = 0; i < n; i++)
		le[i][0] = s[i][0] != '0';
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n; j++)
			le[i][j] = (s[i][j] == '0'?0:le[i][j - 1] + 1);

	for (int i = 0; i < n; i++)
		ri[i][n - 1] = s[i][n - 1] != '0';
	for (int i = 0; i < n; i++)
		for (int j = n - 2; ~j; j--)
			ri[i][j] = (s[i][j]=='0'?0:ri[i][j + 1] + 1);

	memset(p, 0, sizeof(p));
	for (int w = 2; w <= 3; w++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				p[w][i + 1][j + 1] = p[w][i + 1][j] + p[w][i][j + 1] - p[w][i][j] + int(s[i][j] == char(w + 48));

	pair<int, int>	ret(0, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ok[i][j]){
				int mn = min({le[i][j], ri[i][j], up[i][j], dn[i][j]});
				ret = mx(ret, {count(2, i - mn + 1, j, i + mn, j + 1) + count(2, i, j - mn + 1, i + 1, j + mn) - int(s[i][j] == '2'), 
					count(3, i - mn + 1, j, i + mn, j + 1) + count(3, i, j - mn + 1, i + 1, j + mn) - int(s[i][j] == '3')}); 
			}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	
	{
		ss[2][0] = ss[3][0] = 1;
		for (int w = 2; w <= 3; w++)
			for (int i = 1; i < 3 * MAXN; i++)
				ss[w][i] = (ss[w][i - 1] * ll(w)) % MOD;

		tt[2][1] = log(2);
		tt[3][1] = log(3);
		for (int w = 2; w <= 3; w++)
			for (int i = 2; i < 3 * MAXN; i++)
				tt[w][i] = tt[w][i - 1] + tt[w][1];
	}

	int cnt = 0;
	{
		cin >> n;
		for (int i = 0; i < n; i++)	
			cin >> s[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ok[i][j] = 1, cnt += int(s[i][j] != '0');
	}
	if (cnt == 0){
		cout << 0 << endl;
		return 0;
	}

	pair<int, int>	ans(0, 0);
	ans = mx(ans, get());
	memset(ok, 0, sizeof(ok));
	
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				t[i + j][i - j + (n - 1)] = s[i][j], ok[i + j][i - j + (n - 1)] = 1;
		
		n = 2 * n - 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (t[i][j] == 0 && fit(i + 1, j) && fit(i - 1, j) && t[i - 1][j] != 0 && t[i + 1][j] != 0)
					t[i][j] = '1';

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (t[i][j] == 0)
					t[i][j] = '0';

		memcpy(s, t, sizeof(t));
	}
	ans = mx(ans, get());
	cout << ss[2][ans.F] * ss[3][ans.S] % MOD << endl;
	return 0;
}