#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>

using namespace std;

const int N=100000;
int n,k,m;
map<string,int>v;
string a;
int cost[N+5];
int best[N+5];
int aux[N+5];
int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        v[a]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>cost[i];
        best[i]=cost[i];
    }
    for(int i=1;i<=k;i++)
    {
        int nr;
        cin>>nr;
        for(int j=1;j<=nr;j++)
        {
            cin>>aux[j];
        }
        int best2=cost[aux[1]];
        for(int j=2;j<=nr;j++)
            best2=min(best2,cost[aux[j]]);
        for(int j=1;j<=nr;j++)
            best[aux[j]]=min(best[aux[j]],best2);
    }
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        string a;
        cin>>a;
        ans+=best[v[a]];
    }
    cout<<ans;
    return 0;
}
/**


**/