#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN], y[MAXN];
int xx[MAXN], yy[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i];
    for (int i = 0; i < N; ++i) cin >> y[i];
    for (int i = 0; i < N; ++i) {
        ++xx[x[i]];
        ++yy[y[i]];
    }
    vector<int> P, Q;
    for (int i = 0; i < N; ++i) {
        if (xx[x[i]] != 1) Q.push_back(i);
        if (yy[y[i]] != 1) Q.push_back(i);
        if (xx[i + 1] != 1) P.push_back(i + 1);
        if (yy[i + 1] != 1) P.push_back(i + 1); 
    }
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());
    Q.resize(unique(Q.begin(), Q.end()) - Q.begin());

    do {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < Q.size(); ++i) {
            if (P[i] != x[Q[i]]) ++cnt1;
            if (P[i] != y[Q[i]]) ++cnt2;
        }
        if (cnt1 == cnt2 && cnt1 == 1) {
            for (int i = 0; i < Q.size(); ++i) x[Q[i]] = P[i];
            break;
        }
    } while (next_permutation(P.begin(), P.end()));

    for (int i = 0; i < N; ++i) cout << x[i] << " ";
    cout << endl;
    return 0;
}