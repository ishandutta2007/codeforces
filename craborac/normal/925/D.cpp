//
// Created by demon1999 on 27.04.18.
//

#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef unsigned long long ull;

const int ma = 4 * 128 * 1024;
int n, m, dst[ma], pr[ma], ans = int(1e9), uses[ma], cnt1, cnt2;
vector<int> e[ma], nq;
map<int, int> use[ma];

void dfs(int nu) {
    uses[nu] = 1;
    cnt1++;
    nq.push_back(nu);
    cnt2 += sz(e[nu]) - 1;
    for (int v : e[nu]) {
        if (v && uses[v] == 0) {
            dfs(v);
        }
    }
}

void find_ans() {
    cout << 5 << "\n";
    vector<int> path;
    forn(i, sz(nq)) {
        for (int j = i + 1; j < sz(nq); j++) {
            if (use[nq[i]][nq[j]] == 0) {
                path.push_back(nq[i]);
                break;
            }
        }
        if (sz(path)) break;
    }
    forn (i, n) dst[i] = int(1e9);
    dst[path[0]] = 0;
    queue<int> qq;
    qq.push(path[0]);
    while (!qq.empty()) {
        int nu = qq.front();
        qq.pop();
        for (int v : e[nu]) {
            if (v != 0 && dst[v] > dst[nu] + 1) {
                dst[v] = dst[nu] + 1;
                pr[v] = nu;
                qq.push(v);
            }
        }
    }
    forn (i, n) {
        if (dst[i] == 2) {
            path.push_back(pr[i]);
            path.push_back(i);
            break;
        }
    }
    cout << "1 " << path[0] + 1 << " " << path[1] + 1 << " " << path[2] + 1 << " " << path[0] + 1 << " " << n << "\n";
}

int main() {
    iostream::sync_with_stdio(0);
    cin >> n >> m;
    forn (i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
        use[a][b] = use[b][a] = 1;
    }
    queue<int> qq;
    qq.push(0);
    forn (i, n) {
        dst[i] = int(1e9);
    }
    dst[0] = 0;
    int ps = -1;
    while (!qq.empty()) {
        int nu = qq.front();
        qq.pop();
        for (int v : e[nu]) {
            if (dst[v] > dst[nu] + 1) {
                qq.push(v);
                dst[v] = dst[nu] + 1;
                pr[v] = nu;
            }
        }
    }
    if (dst[n - 1] < 4) {
        vector<int> nums;
        int nu = n - 1;
        while (true) {
            nums.push_back(nu);
            if (nu == 0) break;
            nu = pr[nu];
        }
        reverse(nums.begin(), nums.end());
        cout << sz(nums) - 1 << "\n";        
        for (int v : nums) {
            cout << v + 1 << " ";
        }
        cout << "\n";
        return 0;
    }
    forn (i, n) {
        if (dst[i] == 2) {
            cout << 4 << "\n";
            cout << 1 << " " << pr[i] + 1 << " " << i + 1 << " " << 1 << " " << n << "\n";
            return 0;
        }
    }
    vector<int> nms;
    forn (i, n) {
        if (dst[i] == 1) nms.push_back(i);
    }
    for (int i : nms) {
        if (uses[i] == 0) {
            cnt1 = cnt2 = 0;
            nq.resize(0);
            dfs(i);
            if (ll(cnt1) * (ll(cnt1) - 1) != cnt2) {
                find_ans();
                return 0;
            }
        }
    }
    cout << "-1";
    return 0;
}