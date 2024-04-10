
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define ll long long
#include <stdio.h>
#include <bits/stdc++.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

const int N = 300000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const ld eps = 1e-9;
const ld pi = atan2(0, -1);
const int ABC = 26;

vector<int> g[N];
bool used[N];
int ttt = 0;
int in[N], up[N];
vector<int> cur;
vector<pair<int, int> > restr;

void dfs(int u, int par)
{
    used[u] = true;
    in[u] = up[u] = ttt++;
    cur.push_back(u);
    for (int v : g[u])
        if (!used[v])
        {
            dfs(v, u);
            up[u] = min(up[u], up[v]);
            if (up[v] == in[v])
            {
                int mi = inf, ma = -inf;
                while (true)
                {
                    int w = cur.back();
                    cur.pop_back();
                    mi = min(mi, w);
                    ma = max(ma, w);
                    if (w == v)
                        break;
                }
                if (mi != ma)
                    restr.push_back({mi, ma});
            }
        }
        else if (v != par)
        {
            up[u] = min(up[u], in[v]);
        }
    if (par == -1)
    {
        int mi = inf, ma = -inf;
        while (sz(cur) > 0)
        {
            int w = cur.back();
            cur.pop_back();
            mi = min(mi, w);
            ma = max(ma, w);
        }
        if (mi != ma)
            restr.push_back({mi, ma});
    }
}
int v[N] , p[N];
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    
        int h;
        
        cin >> h;
        
        for (int i = 0; i <= h; i++)
        {
            cin >> v[i];
        }
        
        bool fl = true;
        
        for (int i = 0; i < h; i++)
        {
            if (v[i] > 1 && v[i + 1] > 1)
            {
                fl = false;
            }
        }
    
        if (fl)
        {
            cout << "perfect" << endl;
            return 0;
        }
        
        cout << "ambiguous" << endl;
        
        int pos = 2;
        int last = 1;
        
        for (int i = 1; i <= h; i++)
        {
            for (int j = 0; j < v[i]; j++)
            {
                p[pos + j] = last;
            }
            
            last = pos;
            pos += v[i];
        }
        
        for (int i = 1; i < pos; i++)
        {
           cout << p[i] << " ";
        }
        
       cout << "\n";
        
        pos = 2;
        last = 1;
        
        for (int i = 1; i <= h; i++) {
            for (int j = 0; j < v[i]; j++) {
                p[pos + j] = last;
            }
            
            if (v[i - 1] > 1 && v[i] > 1) {
                p[pos + v[i] - 1] = last + 1;
            }
            
            last = pos;
            pos += v[i];
        }
        
      for (int i = 1; i < pos; i++)
    {
        cout << p[i] << " ";
    }

       return 0;
}