#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

const int maxn = int(4e5);
int n;
ll ans, cnt1;
ll cnt[maxn][2], szz[maxn], sum;
vector<int> e[maxn];

void dfs(int nu, int  p) {
    cnt[nu][0] = 1;
    szz[nu] = 1;
    for (int v : e[nu]) {
        if (v != p) {
            dfs(v, nu);
            cnt1 += cnt[nu][1] * cnt[v][1];
            cnt1 += cnt[nu][0] * cnt[v][0];
            cnt[nu][1] += cnt[v][0];
            cnt[nu][0] += cnt[v][1];
            szz[nu] += szz[v]; 
            ans += szz[v] * ll(n - szz[v]);
        }
    }
}
int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    forn (i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0, -1);
    cout << (ans - cnt1) / 2LL + cnt1; 
    return 0;
}