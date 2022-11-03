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

int n;
int x[100],y[100];
vector< vector<int> > g;
int cnt = 0;
bool us[100];

void dfs(int v)
{
     us[v] = true;
     for (int i=0;i<g[v].size();i++)
     {
         int u = g[v][i];
         if (!us[u])
            dfs(u);
     }
}

int main()
{
    cin >> n;
    g.resize(n);
    for (int i=0;i<n;i++)cin >> x[i] >> y[i];
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (x[i]==x[j] || y[i]==y[j])
            {
                           g[i].push_back(j);
                           g[j].push_back(i);
            }
    for (int i=0;i<n;i++)us[i] = false;
    for (int i=0;i<n;i++)
        if (!us[i])
        {
                   cnt++;
                   dfs(i);
                   }
    cout << (cnt-1) << endl;
  //  system("pause");
    return 0;
}