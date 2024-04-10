#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MAXN = 5e3 + 10;

int n, a[MAXN];
string s;
int cnt[MAXN][26], cc[MAXN];
bool ok[26];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s; n = s.size();
	for (int i = 0; i < n; i++) {
		a[i] = (s[i] - 'a');
		cc[a[i]]++;
	}
	ld ans = 0;
	for (int w = 0; w < 26; w++){
		if (!cc[w]) continue;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
			if (a[i] == w){
				for (int t = 1; t < n; t++){
					int j = i +t;
					if (j >= n) j -= n;
					cnt[t][a[j]]++;
				}
			}

		bool fl = false;
		int mn = 0;
		for (int t = 1; !fl && t < n; t++) {
			bool fail = false;
			int cg = 0;
			for (int w = 0; w < 26; w++)
				if (cnt[t][w] > 1)
					fail = true;
				else if (cnt[t][w] == 1)
					cg++;
			fl |= !fail;
			mn = max(mn, cg);
		}
		ok[w] = fl;
		if (!fl && mn)
			ans += mn/ ld(n);
	}
	for (int i = 0; i < n; i++)
		if (ok[a[i]])
			ans += 1/ ld(n);
	cout  << fixed << setprecision(12);
	cout << ans << endl;
	return 0;
}