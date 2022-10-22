#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 300005

ll a[MAXN],b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m,s1=0,s2=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        s1+=a[i];
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        s2+=b[i];
    }

    if(s1!=s2)
        db(-1)
    else
    {
        int res=0;
        int p1=-1,p2=-1;
        ll sa=0,sb=0;
        while(p1!=n && p2!=m)
        {
            if(sa==sb)
            {
                p1++;
                p2++;
                sa=a[p1];
                sb=b[p2];
                res++;
            }
            else if(sa>sb)
            {
                p2++;
                sb+=b[p2];
            }
            else
            {
                p1++;
                sa+=a[p1];
            }
        }
        db(res-1)
    }

    return 0;
}