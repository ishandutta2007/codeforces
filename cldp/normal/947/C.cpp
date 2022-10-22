#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 300010;
const int MAXM = 30000000;
const int INF = 1000000007;
const double PI = acos(-1.0);

struct Trie {
    int M, root; 
    int L[MAXM], R[MAXM], cnt[MAXM];

    Trie() {
        root = 0;
        M = 1;
        L[0] = R[0] = -1;
    }

    void add(int a) {
        int t = root;
        for (int i = 29; i >= 0; --i) {
            if (a & (1 << i)) {
                if (L[t] == -1) {
                    L[t] = M;
                    L[M] = R[M] = -1;
                    ++M;
                }
                t = L[t];
            } else {
                if (R[t] == -1) {
                    R[t] = M;
                    L[M] = R[M] = -1;
                    ++M;
                }
                t = R[t];
            }
            ++cnt[t];
        }
    }

    int solve(int a) {
        int t = root;
        int ans = 0;
        vector<int> X;
        X.push_back(t);
        for (int i = 29; i >= 0; --i) {
            if (a & (1 << i)) {
                if (L[t] == -1) {
                    t = R[t];
                } else {
                    ans += (1 << i);
                    t = L[t];
                }
            } else {
                if (R[t] == -1) {
                    ans += (1 << i);
                    t = L[t];
                } else {
                    t = R[t];
                }
            }
            X.push_back(t);
            --cnt[t];
        }
        for (int i = 30; i >= 1; --i) {
            int t = X[i], p = X[i - 1];
            if (cnt[t] == 0) {
                if (t == L[p]) L[p] = -1; else R[p] = -1;
            }
        }
        return ans;
    }
};

int x[MAXN], y[MAXN];
Trie T;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i];
    for (int i = 0; i < N; ++i) {
        cin >> y[i];
        T.add(y[i]);
    }
    for (int i = 0; i < N; ++i) {
        int K = T.solve(x[i]);
        cout << (x[i] ^ K) << endl;
    }
    return 0;
}