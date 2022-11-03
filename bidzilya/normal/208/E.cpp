#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
const ll MD = 10007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
void stop();
//**************************************

int n;
vi dd,nam,cnt;
vvi d,g,p;

void dfs(int v, int dep, int & num)
{
     d[dep].push_back(num);
     dd[v] = dep;
     nam[v] = num;
     num++;
     cnt[v] = 1;
     for (int i=0;i<g[v].size();i++)
     {
         dfs(g[v][i],dep+1,num);
         cnt[v] += cnt[g[v][i]];
     }
}

int calc(int v, int dep)
{
    int res = 0;
    dep += dd[v];
    int left = nam[v],
        right = nam[v]+cnt[v]-1,
        l =0,
        r = d[dep].size()-1,
        ind1 = MAX_INT;
    while (l<=r)
    {
          int m = (l+r)/2;
          int x = d[dep][m];
          if (x>right)
             r = m-1;
          else
          if (x>=left)
          {
                      ind1 = min(ind1,m);
                      r = m-1;
          }else
               l = m+1;
    }
    if (ind1==MAX_INT)
       return 0;
    int ind2 = -1;
    l = 0;
    r = d[dep].size()-1;
    while (l<=r)
    {
          int m = (l+r)/2;
          int x = d[dep][m];
          if (x<left)
             l = m+1;
          else
          if (x<=right)
          {
                       ind2 = max(ind2,m);
                       l = m+1;
          }else
               r = m-1;
    }
    if (ind2==-1)
       return 0;
    return ind2-ind1;
}

int find(int v, int dep)
{
    int st = 1;
    for (int i=0;i<18;i++)
    {
        if (dep&st)
        {
                 v = p[v][i];
                 if (v==-1)
                    return -1;
        }
        st *= 2;
    }
    return v;
}

int main()
{
    cin >> n;
    g.resize(n);
    d.resize(n);
    dd.resize(n);
    p.resize(n);
    nam.resize(n);
    cnt.resize(n);
    for (int i=0;i<n;i++)
    {
        p[i].resize(18,-1);
        int v;
        cin >> v;
        v--;
        p[i][0] = v;
        if (v!=-1)
           g[v].push_back(i);
    }
    for (int i=1;i<18;i++)
        for (int j=0;j<n;j++)
            if (p[j][i-1]!=-1)
               p[j][i]=p[p[j][i-1]][i-1];
    for (int i=0,c=0;i<n;i++)
        if (p[i][0]==-1)
           dfs(i,0,c);
    int m;
    cin >> m;
    for (int i=0;i<m;i++)
    {
        int v,x;
        cin >> v >> x;
        v = find(v-1,x);
        if (v==-1)
           cout << "0 ";
        else
            cout << calc(v,x) << " ";
    }
    return 0;
}

//**************************************


void stop()
{
     for (int i=0;i<MAX_LL;i++);
}