#include "bits/stdc++.h"

#define all_of(x) std::begin(x), std::end(x)
#ifdef _GLIBCXX_DEBUG
    #define debug(x) cerr << #x << ": " << x << endl
#else
    #define debug(x) 
#endif

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for(auto& x : v) {
        in >> x;
    }
    return in;
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

vector<pair<LL, LL>> solve(const vector<int>& A, int b) {
    if(A.empty()) {
        return vector<pair<LL, LL>>(b + 1, {0, 0});
    }
    //~ cerr << A << b << endl;
    vector<int> A0, A1;
    int cnt0 = 0, cnt1 = 0;
    LL ans0 = 0, ans1 = 0;
    int mask = 1 << b;
    for(int n = 0; n < int(A.size()); ++n) {
        if(A[n] & mask) {
            ans1 += cnt0;
            ++cnt1;
            A1.push_back(A[n]);
        } else {
            ans0 += cnt1;
            ++cnt0;
            A0.push_back(A[n]);
        }
    }
    if(b == 0) {
        return {{ans0, ans1}};
    } else {
        auto x = solve(A0, b - 1), y = solve(A1, b - 1);
        vector<pair<LL, LL>> ans;
        for(int i = 0; i < b; ++i) {
            ans.emplace_back(x[i].first + y[i].first, x[i].second + y[i].second);
        }
        ans.emplace_back(ans0, ans1);
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    auto v = solve(A, 30);
    LL ans = 0;
    int x = 0;
    for(int b = 0; b <= 30; ++b) {
        if(v[b].second < v[b].first) {
            ans += v[b].second;
            x |= (1 << b);
        } else {
            ans += v[b].first;
        }
    }
    cout << ans << " " << x << "\n";
    
    return 0;
}