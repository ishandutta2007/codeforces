#include <iostream>
#include <map>

using namespace std;

int n,k;
map<int,int>mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    if(k==0)
    {
        if(mp[1]==0)
            cout<<1;
        else
            cout<<-1;
        return 0;
    }
    for(auto c:mp)
    {
        int x=c.first;
        int ap=c.second;
        k-=ap;
        if(k==0)
        {
            cout<<x;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
/**
**/