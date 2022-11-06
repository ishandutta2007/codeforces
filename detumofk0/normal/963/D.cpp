#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long mod = 1000025171;

int ans[N];
int freq[N];
long long hs[N];
long long pw[N];
deque < int > pos[N];
vector < pair < long long, int > > queries[N];

long long getHash(int x, int y) {
    return (hs[y] - hs[x - 1] * pw[y - x + 1] + mod * mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp", "r")) freopen("1.inp", "r", stdin);

    string s; cin >> s;
    int n; cin >> n;

    s = " " + s;
    pw[0] = 1;

    for(int i = 1; i < s.size(); ++i) {
        pw[i] = pw[i - 1] * 27 % mod;
        hs[i] = (hs[i - 1] * 27 + s[i] - 'a') % mod;
    }

    for(int i = 1; i <= n; ++i) {
        cin >> freq[i];
        string r; cin >> r;
        long long hash_ = 0;
        for(auto &c : r) hash_ = (hash_ * 27 + c - 'a') % mod;
        queries[r.size()].emplace_back(hash_, i);
    }

    memset(ans, 60, sizeof ans);

    for(int len = 1; len < s.size(); ++len) {
        if(queries[len].size() == 0) continue;
        sort(queries[len].begin(), queries[len].end());
        for(int i = len; i < s.size(); ++i) {
            long long w = getHash(i - len + 1, i);
            int fpos = lower_bound(queries[len].begin(), queries[len].end(), make_pair(w, -1)) - queries[len].begin();
            if(fpos == queries[len].size() || queries[len][fpos].first != w) continue;
            int id = queries[len][fpos].second;
            pos[fpos].push_back(i);
            if(pos[fpos].size() > freq[id]) pos[fpos].pop_front();
            if(pos[fpos].size() == freq[id]) ans[id] = min(ans[id], pos[fpos].back() - pos[fpos].front() + len);

        }
        for(int i = 0; i < queries[len].size(); ++i) {
            pos[i].clear();
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << (ans[i] > s.size() ? -1 : ans[i]) << "\n";
    }

    return 0;
}