#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>ray(n);
    for(int i=0;i<n;i++)
    {
        cin>>ray[i];
    }
    sort(ray.begin(),ray.end());
    ray.push_back((int)1e9);
    vector<int>tai(n+2,0);
    for(int i=0;i<m;i++)
    {
        int x1,x2,y;
        cin>>x1>>x2>>y;
        if(x1==1)
        {
            int sector=upper_bound(ray.begin(),ray.end(),x2)-ray.begin();
            tai[sector]++;
        }
    }
    for(int i=n+1;i>=1;i--)
    {
        tai[i-1]+=tai[i];
    }
    int ans=(1<<30);
    for(int i=1;i<=n+1;i++)
    {
        ans=min(ans,tai[i]+i-1);
    }
    cout<<ans<<"\n";
    return 0;
}