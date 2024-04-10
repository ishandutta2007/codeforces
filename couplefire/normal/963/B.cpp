#include <bits/stdc++.h>
using namespace std;
#define MAXN 256
typedef long long ll;
ll n;
map<ll, vector<ll> > t;
map<ll, ll> s;
vector<ll> r;
ll i, x;
 
void dfss(ll x)
{
    s[x] = 1;
    for (auto p: t[x]) dfss(p), s[x] += s[p];
}
 
void dfs(ll x)
{
    for (auto p: t[x]) if (s[p] & 1 ^ 1) dfs(p);
    printf("%lld ", x + 1);
    for (auto p: t[x]) if (s[p] & 1) dfs(p);
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%lld", &n);
    if (n & 1)
    {
        puts("YES");
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            t[x - 1].push_back(i);
        }
        ll root = t[-1][0];
        dfss(root);
        dfs(root);
    }
    else puts("NO");
    return 0;
}