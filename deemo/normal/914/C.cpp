#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;
const int MOD = 1e9 + 7;

int cnt[MAXN], ch[MAXN][MAXN], k;
string n;

int add(int x, int y){
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cnt[1] = 0;
	for (int i = 2; i < MAXN; i++){
		int x = __builtin_popcount(i);
		cnt[i] = cnt[x] + 1;
	}

	ch[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		ch[i][i] = ch[i][0] = 1;
		for (int j = 1; j < i; j++)
			ch[i][j] = add(ch[i-1][j], ch[i-1][j-1]);
	}

	int ans = 0;
	cin >> n >> k;
	int cc = 0;
	for (char c: n)
		if (c == '1')
			cc++;

	if (k == 0)
		ans = 1;
	else {
		for (int i = 1; i <= n.size(); i++)
			if (cnt[i] + 1 == k) {
				ans = add(ans, ch[n.size()][i]);

				int cur = 0;
				for (int j = 0; j < n.size(); j++) {
					if (n[j] == '0' && cur + 1 <= i)
						ans = add(ans, -ch[(int)n.size() - j-1][i-cur-1]);
					if (n[j] == '1')
						cur++;
				}
			}
		if (k == 1)
			ans = add(ans, -1);
	}

	cout << ans << "\n";
	return 0;
}