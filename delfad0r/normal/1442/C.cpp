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

constexpr int MOD = 998244353, INF = 1 << 30;

struct pq_t {
    int x, y, n;
    
    bool operator < (const pq_t& other) const {
        return (y < other.y) or ((y == other.y) and (x < other.x));
    }
    bool operator > (const pq_t& other) const {
        return (y > other.y) or ((y == other.y) and (x > other.x));
    }
};


int dp[22][200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N), GT(N);
    while(M--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        GT[v].push_back(u);
    }
    
    {
        struct pq_t {
            int n, k, d;
        };
        auto cmp = [](const auto& x, const auto& y) {
            return x.d > y.d;
        };
        priority_queue<pq_t, vector<pq_t>, decltype(cmp)> PQ(cmp);
        array<vector<int>, 20> dist;
        array<vector<bool>, 20> visited;
        dist.fill(vector<int>(N, INF));
        dist[0][0] = 0;
        visited.fill(vector<bool>(N, false));
        PQ.push({ 0, 0, 0 });
        while(PQ.size()) {
            auto [n, k, d] = PQ.top();
            //~ cerr << n << " " << k << " " << d << endl;
            PQ.pop();
            if(visited[k][n]) {
                continue;
            }
            visited[k][n] = true;
            if(n == N - 1) {
                cout << d << "\n";
                return 0;
            }
            auto& myG = (k % 2 == 0) ? (G) : (GT);
            for(int x : myG[n]) {
                if(not visited[k][x] and dist[k][x] > d + 1) {
                    PQ.push({ x, k, dist[k][x] = d + 1 });
                }
            }
            if(k < 19 and not visited[k + 1][n] and dist[k + 1][n] > d + (1 << k)) {
                PQ.push({ n, k + 1, dist[k + 1][n] = d + (1 << k) });
            }
        }
    }
    {
        struct pq_t {
            int n;
            pair<int, int> d;
        };
        auto cmp = [](const auto& x, const auto& y) {
            return x.d > y.d;
        };
        priority_queue<pq_t, vector<pq_t>, decltype(cmp)> PQ(cmp);
        array<vector<pair<int, int>>, 2> dist;
        array<vector<bool>, 2> visited;
        dist.fill(vector<pair<int, int>>(N, { INF, INF }));
        dist[0][0] = { 0, 0 };
        visited.fill(vector<bool>(N, false));
        PQ.push({ 0, { 0, 0 } });
        while(PQ.size()) {
            auto [n, d] = PQ.top();
            auto [k, t] = d;
            PQ.pop();
            if(visited[k % 2][n]) {
                continue;
            }
            visited[k % 2][n] = true;
            if(n == N - 1) {
                LL ans = 1;
                while(k--) {
                    ans = (ans * 2) % MOD;
                }
                ans = (ans + MOD - 1 + t) % MOD;
                cout << ans << "\n";
                return 0;
            }
            auto& myG = (k % 2 == 0) ? (G) : (GT);
            for(int x : myG[n]) {
                if(not visited[k % 2][x] and dist[k % 2][x] > pair(k, t + 1)) {
                    PQ.push({ x, dist[k % 2][x] = { k, t + 1 } });
                }
            }
            if(not visited[(k + 1) % 2][n] and dist[(k + 1) % 2][n] > pair(k + 1, t)) {
                PQ.push({ n, dist[(k + 1) % 2][n] = { k + 1, t } });
            }
        }
    }
    
    abort();
    
    
    return 0;
}