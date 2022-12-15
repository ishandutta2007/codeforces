#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t, n, f[100005][2][2];
map<int,int> mp;
char s[100005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s + 1); n = strlen(s + 1);
		memset(f, 0x3f, sizeof(int) * 4 * (n + 1));
		f[1][0][0] = 0; f[1][0][1] = f[1][1][0] = 1; f[1][1][1] = 2;
		for (int i = 2; i <= n; i++) {
			if (s[i] == s[i - 2]) {
				if (s[i] == s[i - 1]) {
					f[i][0][1] = min(f[i - 1][0][0] + 1, f[i - 1][1][0] + 1);
					f[i][1][0] = f[i - 1][1][1];
					f[i][1][1] = min(f[i - 1][0][1] + 1, f[i - 1][1][1] + 1);
				}
				else {
					f[i][0][0] = f[i - 1][1][0];
					f[i][0][1] = min(f[i - 1][0][0] + 1, f[i - 1][1][0] + 1);
					f[i][1][0] = f[i - 1][1][1];
					f[i][1][1] = min(f[i - 1][0][1] + 1, f[i - 1][1][1] + 1);
				}
			}
			else {
				if (s[i] == s[i - 1]) {
					f[i][0][1] = min(f[i - 1][0][0] + 1, f[i - 1][1][0] + 1);
					f[i][1][0] = min(f[i - 1][0][1], f[i - 1][1][1]);
					f[i][1][1] = f[i][1][0] + 1;
				}
				else {
					f[i][0][0] = min(f[i - 1][0][0], f[i - 1][1][0]);
					f[i][0][1] = min(f[i - 1][0][0] + 1, f[i - 1][1][0] + 1);
					f[i][1][0] = min(f[i - 1][0][1], f[i - 1][1][1]);
					f[i][1][1] = f[i][1][0] + 1;
				}
			}
		}
		printf("%d\n", min(min(f[n][1][0], f[n][1][1]), min(f[n][0][1], f[n][0][0])));
	}
	return 0;
}