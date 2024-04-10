#include <bits/stdc++.h>

using namespace std;

int h[100002];
vector<pair<int, int> > v;
struct node
{
    int pr, sf, rng, len;
    node() : node(0, 0, 0, 0) {}
    node(int _p, int _s, int _r, int _l) : pr(_p), sf(_s), rng(_r), len(_l) {}
};

node tree[400002];

node add(node x, node y)
{
    node ret;
    ret.len = x.len + y.len;
    if(x.len == x.pr) ret.pr = x.len + y.pr;
    else ret.pr = x.pr;
    if(y.len == y.sf) ret.sf = y.len + x.sf;
    else ret.sf = y.sf;
    ret.rng = max(x.sf + y.pr, max(x.rng, y.rng));
    return ret;
}

void init(int i, int l, int r)
{
    if(l == r)
    {
        tree[i] = node(0, 0, 0, 1);
        return;
    }
    int m = (l + r)/2;
    init(i*2, l, m);
    init(i*2+1, m+1, r);
    tree[i] = add(tree[i*2], tree[i*2+1]);
}

void update(int i, int l, int r, int idx)
{
    if(l == r)
    {
        tree[i] = node(1, 1, 1, 1);
        return;
    }
    int m = (l + r)/2;
    if(idx <= m) update(i*2, l, m, idx);
    else update(i*2+1, m+1, r, idx);
    tree[i] = add(tree[i*2], tree[i*2+1]);
}

node query(int i, int l, int r, int s, int e)
{
    if(e <l || r < s) return node(0, 0, 0, 0);
    if(s <= l && r <= e) return tree[i];
    int m = (l + r)/2;
    return add(query(i*2, l, m, s, e), query(i*2+1, m+1, r, s, e));
}

int l[100002], r[100002];
int ql[100002], qr[100002], w[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> h[i];
        v.push_back({h[i], i});
    }
    sort(v.rbegin(), v.rend());
    int q; cin >> q;
    for(int i=1;i<=q;i++)
    {
        cin >> ql[i] >> qr[i] >> w[i];
        l[i] = 0, r[i] = n-1;
    }

    while(true)
    {
        vector<vector<int>> mid;
        mid.resize(n);
        bool flag = true;
        for(int i=1;i<=q;i++)
        {
            if(l[i] == r[i]) continue;
            mid[(l[i]+r[i])/2].push_back(i);
            flag = false;
        }

        if(flag) break;

        init(1, 1, n);
        for(int i=0;i<n;i++)
        {
            update(1, 1, n, v[i].second);
            for(int j : mid[i])
            {
                if(query(1, 1, n, ql[j], qr[j]).rng < w[j]) l[j] = i+1;
                else r[j] = i;
            }
        }
    }

    for(int i=1;i<=q;i++)
    {
        cout << v[l[i]].first << "\n";
    }
}