#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
//#include "optimization.h"
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N =  200005;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;
vector<int> g[N];
vector<int> gr[N];
int used[N];
ll ans = 0;
vector<int> order, component;
void dfs1 (int v)
{
    used[v] = true;
    for (auto i : g[v])
    {
        if (!used[i]) dfs1 (i);
    }
    order.push_back (v);
}
vector<vector<int>>comp;
void dfs2 (int v)
{
    used[v] = true;
    component.push_back (v);
    for (auto i : g[v])
        if (!used[i])
            dfs2 (i);
}
bool cmp (vector<int> a , vector<int> b)
{
    return a.size() > b.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int  n ;
    cin >> n ;
    vector<int> a(n);
    int need = 2;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        g[i].pb(a[i]);
        if(a[i] == i) need--;
        gr[a[i]].pb(i);
    }
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    for(int i = 0; i < n; i++) used[i] = 0;
    int p;
    vector<ll> t;
    for (int i=0; i<n; ++i)
    {
        int v = order[n - 1 - i];
        if (!used[v])
        {
            dfs2 (v);
            ans += 1LL *  component.size() * component.size();
            t.pb(component.size());
            comp.pb(component);
            component.clear();
       //     cout << "\n";
        }
    }
   // sort(comp.begin(), comp.end(), cmp);
    sort(t.rbegin() , t.rend());
    ll res = 0;
 //   for(int i = 0; i < t.size(); i++) cout << t[i] << " ";
  //  cout << "\n";
    if(t.size() >= 2)
    res += 1LL * (t[0] + t[1]) * (t[0] + t[1]);
    
    for(int i = 2; i < t.size(); i++)
    {
     //   cout << t[i] << " ";
        res += 1LL * t[i] * t[i];
    }
    
    
    cout << max(ans , res) << "\n";
    return 0;
}