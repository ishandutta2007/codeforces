#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=n-1;i>=0;i-=k)
        ans+=v[i]+v[i]-2;
    cout<<ans<<"\n";
    return 0;
}
/**


**/