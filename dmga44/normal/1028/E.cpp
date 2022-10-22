#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 150005

ll a[MAXN],res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,x,ma=0;
    cin >> n;
    set<ll> s;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        s.insert(a[i]);
        ma=max(ma,a[i]);
    }

    if(s.size()==1)
    {
        if(ma==0)
        {
            db("YES")
            for(int i=0;i<n;i++)
                cout << 1 << ' ';
        }
        else
            db("NO")
        return 0;
    }
    else
    {
        db("YES")
        x=ma;
        ll p=0;
        for(ll i=0;i<n;i++)
            if(a[i]==x && (a[(i+n-1)%n]!=x) && !p)
                p=i+1;
        p--;
        res[p]=a[p];
        res[(p+n-1)%n]=a[(p+n-1)%n]+((200000/a[p])+1)*(a[p]);
        for(ll i=(p+n-2)%n;i!=p;i=(i+n-1)%n)
            res[i]=a[i]+res[(i+1)%n];
        for(ll i=0;i<n;i++)
            cout << res[i] << ' ';
    }

    return 0;
}