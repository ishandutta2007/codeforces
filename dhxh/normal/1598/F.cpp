#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;
const int N = 4e5;

int n, m, t;

string str[25];
int f[(1 << 20) + 5];
int g[(1 << 20) + 5];
int lst[25];
int mn[25];
int cnt[25][maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> str[i];
		int c = 0;
		for(j=0;j<str[i].length();j++){
			if(str[i][j] == '('){
				c++;
			}else{
				c--;
				mn[i] = min(mn[i], c);
				if(c <= mn[i]) cnt[i][-mn[i]]++;
			}
		}
		lst[i] = c;
	}

	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++){
			if(((i >> j) & 1)) continue;
			g[i ^ (1 << j)] = g[i] + lst[j];
		}
	}

	int ans = 0;
	memset(f, 0xc0, sizeof(f));
	f[0] = 0;
	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++){
			if(((i >> j) & 1)) continue;
			if(g[i] < 0) continue;
			if(mn[j] + g[i] < 0){
				ans = max(ans, f[i] + cnt[j][g[i]]);
			}else{
				f[i ^ (1 << j)] = max(f[i ^ (1 << j)], f[i] + cnt[j][g[i]]);
				ans = max(ans, f[i ^ (1 << j)]);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}