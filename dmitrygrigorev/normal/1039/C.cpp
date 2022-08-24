#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > Data;
int MOD = 1000000007;
struct Snm{int f; int r;};
vector<Snm> snm;
int get(int v){
    if (snm[v].f == v) return v;
    snm[v].f = get(snm[v].f);
    return snm[v].f;
}
int un(int a, int b){
    if (snm[a].r < snm[b].r) swap(a, b);
    if (snm[a].r == snm[b].r) snm[a].r++;
    snm[b].f = a;
}
int st(int a, int b){
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2==0){
        int rs = st(a, b/2);
        return (rs*rs) % MOD;
    }
    return (a*st(a, b-1)) % MOD;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) {
        vector<int> h;
        Data.push_back(h);
    }
    map<int, vector<pair<int, int> > > ms;
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        Data[a-1].push_back(b-1);
        Data[b-1].push_back(a-1);
        int X = v[a-1] ^ v[b-1];
        if (!ms.count(X)) ms[X] = {};
        ms[X].push_back({a-1, b-1});
    }
    for (int i=0; i < n; i++) snm.push_back({i, 1});
    int fr = (1LL<<k);
    int ans = 0;
    while (ms.size()){
        auto it = ms.begin();
        int hr = (*it).first;
        vector<pair<int, int> > bb = (*it).second;
        ms.erase(it);
        int cmp = n;
        for (int i=0; i < bb.size(); i++){
            int a = bb[i].first, b = bb[i].second;
            if (get(a) == get(b)) continue;
            cmp--;
            un(get(a), get(b));
        }
        for (int i=0; i < bb.size(); i++){
            int a = bb[i].first, b = bb[i].second;
            snm[a] = {a, 1};
            snm[b] = {b, 1};
        }
        fr--;
        ans += st((int)2 , cmp);
    }
    fr %= MOD;
    int ss = st((int)2, n);
    ans += ss*fr;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans;
    
}