#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int QUERY(const vector<int>& a, int s = 1) {
    cout << "? ";
    for (int i = s, n = a.size(); i < n; i++) {
        cout << a[i] << " \n"[i + 1 == n];
    }
    cout.flush();
    int k;
    cin >> k;
    return k;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N;

    // Is there really any necessity for 1<=a<=n? ...
    if (N == 2) {
        int a = QUERY({0, 1, 2});
        if (a != 0) {
            cout << "! 2 1" << endl;
        } else {
            cout << "! 1 2" << endl;
        }
        return 0;
    }

    vector<int> a(N + 1, 2);
    vector<int> positive(N + 1, 0);
    vector<int> negative(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        a[i] = 3;
        positive[i] = QUERY(a);
        a[i] = 1;
        negative[i] = QUERY(a);
        a[i] = 2;
    }
    // 2N queries

    vector<int> pi(N + 1);
    vector<int> next(N + 1, 0);

    // First, find 1 and N
    int one = 0;
    for (int i = 1; i <= N; i++) {
        if (positive[i] == 0) {
            pi[i] = N;
        }
        if (negative[i] == 0) {
            pi[i] = 1;
            one = i;
        }
    }
    // Now find next for every position
    for (int i = 1; i <= N; i++) {
        if (positive[i] && positive[i] != i) {
            next[i] = positive[i];
        }
        if (negative[i] && negative[i] != i) {
            next[negative[i]] = i;
        }
    }
    for (int n = 2, i = one; n < N; n++) {
        assert(i != 0);
        pi[next[i]] = n;
        i = next[i];
    }

    cout << "! ";
    for (int i = 1; i <= N; i++) {
        cout << pi[i] << " \n"[i == N];
    }
    cout.flush();

    return 0;
}