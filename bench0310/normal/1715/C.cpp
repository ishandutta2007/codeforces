#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    ll res=(ll(n)*(n+1)/2);
    auto upd=[&](int i,int d)
    {
        if(1<=i&&i<n&&a[i]!=a[i+1]) res+=(ll(d)*i*(n-i));
    };
    for(int i=1;i<n;i++) upd(i,1);
    while(m--)
    {
        int i,x;
        cin >> i >> x;
        upd(i-1,-1);
        upd(i,-1);
        a[i]=x;
        upd(i-1,1);
        upd(i,1);
        cout << res << "\n";
    }
    return 0;
}