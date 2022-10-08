//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

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

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

vector <int> task[2050];
int main() {
    int N, i, j, t;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &t);
        task[t].push_back(i);
    }

    for (i = 1; i <= 2000; i++) if (task[i].size() >= 3) break;
    if (i <= 2000) {
        printf("YES\n");
        t = i;
        for (i = 1; i <= 2000; i++) for (j = 0; j < task[i].size(); j++) printf("%d ", task[i][j]);
        printf("\n");
        for (i = 1; i <= 2000; i++) {
            if (i == t) {
                printf("%d %d ", task[t][1], task[t][0]);
                for (j = 2; j < task[i].size(); j++) printf("%d ", task[t][j]);
            }
            else for (j = 0; j < task[i].size(); j++) printf("%d ", task[i][j]);
        }
        printf("\n");
        for (i = 1; i <= 2000; i++) {
            if (i == t) {
                printf("%d %d %d ", task[t][2], task[t][0], task[t][1]);
                for (j = 3; j < task[i].size(); j++) printf("%d ", task[t][j]);
            }
            else for (j = 0; j < task[i].size(); j++) printf("%d ", task[i][j]);
        }
        return 0;
    }

    int t1 = -1;
    for (i = 1; i <= 2000; i++) {
        if (task[i].size() == 2) {
            if (t1 != -1) break;
            t1 = i;
        }
    }
    if (i > 2000) {
        printf("NO");
        return 0;
    }
    int t2 = i;
    printf("YES\n");
    for (i = 1; i <= 2000; i++) for (j = 0; j < task[i].size(); j++) printf("%d ", task[i][j]);
    printf("\n");
    for (i = 1; i <= 2000; i++) {
        if (i == t1) {
            printf("%d %d ", task[t1][1], task[t1][0]);
            continue;
        }
        else for (j = 0; j < task[i].size(); j++) printf("%d ", task[i][j]);
    }
    printf("\n");
    for (i = 1; i <= 2000; i++) {
        if (i == t2) {
            printf("%d %d ", task[t2][1], task[t2][0]);
            continue;
        }
        else for (j = 0; j < task[i].size(); j++) printf("%d ", task[i][j]);
    }
    return 0;
}
//*/