#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()



int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int d = input<int>();
    int s = input<int>();

    vector<vector<pair<int,int>>> rgraph(d);

    for (int rem = 0; rem < d; ++rem)
        for (int dig = 0; dig < 10; ++dig)
            rgraph[(rem * 10 + dig) % d].emplace_back(dig, rem);

    queue<pair<int, int>> q;
    vector<vector<int>> dist(s + 1, vector<int>(d, TYPEMAX(int)));
    dist[s][0] = 0;

    q.emplace(s, 0);

    while (not q.empty()) {
        int sm = q.front().first;
        int rm = q.front().second;

        q.pop();

        for (auto go: rgraph[rm])
            if (sm >= go.first and dist[sm - go.first][go.second] > dist[sm][rm] + 1) {
                dist[sm - go.first][go.second] = dist[sm][rm] + 1;
                q.emplace(sm - go.first, go.second);
            }
    }

    if (dist[0][0] == TYPEMAX(int)) {
        cout << "-1\n";
        return 0;
    }
    
    string ans = "";
    int sm = 0;
    int rm = 0;

    while (make_pair(sm, rm) != make_pair(s, 0)) {
        bool ok = false;
        for (int dig = 0; dig < 10 and sm + dig <= s; ++dig) {
            int nsum = sm + dig;
            int nrm = (rm * 10 + dig) % d;

            if (dist[sm][rm] == dist[nsum][nrm] + 1) {
                sm = nsum;
                rm = nrm;
                ans += char('0' + dig);
                ok = true;
                break;
            }
        }

        assert(ok);
    }

    cout << ans << "\n";
    
    return 0;
}