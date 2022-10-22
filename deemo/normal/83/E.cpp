#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MAXM = 20 + 1;

int n, m, a[MAXN];
int x, d[MAXM][1<<MAXM];

int get(int x, int y){
	int ms = (1<<m) - 1;
	for (int i = 0; i < m; i++, ms >>= 1, y >>= 1)
		if ((ms & x) == y)
			return i;
	return m;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;	cin >> s;	m = s.size();
		for (int j = 0; j < m; j++)
			if (s[j] == '1')
				a[i] |= 1<< m - j - 1;
	}
	
	memset(d, 63, sizeof(d));
	int z = m;

	for (int i = 1; i < n; i++){
		int y = get(a[i - 1], a[i]);

		int mn = z + m;
		for (int j = 0; j <= m; j++)
			mn = min(mn, d[m-j][a[i]>>j] + x + j);
	//	cout << i - 1 << " " << mn << "    " << x<<"  " << z << endl;
		//cout << d[3][0] + x << endl;

		z += y;
		x += y;
		int ms = (1<<m)-1;
		for (int j = 0; j <= m; j++, ms >>= 1)
			d[m - j][a[i - 1]&ms] = min(d[m - j][a[i - 1] & ms], mn - x);

	}
	
	int ans = z;
	for (int j = 0; j < MAXM; j++)
		for (int i = 0; i < 1<<m; i++)
			ans = min(ans, d[j][i] + x);
	cout << ans << "\n";
	return 0;
}