#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

struct node
{
    int pf, sf, psum, ssum, rsum;
    node() : node(0, 0, 0, 0, 0) {}
    node(int a, int b, int c, int d, int e) : pf(a), sf(b), psum(c), ssum(d), rsum(e) {}
};

node add(node x, node y)
{
    node ret;
    ret.psum = x.psum + y.psum;
    ret.ssum = x.ssum + y.ssum;
    ret.rsum = min(x.rsum + y.ssum, y.rsum + x.psum);
    ret.pf = min(x.pf, x.psum + y.pf);
    ret.sf = min(y.sf, y.ssum + x.sf);
    ret.rsum = min(ret.rsum, x.pf + y.sf);
    return ret;
}

node tree[400002];
string s;

void init(int i, int l, int r)
{
    if(l == r)
    {
        if(s[l] == 'a') tree[i] = node(0, 0, 1, 0, 0);
        if(s[l] == 'b') tree[i] = node(-1, -1, -1, -1, -1);
        if(s[l] == 'c') tree[i] = node(0, 0, 0, 1, 0);
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
        if(s[l] == 'a') tree[i] = node(0, 0, 1, 0, 0);
        if(s[l] == 'b') tree[i] = node(-1, -1, -1, -1, -1);
        if(s[l] == 'c') tree[i] = node(0, 0, 0, 1, 0);
        return;
    }
    int m = (l + r)/2;
    if(idx <= m) update(i*2, l, m, idx);
    else update(i*2+1, m+1, r, idx);
    tree[i] = add(tree[i*2], tree[i*2+1]);
}

int query()
{
    return tree[1].rsum;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<n;i++) if(s[i] == 'b') cnt++;
    init(1, 0, n-1);
    for(int i=1;i<=q;i++)
    {
        int pos; char c;
        cin >> pos >> c;
        pos--;
        if(s[pos] == 'b') cnt--;
        if(c == 'b') cnt++;
        s[pos] = c;
        update(1, 0, n-1, pos);
        cout << cnt + min(0, query()) << "\n";
    }
}