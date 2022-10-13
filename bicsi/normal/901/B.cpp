#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<int> Trans(vector<int> A, vector<int> B) {
    A.insert(A.begin(), 0);
    for (int i = 0; i < (int)B.size(); ++i)
        A[i] += B[i];
    return A;
}

pair<vector<int>, vector<int>> Try(int n, vector<int> A, vector<int> B) {

    for (int i = 2; i <= n; ++i) {
        vector<int> C;
        bool bad = true;
        for (int it = 0; it < 2; ++it) {
            C = Trans(A, B);
            bad = false;
            for (auto x : C)
                if (x < -1 or x > 1) bad = true;
            if (!bad) break;
            
            for (auto& x : A) x = -x;
        }
        if (bad) return {{}, {}};
        B = A; A = C;
    }
    return {A, B};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    for (int c = 0; c < 4; ++c) {
        vector<int> A = {0}, B;
        if (c % 2) A.push_back(1);
        else A.push_back(-1);
        if (c / 2) B.push_back(1);
        else B.push_back(-1);

        tie(A, B) = Try(n, A, B);
        bool ok = true;
        if (A.empty() or B.empty()) ok = false;

        for (auto x : A) {
            ok &= (x >= -1 && x <= 1);
        }
        for (auto x : B) {
            ok &= (x >= -1 && x <= 1);
        }
        ok &= A.back() == 1;
        ok &= B.back() == 1;

        if (ok) {
            cout << A.size() - 1 << endl;
            for (auto x : A) cout << x << " "; cout << endl;
            cout << B.size() - 1<< endl;
            for (auto x : B) cout << x << " "; cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}