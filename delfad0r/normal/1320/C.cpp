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

int rt_s[1 << 21], rt_mps[1 << 21];

void point_update(int w, int v) {
    w += 1 << 20;
    rt_s[w] += v;
    rt_mps[w] += v;
    while(w >>= 1) {
        rt_s[w] = rt_s[2 * w] + rt_s[2 * w + 1];
        rt_mps[w] = max(rt_mps[2 * w], rt_s[2 * w] + rt_mps[2 * w + 1]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int N, M, P;
    cin >> N >> M >> P;
    vector<pair<int, int>> A;
    for(int n = 0; n < N; ++n) {
        int a, ca;
        cin >> a >> ca;
        A.emplace_back(a, ca);
    }
    A.emplace_back(0, 0);
    vector<pair<int, int>> B;
    for(int m = 0 ; m < M; ++m) {
        int b, cb;
        cin >> b >> cb;
        B.emplace_back(b, cb);
    }
    sort(A.begin(), A.end(), [&](auto& x, auto& y) { return x.first < y.first or (x.first == y.first and x.second > y.second); });
    for(int n = N - 1, m = A[N].second; n >= 0; --n) {
        m = min(A[n].second, m);
        A[n].second = m;
    }
    for(int n = 1; n <= N; ++n) {
        point_update(A[n - 1].first, A[n - 1].second - A[n].second);
    }
    sort(B.begin(), B.end(), [&](auto& x, auto& y) { return x.first < y.first; });
    vector<tuple<int, int, int>> C;
    for(int p = 0; p < P; ++p) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x < A[N].first) {
            C.emplace_back(x, y, z);
        }
    }
    sort(C.begin(), C.end(), [&](auto& x, auto& y) { return get<1>(x) > get<1>(y); });
    int ans = -A[1].second - B[0].second;
    for(auto& b : B) {
        while(C.size() and get<1>(C.back()) < b.first) {
            point_update(get<0>(C.back()), get<2>(C.back()));
            C.pop_back();
        }
        ans = max(ans, rt_mps[1] - b.second);
    }
    
    cout << ans << "\n";
    
    
    return 0;
}