#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, T;
    cin >> N >> T;
    vector<LL> A(N), L(T), R(T);
    int sqrtN = sqrt(N);
    vector<vector<int>> queries(N);
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    for(int t = 0; t < T; ++t) {
        cin >> L[t] >> R[t];
        --L[t];
        --R[t];
        queries[L[t] / sqrtN].push_back(t);
    }
    vector<LL> ans(T, 0);
    vector<int> K(1000100, 0);
    for(auto& q : queries) {
        sort(q.begin(), q.end(), [&](int i, int j) { return R[i] < R[j]; });
        LL a = 0;
        auto add = [&](LL s) {
            a += (2 * K[s] + 1) * s;
            ++K[s];
        };
        auto rem = [&](LL s) {
            a += (-2 * K[s] + 1) * s;
            --K[s];
        };
        int l = 0, r = -1;
        for(int i : q) {
            while(L[i] < l) {
                add(A[--l]);
            }
            while(R[i] > r) {
                add(A[++r]);
            }
            while(L[i] > l) {
                rem(A[l++]);
            }
            while(R[i] < r) {
                rem(A[r--]);
            }
            ans[i] = a;
        }
        while(r >= l) {
            rem(A[r--]);
        }
    }
    for(LL& a : ans) {
        cout << a << '\n';
    }
}