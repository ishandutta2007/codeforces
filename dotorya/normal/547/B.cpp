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

set <pii> S;

vector <pii> V;

int ANS[200050];
int main() {
    int N, i, t;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &t);
        V.push_back(pii(t, i));
    }
    sort(V.begin(), V.end());

    int C = 1;
    for (i = N-1; i >= 0; i--) {
        t = V[i].second;
        int st = t, en = t;
        if (S.empty()) S.insert(pii(t, t));
        else {
            set <pii>::iterator it = S.lower_bound(pii(t, 0));
            if (it != S.end() && it->first == t + 1) {
                en = it->second;
                S.erase(it);
            }

            it = S.lower_bound(pii(t, 0));
            if (it != S.begin()) {
                it--;
                if (it->second == t - 1) {
                    st = it->first;
                    S.erase(it);
                }
            }

            S.insert(pii(st, en));
        }
        for (; C <= en - st + 1; C++) ANS[C] = V[i].first;
    }

    for (i = 1; i <= N; i++) printf("%d ", ANS[i]);
    return 0;
}
//*/