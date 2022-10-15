#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int ans=k;
    for(int i=1;i<=n;i++)
{
        int x;
        cin>>x;
        ans=gcd(ans,x%k);
    }
    vector<int>sl;
    for(int j=0;j<k;j+=ans)
    {
        sl.push_back(j);
    }
    cout<<sl.size()<<"\n";
    for(auto itr:sl)
    {
        cout<<itr<<" ";
    }
    cout<<"\n";
    return 0;
}
/**
**/