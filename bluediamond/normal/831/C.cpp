#include <bits/stdc++.h>
using namespace std;
const int nmax=2000;
set<int>sum; int SUM;
set<int>sol;
set<int>::iterator it;
int ans;
int n,k,x,b[nmax+5];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        SUM+=x;
        if(sum.find(SUM)==sum.end())
            sum.insert(SUM);
    }
    for(int i=1;i<=k;i++)
        cin>>b[i];
    for(it=sum.begin();it!=sum.end();it++)
    {
        if(sol.find(b[1]-*it)==sol.end())
            sol.insert(b[1]-*it);
    }
    for(it=sol.begin();it!=sol.end();it++)
    {
        bool ok=1;
        for(int i=2;i<=k;i++)
            if(sum.find(b[i]-*it)==sum.end())
            {
                ok=0;
                break;
            }
        ans+=ok;
    }
    cout<<ans;
    return 0;
}