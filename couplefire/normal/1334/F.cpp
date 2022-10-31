#include<bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define int long long
 
typedef long long ll;
 
const int maxn = 5e5+10;
const int mod = 1e9+7;
const ll inf = 1e16;
 
ll seg[maxn<<2], la[maxn<<2], n , m;
 
void shift(int v)
{
    seg[v] += la[v];
    if(v < (maxn<<1))
    {
        la[v<<1] += la[v];
        la[v<<1|1] += la[v];
    }
    la[v] = 0;
}
 
void up(int l, int r, ll val, int v = 1, int tl = 1, int tr = m)
{
    if(tl == l && tr == r)
    {
        la[v] += val;
        shift(v);
        return;
    }
 
    shift(v);
    if(l > r) return;
 
    int tm = (tl + tr) >> 1;
    up(l, min(tm,r), val, v<<1, tl, tm);
    up(max(tm+1,l), r, val, v<<1|1, tm+1, tr);
 
    seg[v] = min(seg[v<<1], seg[v<<1|1]);
}
 
ll sm = 0;
ll qu(int pos, int v = 1, int tl = 1, int tr = m)
{
    shift(v);
    if(pos == 0) return sm;
    if(tl == tr) return seg[v];
 
    int tm = (tl + tr) >> 1;
    if(pos <= tm) return qu(pos, v<<1, tl, tm);
    else return qu(pos, v<<1|1, tm+1, tr);
}
 
int a[maxn], p[maxn], b[maxn];
 
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   
    fill(seg, seg+4*maxn, inf);
 
    cin>> n;
    for(int i = 1; i <= n; i++) cin>> a[i];
    for(int i = 1; i <= n; i++) cin>> p[i];
    cin>> m;
    for(int i = 1; i <= m; i++) cin>> b[i];
 
    for(int i = 1; i <= n; i++)
    {
        int x = lower_bound(b+1, b+m+1, a[i]) - b;
        int x1 = x;
        if(b[x] == a[i])
        {
            x1++;
            up(x, x, min({qu(x-1), qu(x)+p[i], qu(x)})-qu(x));
        }
 
        if(p[i] < 0)
            up(x1, m, p[i]);
        up(1, x-1, p[i]);
        sm += p[i];
    }
 
    ll X = qu(m);
    if(X > (1e15+10))
        return cout<<"NO", 0;
    cout<<"YES\n"<< X;
}