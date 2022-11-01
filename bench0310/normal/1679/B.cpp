#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<array<int,2>> u(n+1);
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        s+=a;
        u[i]={0,a};
    }
    array<int,2> all={-1,0};
    for(int i=1;i<=q;i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int p,x;
            cin >> p >> x;
            s+=(x-max(u[p],all)[1]);
            u[p]={i,x};
        }
        else
        {
            int x;
            cin >> x;
            s=ll(n)*x;
            all={i,x};
        }
        cout << s << "\n";
    }
    return 0;
}