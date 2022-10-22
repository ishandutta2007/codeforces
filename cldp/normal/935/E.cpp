#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int INF = 1000000007;
const double PI = acos(-1.0);

string Q;
int A, B;
int R[MAXN];
vector<int> x[MAXN];

int f[MAXN][102]; // max
int g[MAXN][102]; // min
bool z[MAXN][102];

void dp(int a, int A, bool isA) {
    if (z[a][A]) return ;
    z[a][A] = true;

    if (Q[a] >= '0' && Q[a] <= '9') {
        if (A > 0) {
            f[a][A] = -INF;
            g[a][A] = INF;
            return ;
        }
        f[a][A] = g[a][A] = Q[a] - '0';
        return ;
    }

    int p = a + 1, q;
    if (Q[p] == '(') {
        q = R[p] + 2;
    } else {
        q = p + 2;
    }
    for (int i = 0; i <= A; ++i) {
        dp(p, i, isA);
        dp(q, A - i, isA);
    }

    f[a][A] = -INF;
    g[a][A] = INF;
    if (isA) {
        // use +
        if (A > 0) {
            for (int i = 0; i <= A - 1; ++i) {
                f[a][A] = max(f[a][A], f[p][i] + f[q][A - 1 - i]);
                g[a][A] = min(g[a][A], g[p][i] + g[q][A - 1 - i]);
            }
        }
        // use -
        for (int i = 0; i <= A; ++i) {
            f[a][A] = max(f[a][A], f[p][i] - g[q][A - i]);
            g[a][A] = min(g[a][A], g[p][i] - f[q][A - i]);
        }
    } else {
        // use +
        for (int i = 0; i <= A; ++i) {
            f[a][A] = max(f[a][A], f[p][i] + f[q][A - i]);
            g[a][A] = min(g[a][A], g[p][i] + g[q][A - i]);
        }
        // use - 
        if (A > 0) {
            for (int i = 0; i <= A - 1; ++i) {
                f[a][A] = max(f[a][A], f[p][i] - g[q][A - 1 - i]);
                g[a][A] = min(g[a][A], g[p][i] - f[q][A - 1 - i]);
            }
        }
    }
 //   cout << a << " " << A << " " << f[a][A] << " " << g[a][A] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
/*
    string P = "(1?1)";
    for (int i = 0; i < 100; ++i) P = "(" + P + "?1)";
    cout << P << endl;
return 0;
*/

    cin >> Q;
    cin >> A >> B;
    if (Q.size() == 1) {
        cout << Q << endl;
        return 0;
    }
    stack<int> S;
    for (int i = 0; i < Q.size(); ++i) {
        if (Q[i] == '(') S.push(i);
        if (Q[i] == ')') {
            R[S.top()] = i;
            S.pop();
        }
    }

    if (A <= 100) {
        dp(0, A, true);
        cout << f[0][A] << endl;
    } else {
        dp(0, B, false);
        cout << f[0][B] << endl;
    }

    return 0;
}