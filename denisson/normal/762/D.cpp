#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>

using namespace std;

typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;

const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

int n;
int a[3][100007];
ll dp[2][64][6];
int pos[3][3];
pair<int, int> ge[6];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("subrev.in", "r", stdin);
		//freopen("subrev.out", "w", stdout);
	}
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j < 64; j++)
			for (int k = 0; k < 6; k++)
				dp[i][j][k] = -LINF;
	pos[0][0] = 0;
	pos[0][1] = 1;
	pos[1][0] = 2;
	pos[1][1] = 3;
	pos[2][0] = 4;
	pos[2][1] = 5;
	ge[0] = mp(0, 0);
	ge[1] = mp(0, 1);
	ge[2] = mp(1, 0);
	ge[3] = mp(1, 1);
	ge[4] = mp(2, 0);
	ge[5] = mp(2, 1);
	dp[0][1 + 2 + 4 + 16][1] = a[0][1];
	for (int i = 1; i <= n; i++) {
		for (int mask = 0; mask < 64; mask++) {
			for (int now = 0; now < 6; now++) {
				if (dp[0][mask][now] == -LINF) continue;
				int x = ge[now].x, y = ge[now].y;
				for (int to = 0; to < 4; to++) {
					int nx = x + dx[to];
					int ny = y + dy[to];
					if (nx >= 0 && nx < 3 && ny >= 0 && ny <= 1) {
						if (!((mask >> pos[nx][ny]) & 1)) {
							dp[0][mask + (1 << pos[nx][ny])][pos[nx][ny]] = max(dp[0][mask + (1 << pos[nx][ny])][pos[nx][ny]],
								dp[0][mask][now] + (ll)a[nx][i - abs(ny - 1)]);
						}
					}
					if (nx >= 0 && nx < 3 && ny == 2) {
						int newmask = 0;
						if ((mask >> 1) & 1) newmask += 1;
						if ((mask >> 3) & 1) newmask += 4;
						if ((mask >> 5) & 1) newmask += 16;
						newmask += (1 << pos[nx][1]);
						dp[1][newmask][pos[nx][1]] = max(dp[1][newmask][pos[nx][1]], dp[0][mask][now] + (ll)a[nx][i + 1]);
					}
				}
			}
		}
		
		for (int mask = 0; mask < 64; mask++) {
			for (int now = 0; now < 6; now++) {
				dp[0][mask][now] = dp[1][mask][now];
				dp[1][mask][now] = -LINF;
			}
		}
	}
	ll ans = -LINF;
	for (int mask = 0; mask < 64; mask++) {
		if ((mask >> 5) & 1)
			ans = max(ans, dp[0][mask][5]);
	}
	cout << ans;
}