#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n;
vector< vector<int> > g;
vector< vector<int> > num;
int up[100000][21];
int tin[100000],tout[100000];
int timer;
int vh[100000],vih[100000];
int ans[100000];

bool upper(int pred, int v){
    return (tin[pred]<=tin[v] && tout[pred]>=tout[v]);
}

int lca(int v1, int v2){
    if (upper(v1,v2))return v1;
    if (upper(v2,v1))return v2;
    for (int l=20;l>=0;l--)
        if (!upper(up[v1][l],v2))
            v1 = up[v1][l];
    return up[v1][0];
}

void dfs(int v, int pr){
    up[v][0] = pr;
    for (int i=1;i<21;i++)
        up[v][i] = up[up[v][i-1]][i-1];

    timer++;
    tin[v] = timer;
    for (int i=0;i<g[v].size();i++)
        if (g[v][i]!=pr)
            dfs(g[v][i],v);
    timer++;
    tout[v] = timer;
}

void calc(int v,int pr){
    int VH=0,VIH=0;
    for (int i=0;i<g[v].size();i++){
        int u = g[v][i];
        if (u!=pr){
            int NUM = num[v][i];
            calc(u,v);
            ans[NUM] = vh[u] - vih[u];
            VH += vh[u];
            VIH += vih[u];
        }
    }
    vh[v] += VH;
    vih[v] += VIH;
}

int main(){
    cin >> n;
    g.resize(n);
    num.resize(n);
    for (int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        num[a].push_back(i);
        num[b].push_back(i);
    }
    timer = 0;
    dfs(0,0);
    for (int i=0;i<n;i++)
        vh[i] = vih[i] = 0;
    int m;
    for (cin >> m;m;m--){
        int a,b;
        cin >> a >> b;
        a--;b--;
        int c = lca(a,b);
        if (c==a){
            vih[a]++;
            vh[b]++;
        }else
        if (c==b){
            vih[b]++;
            vh[a]++;
        }else{
            vih[c]+= 2;
            vh[a]++;
            vh[b]++;
        }
    }
    calc(0,0);
    for (int i=0;i<n-1;i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}