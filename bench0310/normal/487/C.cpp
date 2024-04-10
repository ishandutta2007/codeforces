#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fpow(ll b,ll e,ll mod)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n<=4)
    {
        cout << "YES\n";
        if(n==1) cout << "1\n";
        else if(n==2) cout << "1 2\n";
        else if(n==3) cout << "1 2 3\n";
        else if(n==4) cout << "1 3 2 4\n";
    }
    else
    {
        bool ok=1;
        for(int i=2;i*i<=n;i++) ok&=((n%i)>0);
        if(ok==1)
        {
            cout << "YES\n";
            cout << "1 ";
            for(ll i=2;i<n;i++) cout << ((i*fpow(i-1,n-2,n))%n) << " ";
            cout << n << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}