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

const int IT_MAX = 1048576;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

ll in[200050][2];
int ans[200050];
pli len[200050];
vector <pair<pll, int>> V;
set <pli> S;
int main() {
    int N, M, i, j;
    ll t1, t2;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) scanf("%I64d %I64d", &in[i][0], &in[i][1]);
    for (i = 0; i < M; i++) {
        scanf("%I64d", &len[i].first);
        len[i].second = i + 1;
    }

    for (i = 1; i < N; i++) {
        t1 = in[i + 1][0] - in[i][1];
        t2 = in[i + 1][1] - in[i][0];
        V.push_back(make_pair(pll(t1, t2), i));
    }
    sort(V.begin(), V.end());
    sort(len, len + M);

    int pos = M - 1;
    while (!V.empty()) {
        t1 = V.back().first.first;
        t2 = V.back().first.second;
        int t3 = V.back().second;
        
        while (pos >= 0 && len[pos].first >= t1) {
            S.insert(len[pos]);
            pos--;
        }
        
        set <pli>::iterator it = S.lower_bound(pli(t2+1, 0));
        if (it == S.begin()) break;
        it--;
        ans[t3] = it->second;
        S.erase(it);
        V.pop_back();
    }
    if (!V.empty()) {
        printf("No");
        return 0;
    }
    else {
        printf("Yes\n");
        for (i = 1; i < N; i++) printf("%d ", ans[i]);
    }
    return 0;
}
//*/