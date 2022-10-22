#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXN = 100010;

int X[MAXN], Y[MAXN], Z[MAXN];

unordered_map<string, pair<int, int> > C;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    int t1 = 1, t2 = -1;
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d%d", &X[i], &Y[i], &Z[i]); 
        if (X[i] > Y[i]) swap(X[i], Y[i]);
        if (Y[i] > Z[i]) swap(Y[i], Z[i]);
        if (X[i] > Y[i]) swap(X[i], Y[i]);

        if (X[i] > ans) {
            ans = X[i];
            t1 = i;
            t2 = -1;
        }

        string P, Q, R;
        P = to_string(X[i]) + " " + to_string(Y[i]);
        Q = to_string(X[i]) + " " + to_string(Z[i]);
        R = to_string(Y[i]) + " " + to_string(Z[i]);

        if (C.find(R) != C.end()) {
            int cnt = min(Y[i], C[R].first + X[i]);
            if (cnt > ans) {
                ans = cnt;
                t1 = C[R].second;
                t2 = i;
            }
        }

        if (C.find(P) == C.end() || C[P].first < Z[i]) C[P] = make_pair(Z[i], i);
        if (C.find(Q) == C.end() || C[Q].first < Y[i]) C[Q] = make_pair(Y[i], i);
        if (C.find(R) == C.end() || C[R].first < X[i]) C[R] = make_pair(X[i], i);
    }
    if (t2 == -1) {
        cout << 1 << endl << t1 << endl;
    } else {
        cout << 2 << endl << t1 << endl << t2 << endl;
    }
    return 0;
}