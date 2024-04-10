#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2000+5;

map<pair<int,int>,int>f;

int n;
int x[N];
int y[N];
ll ans=0LL;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        for(int j=1;j<i;j++)
        {
            ans+=f[{x[i]+x[j],y[i]+y[j]}]++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}