//*
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
#define MOD 1000000007
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef set<int>::iterator siit;

char inpu[1050];
int main() {
    int L, i, j, K;
    scanf("%s %d", inpu, &K);
    for (L = 0; inpu[L] != 0; L++);
    if (L%K != 0) {
        printf("NO");
        return 0;
    }

    for (i = 0; i < L; i += L / K) {
        int st = i, en = i + L / K - 1;
        for (j = st; j <= en; j++) if (inpu[st + en - j] != inpu[j]) break;
        if (j <= en) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
//*/