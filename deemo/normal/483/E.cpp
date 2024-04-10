#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const int MAXN = 50 + 3;
const int MAX = 20 + 2;

int n, m;
string s[MAXN];
ld ans = 0, cc[200][200];
ll cn[1 << MAX];

int get(int a, int b){
	int mask = 0;
	for (int i = 0; i < m; i++)
		if (s[a][i] == s[b][i])	mask |= 1 << i;
	return	mask;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(16);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> s[i];
	m = s[0].size();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			cn[get(i, j)] |= (1LL << ll(i)) | (1LL << ll(j));
	
	for (int i = (1 << m) - 1; i >= 0; i--)
		for (int j = 0; j < m; j++)
			if (((i >> j) & 1) == 0)
				cn[i] |= cn[i ^ (1 << j)];

	cc[0][0] = 1;
	for (int i = 1; i < 100; i++){
		cc[i][0] = cc[i][i] = 1;
		for (int j = 1; j < i; j++)
			cc[i][j] = cc[i - 1][j] + cc[i - 1][j - 1];
	}
	

	for (int i = 0; i < (1 << m); i++){
		int c = __builtin_popcount(i);
		int d = __builtin_popcountll(cn[i]);
		
		ld p = ld(d)/ ld(n);
		p *= ld(1)/ cc[m][c];
		if (p == 0)	continue;
		for (int j = 0; j < m; j++)
			if (((i >> j) & 1) == 0){
				int e = __builtin_popcountll(cn[i ^ (1LL << j)]);
				ans += ld(1)/ ld(m-c) * p * ld(d - e)/ d * (c + 1);
			}
	}
	cout << ans << endl;
	return	0;
}