#include <bits/stdc++.h>
using namespace std;
const int nmax=100000;
int n,Time,v[nmax+5],ans;
int main()
{
    cin>>n>>Time;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int start=1,cost=0;
    for(int i=1;i<=n;i++)
    {
        cost+=v[i];
        while(cost>Time)
        {
            cost-=v[start];
            start++;
        }
        ans=max(ans,i-start+1);
    }
    cout<<ans;
    return 0;
}
/**

**/