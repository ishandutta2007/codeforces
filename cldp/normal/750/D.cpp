#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const int MX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int MY[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int N;
int X[33];
bool Z[400][400];

struct node {
    int a, b, d;
    node() {}
    node(int _a, int _b, int _d): a(_a), b(_b), d(_d) {}

    bool operator < (const node &B) const {
        if (a != B.a) return a < B.a;
        if (b != B.b) return b < B.b;
        return d < B.d;
    }
};

set<node> S[2];


int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> X[i];
    bool curr = 0;
    S[0].insert(node(200, 200, 0));
    for (int i = 0; i < N; ++i) {
        S[!curr].clear();
        for (auto iter = S[curr].begin(); iter != S[curr].end(); ++iter) {
            int a = iter->a;
            int b = iter->b;
            int d = iter->d;
            for (int k = 0; k < X[i]; ++k) {
                a += MX[d];
                b += MY[d];
                Z[a][b] = true;
            }
            S[!curr].insert(node(a, b, (d + 1) % 8));
            S[!curr].insert(node(a, b, (d + 7) % 8));
        }
        curr = !curr;
    }
    int ans = 0;
    for (int i = 0; i < 400; ++i)
        for (int j = 0; j < 400; ++j) 
            if (Z[i][j]) ++ans;
    cout << ans << endl;
    return 0;
}