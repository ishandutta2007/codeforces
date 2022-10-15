#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<int,int>x;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        x[a]++;
    }
    ll ans=0;
    for(int i=1;i<=10;i++)
    {
        ll f=x[i];
        ll s=x[-i];
        ans+=f*s;
    }
    ll f=x[0];
    ans+=f*(f-1)/2;
    cout<<ans<<"\n";
    return 0;
}
/**
**/