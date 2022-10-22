#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 100100;

struct node {
    int x1, y1, x2, y2;
};

node X[MAXN];
vector<int> L, R, T, B;

int main() {
    ios_base::sync_with_stdio(false);
    int D, N, M;
    cin >> D >> N >> M;
    for (int i = 0; i < D; ++i) {
        cin >> X[i].x1 >> X[i].y1 >> X[i].x2 >> X[i].y2;
        if (X[i].x1 > X[i].x2) swap(X[i].x1, X[i].x2);
        if (X[i].y1 > X[i].y2) swap(X[i].y1, X[i].y2);
        L.push_back(X[i].x1);
        R.push_back(X[i].x2);
        T.push_back(X[i].y1);
        B.push_back(X[i].y2);
    }
    sort(L.begin(), L.end());
    sort(R.rbegin(), R.rend());
    sort(T.begin(), T.end());
    sort(B.rbegin(), B.rend());

    int cl, cr, ct, cb;
    cin >> cl >> cr >> ct >> cb;

    int XL = L[cl], XR = R[cr], YT = T[ct], YB = B[cb];
    /*
    if (cl > 0 && L[cl] == L[cl - 1]) XL = N + 1;
    if (cr > 0 && R[cr] == R[cr - 1]) XR = 0;
    if (ct > 0 && T[ct] == T[ct - 1]) YT = M + 1;
    if (cb > 0 && B[cb] == B[cb - 1]) YB = 0;
cout << XL << " "<< XR << " " << YT << " " << YB << endl;
*/
    int cnt = 0, ans = -1;
    for (int i = 0; i < D; ++i) {
        if (XL == X[i].x1 && X[i].x2 == XR && YT == X[i].y1 && X[i].y2 == YB) {
            ++cnt;
            ans = i + 1;
        }
    }

    if (cnt != 1) {
        cout << -1 << endl; 
    } else {
        int ccl = 0, ccr = 0, cct = 0, ccb = 0;
        for (int i = 0; i < D; ++i) {
            if (i + 1 == ans) continue;
            if (X[i].x1 < X[ans - 1].x2) ++ccl;
            if (X[i].x2 > X[ans - 1].x1) ++ccr;
            if (X[i].y1 < X[ans - 1].y2) ++cct;
            if (X[i].y2 > X[ans - 1].y1) ++ccb;
        }
        if (ccl == cl && ccr == cr && cct == ct && ccb == cb) {
            cout << ans << endl;   
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}