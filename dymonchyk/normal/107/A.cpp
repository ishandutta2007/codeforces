#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

#define ll long long

using namespace std;

vector < vector<int> > g,d;
int in[1002];
vector <int> x,y,how;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    g.resize(n); d.resize(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a--; b--;
        in[b]++;
        g[a].push_back(b);
        d[a].push_back(c);
    }
    for(int i=0;i<n;i++)
        if (!in[i])
        {
            int cur=i,res=1000000000;
            while(g[cur].size())
            {
                res=min(res,d[cur][0]);
                cur=g[cur][0];
            }
            if (i!=cur)
            {
                x.push_back(i+1);
                y.push_back(cur+1);
                how.push_back(res);
            }
        }
    cout << x.size() << endl;
    for(int i=0;i<x.size();i++)
        cout << x[i] << " " << y[i] << " " <<  how[i] << endl;
    return 0;
}