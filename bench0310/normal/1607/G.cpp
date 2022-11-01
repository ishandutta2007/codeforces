#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        ll c=0;
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        vector<int> x(n+1,0);
        vector<int> y(n+1,0);
        vector<int> o(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i] >> b[i];
            x[i]=min(a[i],m);
            y[i]=(m-x[i]);
            c+=((a[i]-x[i])-(b[i]-y[i]));
            o[i]=min(x[i],b[i]-y[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int z=min(max(ll(0),(-c)/2),ll(o[i]));
            x[i]-=z;
            y[i]+=z;
            c+=2*z;
        }
        cout << abs(c) << "\n";
        for(int i=1;i<=n;i++) cout << x[i] << " " << y[i] << "\n";
    }
    return 0;
}