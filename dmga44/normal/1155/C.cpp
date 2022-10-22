#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m,st,x,ans=0;
    cin >> n >> m;
    cin >> st;
    for(int i=0;i<n-1;i++)
    {
        cin >> x;
        ans=gcd(ans,x-st);
    }

    ll res=-1;
    for(int i=0;i<m;i++)
    {
        cin >> x;
        if(ans%x==0)
            res=i+1;
    }
    if(res==-1)
        db("NO")
    else
    {
        db("YES")
        cout << st << ' ' << res << '\n';
    }

    return 0;
}