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

const int IT_MAX = 524288;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

int in[205];
int sum[205];
vector <int> V1;
vector <int> V2;
int main() {
    int N, K, i, j, k;
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; i++) {
        scanf("%d", &in[i]);
        sum[i] = sum[i - 1] + in[i];
    }

    int ans = -INF;
    for (i = 1; i <= N; i++) {
        for (j = i; j <= N; j++) {
            int t = sum[j] - sum[i - 1];
            for (k = 1; k <= N; k++) {
                if (k >= i && k <= j) V1.push_back(in[k]);
                else V2.push_back(in[k]);
            }
            sort(V1.begin(), V1.end());
            sort(V2.begin(), V2.end());
            int p1 = 0, p2 = V2.size() - 1;
            for (k = 1; k <= K && p1 < V1.size() && p2 >= 0 && V1[p1] < V2[p2]; k++, p1++, p2--) t += V2[p2] - V1[p1];
            ans = max(ans, t);
            V1.clear();
            V2.clear();
        }
    }
    printf("%d", ans);
    return 0;
}
//*/