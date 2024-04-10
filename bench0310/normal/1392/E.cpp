#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> v(n+1,vector<ll>(n+1,0));
    auto in=[&](int r,int c)->bool{return (1<=r&&r<=n&&1<=c&&c<=n);};
    ll x=-1;
    int a=1,b=1;
    while(1)
    {
        for(int d=0;in(a-d,b+d)==1;d++) if(d&1) v[a-d][b+d]=(1ll<<x);
        x++;
        if(a==n&&b==n) break;
        if(b==1&&a<n) a++;
        else b++;
    }
    for(int o=1;o<=n;o++) for(int i=1;i<=n;i++) cout << v[o][i] << " \n"[i==n];
    cout.flush();
    int q;
    cin >> q;
    while(q--)
    {
        ll k;
        cin >> k;
        int r=1,c=1;
        auto out=[&](){cout << r << " " << c << "\n"; cout.flush();};
        ll p=0;
        out();
        for(int i=0;i<2*n-2;i++)
        {
            if(in(r+1,c)==1&&((v[r+1][c]>>p)&1)==((k>>p)&1)) r++;
            else c++;
            out();
            p++;
        }
    }
    return 0;
}