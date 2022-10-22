#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int L[MAXN], c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string Q;
    cin >> Q;
    int T = 0;
    set<int> S[2];
    for (int i = 0; i < Q.size(); ) {
        int j = i;
        while (j < Q.size() && Q[j] == Q[i]) ++j;
        L[T] = j - i;
        c[T] = Q[i];
        S[0].insert(T);
        ++T;
        i = j;
    }
    int i = 0, ans = 0;
    while (S[i].size() > 1) {
        L[*S[i].begin()] += 1;
        L[*S[i].rbegin()] += 1;
        for (auto iter = S[i].begin(); iter != S[i].end(); ++iter) L[*iter] -= 2;
        auto iter = S[i].begin();
        while (iter != S[i].end() && L[*iter] <= 0) ++iter;

        while (iter != S[i].end()) {
            auto iter2 = iter;
            int cnt = 0;
            while (iter2 != S[i].end() && (c[*iter2] == c[*iter] || L[*iter2] <= 0)) {
                if (c[*iter2] == c[*iter] && L[*iter2] > 0) cnt += L[*iter2];
                ++iter2;
            }
            S[1 - i].insert(*iter);
            L[*iter] = cnt;
            iter = iter2;
        }

        S[i].clear();
        i = 1 - i;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}