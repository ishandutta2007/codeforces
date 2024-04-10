#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Snm{int r; int f; int mn; int mx;};
vector<Snm> snm;
int get(int v){
    if (snm[v].f != v) snm[v].f = get(snm[v].f) ;
    return snm[v].f;
}
int total=0;
void unite(int a, int b){
    if (snm[a].r < snm[b].r) swap(a, b);
    snm[b].f = a;
    total -= (snm[b].mx - snm[b].mn);
    total -= (snm[a].mx - snm[a].mn);
    snm[a].mn = min(snm[a].mn, snm[b].mn);
    snm[a].mx = max(snm[a].mx, snm[b].mx);
    total += (snm[a].mx - snm[a].mn);
    if (snm[b].r == snm[a].r) snm[a].r++;
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<pair<int, int> > kek;
    for (int i=1; i < n; i++) kek.push_back({v[i]-v[i-1], i});
    sort(kek.begin(), kek.end());
    for (int i=0; i < n; i++) snm.push_back({1, i, v[i], v[i]});
    int m;
    cin >> m;
    vector<pair<int, int> > q;
    for (int i=0; i < m; i++){
        int l, r;
        cin >> l >> r;
        q.push_back({r-l+1, i});
    }
    sort(q.begin(), q.end());
    vector<int> ans(m);
    int tet = n;
    int u = 0;
    for (int i=0; i < m; i++){
        while (u < kek.size() && kek[u].first <= q[i].first){
            int a = get(kek[u].second-1), b = get(kek[u].second);
            if (a!=b){
                unite(a, b);
                tet--;
            }
            u++;
        }
        ans[q[i].second] = total + tet*q[i].first;
    }
    for (int i=0;i<m;i++) cout << ans[i] << " ";
}