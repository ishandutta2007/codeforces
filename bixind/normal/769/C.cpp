#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

#define x kalsdjfgh
#define y amzndlksg
#define x1 sdsdfgsfd
#define y1 djghlsers
#define ft first
#define sd second
#define pb push_back
#define eb emplace_back

using namespace std;

typedef long long int ll;
typedef long double ld;

const int MAXN = 2000;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ll LLINF = 1e18 + 10;

int N, M, K;
char mp[MAXN][MAXN];
int ansl = 0;
char ans[MAXN*MAXN];
int d[MAXN][MAXN];

bool canGo(int pi, int pj) {
    return mp[pi][pj] == '.';
}

bool shouldGo(int pi, int pj) {
    return mp[pi][pj] == '.' && d[pi][pj] == -1;
}

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[5] = "DLRU";

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    scanf("%d %d %d", &N, &M, &K);

    if (K&1) {
        puts("IMPOSSIBLE");
        return 0;
    }

    for (int i = 0; i <= N+1; ++i) {
        for (int j = 0; j <= M+1; ++j) {
            mp[i][j] = '*';
        }
    }

    int si, sj;
    for (int i = 1; i <= N; ++i) {
        scanf("%s", &mp[i][1]);
        for (int j = 1; j <= M; ++j) {
            if (mp[i][j] == 'X') {
                mp[i][j] = '.';
                si = i;
                sj = j;
            }
        }
        mp[i][M+1] = '*';
    }

    if (mp[si-1][sj] == '*' && mp[si+1][sj] == '*' &&
        mp[si][sj-1] == '*' && mp[si][sj+1] == '*') {
        puts("IMPOSSIBLE");
        return 0;
    }

    memset(d, -1, sizeof(d));

    queue<pair<int, int>> bfsq;
    d[si][sj] = 0;
    bfsq.push(make_pair(si, sj));

    int pi, pj;
    while (!bfsq.empty()) {
        pi = bfsq.front().ft;
        pj = bfsq.front().sd;
        bfsq.pop();

        for (int i = 0; i < 4; ++i) {
            if (shouldGo(pi+dx[i], pj+dy[i])) {
                bfsq.push(make_pair(pi+dx[i], pj+dy[i]));
                d[pi+dx[i]][pj+dy[i]] = d[pi][pj] + 1;
            }
        }
    }

    int retidx = -1;
    pi = si, pj = sj;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (canGo(pi + dx[j], pj + dy[j])) {
                pi += dx[j];
                pj += dy[j];
                ans[ansl++] = dir[j];
                break;
            }
        }

        if (d[pi][pj] + ansl == K) {
            break;
        }
    }

    while (pi != si || pj != sj) {
        for (int j = 0; j < 4; ++j) {
            if (canGo(pi + dx[j], pj + dy[j]) &&
                    d[pi + dx[j]][pj + dy[j]] + 1 == d[pi][pj]) {
                ans[ansl++] = dir[j];
                pi += dx[j];
                pj += dy[j];
                break;
            }
        }
    }

    puts(ans);

    return 0;
}