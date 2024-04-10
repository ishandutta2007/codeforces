#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
vector<vector<int>> g;
vector<int>a;
int n;
bool used[200005];
int mx = -1;
vector<int> ans(200005);
void dfs(int v)
{
    used[v] = 1;
    mx = max(a[v], mx);
    ans[v] = mx;
    for(auto u : g[v])
    {
        if(!used[u])
        {
            
            mx = max(a[u] , mx);
            ans[u] = mx;
            dfs(u);
        }
    }
    if(g[v].size() == 0)
    {
        mx = -1;
    }
}
bool solve1(ll l ,ll r ,ll x ,ll y ,ll k)
{
    
    long long mn = (l + k - 1) / k;
    long long mx = r / k;
    if (mn > y || mx < x)
    {
        return 0;
    }
    else {
        return 1;
    }
    
}
bool solve2(int l ,int r ,int x ,int y ,int k)
{
    bool flag = 0;
    for(int i = x; i <= y; i++)
    {
        ll tmp = (ll) i * k;
        if(tmp >= l && tmp <= r) flag = 1;
    }
    return  flag;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(0);
    cout.tie(0);
    ll l , r , x , y , k;
    cin >> l >> r >> x >> y >> k;
    if(solve2(l, r, x, y, k))
    {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}