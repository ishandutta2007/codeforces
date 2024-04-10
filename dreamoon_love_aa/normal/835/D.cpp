#include<iostream>
#include<algorithm>
#include<string>
#define SZ(x) (int)(x.size())
#define ll long long
using namespace std;
int hsh[5005][5005];
int dp[5005][5005];
bool ispal[5005][5005];
int ans[5005];
string st;
void predo() {
	ll vv;
	for (int i = 1; i < SZ(st); ++i) {
		vv = 0;
		for (int j = i; j < SZ(st); ++j) {
			vv *= 127;
			vv = (vv + st[j]) % 1000000007;
			hsh[i][j] = vv;
		}
	}
	for (int i = 1; i<SZ(st); ++i) {
		dp[i][i] = ispal[i][i] = ispal[i][i - 1] = true;
		ans[1]++;
	}
	for (int i = 2; i <= SZ(st); ++i) {
		for (int j = 1; j + i - 1<SZ(st); ++j) {
			if (ispal[j + 1][j + i - 2] && st[j] == st[j + i - 1]) ans[1]++, ispal[j][j + i - 1] = dp[j][j+i-1]= true;
		}
	}
}

int main(void) {
	cin >> st;
	st.insert(0, "?");
	predo();
	for (int i = 2; i <= SZ(st); ++i) {
		for (int j = 1; j + i - 1<SZ(st); ++j) {
			if (hsh[j][j + i / 2 - 1] == hsh[j + i - i / 2][j + i - 1]) {
				if (dp[j][j + i / 2 - 1] == dp[j + i - i / 2][j + i - 1]) {
					if (dp[j][j + i / 2 - 1]) {
						dp[j][j + i - 1] = dp[j][j + i / 2 - 1] + 1;
						ans[dp[j][j + i - 1]]++;
					}
				}
			}
		}
	}
	for (int i = SZ(st) - 1; i > 1; --i) ans[i] += ans[i + 1];
	for (int i = 1; i<SZ(st); ++i) cout << ans[i] << (" \n"[i == SZ(st)]);
}