#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,a,b,c,lim;
int ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b>>c>>lim;
    if(c<=b) {
        cout<<n*a<<"\n";
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        int x=lim-t;
        ans+=c*x+a-b*x;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/