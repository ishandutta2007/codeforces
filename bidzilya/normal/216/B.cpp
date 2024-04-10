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
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
const double eps = 1e-8;

bool may[100];
int cl[100],cnt[100],p[100],tme[100];
vector< vector<int> > g;
vector< vector<int> > crc;
vector<int> tmp;
int n;
int timer;

void dfs(int v, int color)
{
     cl[v]=color;
     tme[v]=timer;
     timer++;
     int ncolor = (color+1)%3;
     if (!ncolor)ncolor++;
     for (int i=0;i<g[v].size();i++)
     {
         int u = g[v][i];
         if (may[u])
         {
            if (!cl[u])
            {
                       p[u] = v;
                       dfs(u,ncolor);
            }
            else
            if (cl[u]==cl[v] && tme[u]<tme[v])
            {
                             tmp.clear();
                             tmp.push_back(v);
                             for (int j=p[v];j!=u;j=p[j])
                                 tmp.push_back(j);
                             tmp.push_back(u);
                             crc.push_back(tmp);
            }
         }
     }
}

int main()
{
    int itr;
    cin >> n >> itr;
    g.resize(n);
    for (int i=0;i<itr;i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        v1--;v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i=0;i<n;i++)may[i]=true;
    for (itr=0;;itr++)
    {
        crc.clear();
        for (int i=0;i<n;i++)
        {
            cl[i]=0;
            cnt[i]=0;
        }
        timer = 0;
        for (int i=0;i<n;i++)
            if (may[i] && !cl[i])
               dfs(i,1);
        for (int i=0;i<crc.size();i++)
            for (int j=0;j<crc[i].size();j++)
                cnt[crc[i][j]]++;
        int id = -1;
        for (int i=0;i<n;i++)
            if (may[i] && (id==-1 || cnt[i]>cnt[id]))
               id = i;
        if (id==-1 || !cnt[id])
           break;
        else
            may[id] = false;
    }
    if ((n-itr)%2==1)itr++;
    cout << itr << endl;
   // system("pause");
    return 0;
}