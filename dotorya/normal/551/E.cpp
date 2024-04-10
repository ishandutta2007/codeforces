//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

ll in[1000000];
ll P[1000];
vector <pli> bracket[1000];
int pos[1000][2];
int bs1(int x, ll n) {
    int st = 0, en = bracket[x].size() - 1, mi, ans = bracket[x].size();
    while (st <= en) {
        mi = (st + en) / 2;
        if (bracket[x][mi].first >= n) {
            ans = mi;
            en = mi - 1;
        }
        else st = mi + 1;
    }
    return ans;
}

int bs2(int x, ll n) {
    int st = 0, en = bracket[x].size() - 1, mi, ans = -1;
    while (st <= en) {
        mi = (st + en) / 2;
        if (bracket[x][mi].first <= n) {
            ans = mi;
            st = mi + 1;
        }
        else en = mi - 1;
    }
    return ans;
}
int main() {
    int N, Q, i, j, Z, chk, t1, t2, t3;
    int mn, mx;
    scanf("%d %d", &N, &Q);
    for (Z = 1; Z*Z <= N; Z++);
    int B = 0;
    for (i = 1; i <= N; i++) {
        if ((i - 1) % Z == 0) {
            B++;
            pos[B][0] = i;
            pos[B - 1][1] = i-1;
        }
        scanf("%lld", &in[i]);
        bracket[B].push_back(pli(in[i], i));
    }
    pos[B][1] = N;
    for (i = 1; i <= B; i++) sort(bracket[i].begin(), bracket[i].end());
    
    for (i = 1; i <= Q; i++) {
        scanf("%d", &chk);
        if (chk == 1) {
            scanf("%d %d %d", &t1, &t2, &t3);
            for (j = 1; j <= B; j++) {
                if (pos[j][0] > t2 || pos[j][1] < t1) continue;
                if (pos[j][0] >= t1 && pos[j][1] <= t2) {
                    P[j] += t3;
                    continue;
                }
                bracket[j].clear();
                for (int k = pos[j][0]; k <= pos[j][1]; k++) {
                    if (k >= t1 && k <= t2) in[k] += t3;
                    bracket[j].push_back(pli(in[k], k));
                }
                sort(bracket[j].begin(), bracket[j].end());
            }
        }
        else {
            scanf("%d", &t1);
            mn = -1, mx = -2;
            for (j = 1; j <= B; j++) {
                t2 = bs1(j, t1 - P[j]);
                if (t2 == bracket[j].size() || bracket[j][t2].first != t1-P[j]) continue;
                mn = bracket[j][t2].second;
                break;
            }
            if (mn == -1) {
                printf("-1\n");
                continue;
            }
            for (j = B; j >= 1; j--) {
                t2 = bs2(j, t1 - P[j]);
                if (t2 == -1 || bracket[j][t2].first != t1-P[j]) continue;
                mx = bracket[j][t2].second;
                break;
            }
            printf("%d\n", mx - mn);
        }
    }
    return 0;
}
//*/