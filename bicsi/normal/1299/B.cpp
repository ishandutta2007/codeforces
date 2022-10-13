#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, int>> P;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        P.emplace_back(x, y);
    }

    auto Q = P;
    for (int i = 0; i < n; ++i) {
        Q[i].first *= -1;
        Q[i].second *= -1;
    }

    // reverse(Q.begin(), Q.end());
    auto norm = [&](vector<pair<int, int>>& P) {
        auto it = min_element(P.begin(), P.end());
        rotate(P.begin(), it, P.end());
    };
    norm(P); norm(Q);

    Q.push_back(Q.front());
    P.push_back(P.front());

    auto cross = [&](pair<int, int> a, pair<int, int> b, pair<int, int> c, 
            pair<int, int> d) {
        b.first -= a.first; b.second -= a.second;
        d.first -= c.first; d.second -= c.second;
        return 1LL * b.first * d.second - 1LL * b.second * d.first;
    };
    /*
    for (int i = 0; i < n; ++i) {
        cerr << P[i].first << " " << P[i].second << endl;
    }

    cerr << endl;
    for (int i = 0; i < n; ++i) {
        cerr << Q[i].first << " " << Q[i].second << endl;
    }
    cerr << endl;
    */
    int i = 0, j = 0;
    vector<pair<int, int>> R;
    auto push = [&](pair<int, int>& p) {
        if (R.size() >= 2) {
            auto last = R[R.size() - 1], last2 = R[R.size() - 2];
            if (cross(last2, last, p, last) == 0) {
                R.back().first = p.first;
                R.back().second = p.second;
                return;
            }
        }
        R.push_back(p);
    };
    R.emplace_back(P[0].first + Q[0].first, P[0].second + Q[0].second);
    while (i < n || j < n) {
        auto p = R.back();
        if (i == n || cross(P[i], P[i + 1], Q[j], Q[j + 1]) < 0) {
            ++j;
            p.first += Q[j].first - Q[j - 1].first;
            p.second += Q[j].second - Q[j - 1].second;
            push(p);
        } else {
            ++i;
            p.first += P[i].first - P[i - 1].first;
            p.second += P[i].second - P[i - 1].second;
            push(p);
        }
    }
    /*
    for (auto p : R) {
        cerr << p.first << " " << p.second << '\n';
    }
    */

    auto Norm = [&](pair<int, int> a, pair<int, int> b) {
        b.first -= a.first;
        b.second -= a.second;
        return 1LL * b.first * b.first + 1LL * b.second * b.second;
    };

    auto Similar = [&](vector<pair<int, int>>& A, vector<pair<int, int>>& B) {
        if (A.size() != B.size()) return false;
        auto n1 = Norm(A[0], A[1]), n2 = Norm(B[0], B[1]);
        auto gc = __gcd(n1, n2);
        n1 /= gc; n2 /= gc;
        for (int i = 0; i < n; ++i) {
            if (cross(A[i], A[i + 1], B[i], B[i + 1]))
                return false;
            auto n1p = Norm(A[i], A[i + 1]), n2p = Norm(B[i], B[i + 1]);
            auto gcp = __gcd(n1p, n2p);
            n1p /= gcp; n2p /= gcp;
            if (n1p != n1 || n2p != n2)
                return false;
        }
        return true;
    };
    // cerr << R.size() << endl;
    //assert(R.front() == R.back());

    if (Similar(P, R)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}