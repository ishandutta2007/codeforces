#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, a, m;

int gcd(int x, int y)
{
    if(x==0 || y==0)
        return x+y;
    return gcd(y%x, x);
}

int phi(int x)
{
    int y=x;
    vector <int> v;
    int p=sqrt(x);
    for(int i=2;i<=p;i++)
        if(x%i==0)
            {
                v.push_back(i);
                while(x%i==0)
                    x/=i;
            }
    if(x!=1)
        v.push_back(x);
    for(auto to:v)
        y=y/to*(to-1);
    return y;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> a >> m;
        m/=gcd(a, m);
        cout << phi(m) << endl;
    }
}