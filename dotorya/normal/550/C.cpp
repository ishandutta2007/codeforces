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

char in[105];
vector <int> pos[10];
int main() {
    int i, j, k;
    scanf("%s", in);
    for (i = 0; in[i] != 0; i++) pos[in[i] - '0'].push_back(i);

    if (!pos[0].empty()) {
        printf("YES\n0");
        return 0;
    }
    if (!pos[8].empty()) {
        printf("YES\n8");
        return 0;
    }

    for (i = 16; i <= 100; i += 8) {
        if (pos[i / 10].empty() || pos[i % 10].empty()) continue;
        int t1 = pos[i / 10][0];
        int t2 = pos[i % 10].back();
        if (t1 < t2) {
            printf("YES\n%d", i);
            return 0;
        }
    }

    for (i = 104; i < 1000; i+=8) {
        int x1 = i / 100, x2 = (i / 10) % 10, x3 = i % 10;
        if (pos[x1].empty() || pos[x2].empty() || pos[x3].empty()) continue;
        int t1 = pos[x1][0];
        int t3 = pos[x3].back();
        for (j = 0; j < pos[x2].size(); j++) {
            if (t1 < pos[x2][j] && t3 > pos[x2][j]) {
                printf("YES\n%d", i);
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
//*/