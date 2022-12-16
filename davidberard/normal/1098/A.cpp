#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 100100;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N;
vector<int> ch[NMAX];
int par[NMAX];
ll a[NMAX];
ll s[NMAX];
int dep[NMAX];

ll ans = 0;
bool bad;

ll dfs(int u, int d, ll sf) {
    if((s[u] == -1 && (d&1)) || (s[u] != -1 && !(d&1))) {
        bad = true;
        //cerr << " bad because of depth " << endl;
        return INF;
    }
    if(s[u] >= sf) {
        ans += s[u]-sf;
        sf = s[u];
    }
    else if(s[u] != -1) {
        bad = true;
    }
    ll mn = INF;
    for(auto& v : ch[u]) {
        mn = min(mn, dfs(v, d+1, sf));
    }
    if(s[u] == -1 && ch[u].size() != 0) {
        mn = mn-sf;
        ans -= ch[u].size()*mn;
        ans += mn;
    }
    return s[u];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i=2;i<=N;++i) {
        cin >> par[i];
        ch[par[i]].push_back(i);
    }
    for(int i=1;i<=N;++i) {
        cin >> s[i];
    }
    dfs(1,1,0);
    if(bad) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}