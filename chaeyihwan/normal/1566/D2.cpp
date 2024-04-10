#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1000000;

struct pi
{
    int x, y, z;
};

vector<int> v;
int a[90002];
int cnt[100002];
int T[90002], lazy[360002];
pair<int, int> tree[360002];
int n, m;
pair<int, int> f(pair<int, int> x, pair<int, int> y)
{
    if(x.first > 10000) return y;
    if(y.first > 10000) return x;
    if((x.second -1)/m == (y.second - 1)/m)
    {
        if(x.first < y.first) return x;
        else return y;
    }
    return x;
}
void init(int i, int l, int r)
{
    lazy[i] = 0;
    if(l == r)
    {
        tree[i] = {T[l], l};
        return;
    }
    int mid = (l + r)/2;
    init(i*2, l, mid);
    init(i*2+1, mid+1, r);
    tree[i] = f(tree[i*2], tree[i*2+1]);
}

void propagate(int i, int l, int r)
{
    tree[i].first += lazy[i];
    if(l != r)
    {
        lazy[i*2] += lazy[i];
        lazy[i*2+1] += lazy[i];
    }
    lazy[i] = 0;
}

pair<int, int> query(int i, int l, int r, int s, int e)
{
    propagate(i, l, r);
    if(e < l || r < s) return {INF, 0};
    if(s <= l && r <= e) return tree[i];
    int mid = (l + r)/2;
    return f(query(i*2, l, mid, s, e), query(i*2+1, mid+1, r, s, e));
}

void update(int i, int l, int r, int s, int e, int v)
{
    if(e < s) return;
    propagate(i, l, r);
    if(e < l || r < s) return;
    if(s <= l && r <= e)
    {
        lazy[i] += v;
        propagate(i, l, r);
        return;
    }
    int mid = (l + r)/2;
    update(i*2, l, mid, s, e, v);
    update(i*2+1, mid+1, r, s, e, v);
    tree[i] = f(tree[i*2], tree[i*2+1]);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        v.clear();
        for(int i=1;i<=n*m;i++)
        {
            cin >> a[i];
            v.push_back(a[i]);
            cnt[i] = 0;
        }
        sort(v.begin(), v.end());
        for(int i=1;i<=n*m;i++)
        {
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            a[i]++;
            cnt[a[i]]++;
        }

        for(int i=1;i<=n*m;i++) T[i] = (n*m - i)%m;
        for(int i=1;i<=n*m;i++) cnt[i] += cnt[i-1];

        init(1, 1, n*m);

        ll ans = 0;

        for(int i=1;i<=n*m;i++)
        {
            int L = cnt[a[i]-1] + 1, R = cnt[a[i]];
            pair<int, int> p = query(1, 1, n*m, L, R);
            ans += p.first;
            update(1, 1, n*m, p.second, p.second, INF);
            int X = p.second%m;
            if(X == 0) X = m;
            if(X == 1) continue;
            update(1, 1, n*m, (p.second - X + 1), p.second - 1, -1);
        }
        cout << ans << "\n";
    }
}