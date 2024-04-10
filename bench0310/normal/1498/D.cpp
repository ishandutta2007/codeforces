#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<bool> opt(m+1,0);
    opt[0]=1;
    vector<int> res(m+1,n+1);
    auto up=[&](ll a,ll b)->ll{return (a+b-1)/b;};
    for(int i=1;i<=n;i++)
    {
        int t,y;
        ll x;
        cin >> t >> x >> y;
        vector<int> a(m+1,-1);
        for(int j=0;j<=m;j++)
        {
            if(opt[j]==1) a[j]=y;
            ll to=m+1;
            if(t==1) to=j+up(x,100000);
            else to=up(x*j,100000);
            if(to<=m) a[to]=max(a[to],a[j]-1);
        }
        for(int j=0;j<=m;j++) if(a[j]>=0) opt[j]=1;
        for(int j=1;j<=m;j++) if(opt[j]) res[j]=min(res[j],i);
    }
    for(int i=1;i<=m;i++) cout << (res[i]<=n?res[i]:-1) << " \n"[i==m];
    return 0;
}