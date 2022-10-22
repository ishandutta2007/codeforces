#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, mark[MAXN], pr[MAXN], simple[MAXN], dp[MAXN], cnt[MAXN], cnt2[MAXN];
int sec[10], mul[500];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i < MAXN; i++)
		if (!pr[i])
			for (int j = i; j < MAXN; j += i)
				pr[j] = i;

	simple[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (pr[i] != pr[i/pr[i]])
			simple[i] = simple[i/pr[i]] * pr[i];
		else
			simple[i] = simple[i/pr[i]];
	}

	cin >> n;
	int g = -1;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		if (x == 1){
			cout << "1\n";
			return 0;
		}

		x = simple[x];
		if (g == -1)
			g = x;
		else
			g = __gcd(g, x);
		mark[x] = 1;
	}

	if (g > 1)
		cout << "-1\n";
	else{
		for (int i = 2; i < MAXN; i++)
			if (pr[i] == i && mark[i]){
				cout << "2\n";
				return 0;
			}

		n = 0;
		for (int i = 2; i < MAXN; i++)
			if (mark[i]) {
				for (int j = i+i; j < MAXN; j += i)
					mark[j] = 0;
				n++;
			}

		for (int i = 2; i < MAXN; i++)
			for (int j = i; j < MAXN; j += i)
				cnt[i] += mark[j];

		for (int i = 2; i < MAXN; i++)
			if (simple[i] == i){
				int temp = i, sz = 0;
				while (temp>1){
					sec[sz++] = pr[temp];
					temp /= pr[temp];
				}

				mul[0] = 1;
				for (int mask = 1; mask < 1<<sz; mask++){
					for (int w = 0; w < sz; w++)
						if (mask>>w&1){
							mul[mask] = mul[mask^1<<w] * sec[w];
							break;
						}

					if (__builtin_popcount(mask)&1)
						cnt2[i] += cnt[mul[mask]];
					else
						cnt2[i] -= cnt[mul[mask]];
				}
			}

		memset(dp, 63, sizeof(dp));
		dp[1] = 0;
		for (int i = 1; i < MAXN; i++)
			if (simple[i] == i){
				for (int j = i+i; j < MAXN; j += i)
					if (cnt2[j/i] < n)
						dp[j] = min(dp[j], dp[i]+1);
			}

		int ans = 1e9;
		for (int i = 2; i < MAXN; i++)
			if (mark[i])
				ans = min(ans, dp[i] + 1);
		cout << ans << "\n";
	}
	return 0;
}