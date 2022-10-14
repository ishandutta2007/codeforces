#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

int N;

int QUERY(int i, int j) {
    cout << "?" << ' ' << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

auto solve() {
    cin >> N;
    vector<int> q0i(N), qi0(N);
    for (int i = 0; i < N; i++) {
        q0i[i] = QUERY(0, i);
        qi0[i] = QUERY(i, 0);
    }

    vector<int> permutation;
    int many = 0;

    for (int n = 0; n < N; n++) { // iterate over possible values of p0
        vector<int> pi(N), bi(N);
        for (int i = 0; i < N; i++) {
            bi[i] = q0i[i] ^ n;
            pi[i] = qi0[i] ^ bi[0];
        }
        bool ok = true;
        for (int i = 0; i < N && ok; i++) {
            ok = pi[bi[i]] == i;
        }

        if (ok) {
            if (permutation.empty()) {
                permutation = pi;
            }
            many++;
        }
    }

    cout << "!" << '\n' << many << '\n';
    for (int i = 0; i < N; i++) {
        cout << permutation[i] << ' ';
    }
    cout << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}