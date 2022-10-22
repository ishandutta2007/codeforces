#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second

const int XX = 1e3 + 10;
const int MAXN = 1e4+10;

int k, q;
ld p[MAXN][XX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> q;
	p[0][0] = 1;
	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j <= k; j++)
			p[i][j] = p[i - 1][j]*(ld(j)/k) + p[i - 1][j - 1]*(ld(k-j+1)/k);

	while (q--){
		int ans = 0;
		int x;	cin >> x;
		ld temp = x/ld(2000.);
		while (p[ans][k] < temp)
			ans++;
		cout << ans << "\n";
	}
	return 0;
}