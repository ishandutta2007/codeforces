
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
const int N =  4e5 + 5;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;
vector<int> g[N];
int timer = 0;
int tin[N];
int tout[N];
void dfs(int v)
{
    tin[v] = timer++;
    for(auto u : g[v])
        dfs(u);
    tout[v] = timer - 1;
}
int a[4 * N ];
bool keep[4 * N];
int t[4 * N];
void init(int v , int l , int r)
{
  if(l == r)
  {
      a[v] = t[l];
  }
    else
  {
      init(2 * v, l, (l + r) / 2);
      init(2 * v + 1, (l + r) / 2 + 1, r);
      a[v] = a[2 * v] + a[2 * v + 1];
  }
        
}

int A, B;

void push(int i, int l, int r)
{
    if (keep[i])
    {
        int mid = (l + r) / 2;
        keep[2 * i] ^= keep[i];
        a[2 * i] = (mid - l + 1) - a[2 * i];
        keep[2 * i + 1] ^= keep[i];
        a[2 * i + 1] = (r - mid) - a[2 * i + 1];
        keep[i] = 0;
        a[i] = a[2 * i] + a[2 * i + 1];
    }
     a[i] = a[2 * i] + a[2 * i + 1];
    
}

void add(int i, int l, int r)
{
    if (l > B || r < A) return;
    if (l >= A && r <= B)
    {
        keep[i] ^= 1;
        a[i] = (r - l + 1) - a[i];
        return;
    }
    push(i, l, r);
    add(2 * i, l, (l + r) / 2);
    add(2 * i + 1, (l + r) / 2 + 1, r);
    a[i] = a[2 * i ] + a[2 * i + 1];
}

int sum(int i, int l, int r)
{
    if (l > B || r < A)
        return 0;
    if (l >= A && r <= B)
    {
        return a[i];
    }
    push(i, l, r);
    return sum(2 * i, l, (l + r) / 2) + sum(2 * i + 1, (l + r) / 2 + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        cin >> t[tin[i]];
    }
    init(1, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s[0] == 'g')
        {
            int v;
            cin >> v;
            v--;
            A = tin[v];
            B = tout[v];
            
            cout << sum(1, 0, n - 1) << "\n";
        }
        else
        {
            int v;
            cin >> v;
            v--;
            A = tin[v];
            B = tout[v];
            add(1, 0, n - 1);
        }
    }
    return 0;
}