#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto fpow=[&](int b,int e,int mod)
    {
        int r=1;
        while(e)
        {
            if(e&1) r=(ll(r)*b)%mod;
            b=(ll(b)*b)%mod;
            e/=2;
        }
        return r;
    };
    vector<int> primes={2,3,5,7,11,13,17,19,23};
    int sz=primes.size();
    int p=1;
    for(int x:primes) p*=x;
    vector<int> y(sz);
    vector<int> z(sz);
    for(int i=0;i<sz;i++)
    {
        y[i]=(p/primes[i]);
        z[i]=fpow(y[i],primes[i]-2,primes[i]);
    }
    int tc;
    cin >> tc;
    while(tc--)
    {
        auto q=[&](int a,int b)->int
        {
            cout << "? " << a << " " << b << endl;
            int g;
            cin >> g;
            return g;
        };
        vector<int> a(sz,-1);
        for(int i=1;i<=23;i++)
        {
            int g=q(i,i+p);
            for(int j=0;j<sz;j++) if(a[j]==-1&&(g%primes[j])==0) a[j]=((((-i)%primes[j])+primes[j])%primes[j]);
        }
        int x=0;
        for(int i=0;i<sz;i++) x=(x+(((ll(a[i])*y[i])%p)*ll(z[i]))%p)%p;
        int res=0;
        for(ll i=0;i*p+x<=1000000000;i++) if(q(1,2+i*p+x)==i*p+x+1) res=i*p+x;
        cout << "! " << res << endl;
    }
    return 0;
}