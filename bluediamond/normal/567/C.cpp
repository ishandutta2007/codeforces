#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000+5;
int n;
ll val,v[N];
map<ll,ll>mp1;
map<ll,ll>mp2;
map<ll,ll>mp3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>val;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=n;i>=1;i--)
    {
        mp3[v[i]]+=mp2[v[i]*val];
        mp2[v[i]]+=mp1[v[i]*val];
        mp1[v[i]]++;
    }
    ll ans=0;
    for(auto itr:mp3)
    {
        ans+=itr.second;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/