#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

struct C_t {
    int a, t;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<C_t> C;
    vector<int> A(N), T(N);
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    for(int n = 0; n < N; ++n) {
        cin >> T[n];
    }
    for(int n = 0; n < N; ++n) {
        C.push_back(C_t{A[n], T[n]});
    }
    C.push_back(C_t{1010000000, 0});
    sort(C.begin(), C.end(), [&](auto& x, auto& y) { return x.a < y.a; });
    LL ans = 0;
    int a = C[0].a;
    LL sum = 0;
    multiset<LL> S;
    for(int n = 0; n <= N; ) {
        if(C[n].a == a) {
            //~ cerr << "inserting " << C[n].a << " " << C[n].t << endl;
            S.insert(-C[n].t);
            sum += C[n].t;
            ++n;
        } else {
            if(S.size()) {
                sum -= -*S.begin();
                //~ cerr << "removing " << -*S.begin() << endl;
                S.erase(S.begin());
                ans += sum;
            }
            if(S.size()) {
                ++a;
            } else {
                a = C[n].a;
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}