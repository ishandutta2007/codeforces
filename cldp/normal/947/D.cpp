#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101000;
const int INF = 1000000007;
const double PI = acos(-1.0);

int cntP[MAXN], cntQ[MAXN];
int preP[MAXN], preQ[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string P, Q;
    cin >> P >> Q;
    for (int i = 0; i < P.size(); ++i) {
        preP[i + 1] = preP[i];
        cntP[i + 1] = cntP[i];
        if (P[i] == 'A') continue;
        cntP[i + 1] = cntP[i] + 1;
        preP[i + 1] = i + 1;
    }
    for (int i = 0; i < Q.size(); ++i) {
        preQ[i + 1] = preQ[i];
        cntQ[i + 1] = cntQ[i];
        if (Q[i] == 'A') continue;
        cntQ[i + 1] = cntQ[i] + 1;
        preQ[i + 1] = i + 1;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int A = cntP[b] - cntP[a - 1];
        int B = cntQ[d] - cntQ[c - 1];
        if ((A + B) & 1) {
            cout << 0;
            continue;
        }
        if (A > B) {
            cout << 0;
            continue;
        }
        int B1 = preP[b], B2 = preQ[d];
        if (A == B) {
            if (A == 0) {
                if ((b - a) >= (d - c) && ((b - a) - (d - c)) % 3 == 0) cout << 1; else cout << 0;
                continue;
            }
            if ((b - B1) >= (d - B2) && ((b - B1) - (d - B2)) % 3 == 0) cout << 1; else cout << 0;
            continue;
        }
        if (A == 0) {
            if (d - B2 < b - a + 1) cout << 1; else cout << 0;
            continue;
        }
        if (d - B2 <= b - B1) cout << 1; else cout << 0;
    }
    cout << endl;

    return 0;
}