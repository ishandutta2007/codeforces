#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int p[5002], inv[5002];
int cnt[5002];

int T[20002];
void init(int i, int l, int r)
{
    T[i] = 0;
    if(l == r) return;
    int m = (l + r)/2;
    init(i*2, l, m);
    init(i*2+1, m+1, r);
}

int q(int i, int l, int r, int s, int e)
{
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return T[i];
    int m = (l + r)/2;
    return q(i*2, l, m, s, e) + q(i*2+1, m+1, r, s, e);
}

void upd(int i, int l, int r, int id, int v)
{
    if(l == r) { T[i] += v; return; }
    int m = (l + r)/2;
    if(id <= m) upd(i*2, l, m, id, v);
    else upd(i*2+1, m+1, r, id, v);
    
    T[i] = T[i*2] + T[i*2+1];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> p[i];
        for(int i=1;i<=n;i++) inv[p[i]] = i;
        init(1, 1, n);
        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            ll a = q(1, 1, n, inv[i]+1, n);
            for(int j=1;j<=n;j++) cnt[j] = 0;
            for(int j=1;j<inv[i];j++) cnt[p[j]]++;
            for(int j=1;j<=n;j++) cnt[j] += cnt[j-1];
            for(int j=inv[i]+1;j<=n;j++)
            {
                if(p[j] < i) a--;
                ll b = cnt[p[j]];
                ans += a * b;
            }
            upd(1, 1, n, inv[i], 1);
        }
        cout << ans << "\n";
    }
}