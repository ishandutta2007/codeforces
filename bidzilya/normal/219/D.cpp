#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
const double eps = 1e-8;

const int MAX_N = 200000;

vector< vector<int> > g,tt,d;
int a[MAX_N];
bool us[MAX_N];
int n;

void dfs1(int v){
     us[v] = true;
     a[v] = 0;
     for (int i=0;i<g[v].size();i++){
         int u = g[v][i];
         if (!us[u]){
                     d[v].push_back(i);
                     if (tt[v][i]==-1)a[v]++;
                     dfs1(u);
                     a[v] += a[u];
         }
     }
}

void dfs2(int v){
     for (int i=0;i<d[v].size();i++){
         int id = d[v][i];
         int u = g[v][id];
         int dc = tt[v][id];
         a[u] = a[v]+dc;
         dfs2(u);
     }
}

int main(){
    cin >> n;
    g.resize(n);
    tt.resize(n);
    d.resize(n);
    for (int i=0;i<n-1;i++){
        int v1,v2;
        cin >> v1 >> v2;
        v1--;v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
        tt[v1].push_back(1);
        tt[v2].push_back(-1);
    }
    for (int i=0;i<n;i++)us[i]=false;
    dfs1(0);
    dfs2(0);
    int ans = MAX_INT;
    for (int i=0;i<n;i++)
        ans = min(a[i],ans);
    vector<int>t;
    for (int i=0;i<n;i++)
        if (a[i]==ans)
           t.push_back(i);
    cout << ans << endl;
    for (int i=0;i<t.size();i++)
        cout << (t[i]+1) << " ";
    cout << endl;
    //system("pause");
    return 0;
}