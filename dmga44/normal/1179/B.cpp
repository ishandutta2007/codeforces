#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;

void solve(int l,int r,int len)
{
    if(l==r)
    {
        for(int i=1;i<=((len+1)/2);i++)
        {
            cout << l << ' ' << i << '\n';
            if(i!=((len+1)/2) || !(len&1))
                cout << l << ' ' << len-i+1 << '\n';
        }
        return ;
    }
    for(int i=1;i<=len;i++)
    {
        cout << l << ' ' << i << '\n';
        cout << r << ' ' << len-i+1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=((n+1)/2);i++)
        solve(i,n-i+1,m);

    return 0;
}