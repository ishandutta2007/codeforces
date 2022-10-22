#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;
const ll INF = 1e18;

int a[100002], b[100002], c[100002];
ll tree[400002];

ll init(int i, int l, int r){
    if(l == r) return tree[i] = 0;
    int m = (l + r)/2;
    return tree[i] = init(i*2, l, m) + init(i*2+1, m+1, r);
}

void update(int i, int l, int r, int id, ll val){
    if(l == r) { tree[i] = val; return; }
    int m = (l + r)/2;
    if(id <= m) update(i*2, l, m, id, val);
    else update(i*2+1, m+1, r, id, val);
    tree[i] = tree[i*2] + tree[i*2+1];
}

ll query(int i, int l, int r, int s, int e){
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return tree[i];
    int m = (l + r)/2;
    return query(i*2, l, m, s, e) + query(i*2+1, m+1, r, s, e);
}

void solve()
{
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for(int i=0;i<n;i++)
    {
        a[i] = s[i] - 'a';
        b[i] = t[i] - 'a';
        c[i] = a[i];
    }
    sort(c, c+n);
    bool flag = true;
    for(int i=0;i<n;i++)
    {
        if(c[i] < b[i]) { flag = false; break; }
        if(c[i] > b[i]) { cout << "-1\n"; return; }
    }
    if(flag) { cout << "-1\n"; return; }

    queue<int> q[26];
    for(int i=0;i<26;i++) while(!q[i].empty()) q[i].pop();
    for(int i=0;i<n;i++) q[a[i]].push(i);

    init(1, 0, n-1);
    ll ans = INF, now = 0;
    for(int i=0;i<n;i++)
    {
        int h = n;
        for(int j=0;j<b[i];j++)
        {
            if(!q[j].empty() && h > q[j].front())
            {
                h = q[j].front();
            }
        }
        if(h < n)
        {
            h += query(1, 0, n-1, h, n-1);
            ans = min(ans, h - i + now);
        }

        if(q[b[i]].empty()) break;
        int K = query(1, 0, n-1, q[b[i]].front(), n-1);
        update(1, 0, n-1, q[b[i]].front(), 1);

        now += q[b[i]].front() + K - i;

        q[b[i]].pop();
        if(now >= ans) break;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        solve();
    }
}