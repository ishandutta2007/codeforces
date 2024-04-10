#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll q;
    cin >> q;
    while(q--)
    {
        ll a,b,m;
        cin >> a >> b >> m;
        if(a==b)
        {
            cout << 1 << ' ' << a << '\n';
            continue;
        }

        bool ok=0;
        ll dif=0;
        ll p=a,i=1ll;
        while(p<=b)
        {
            if(b-p<=((1ll<<(i-1ll))*m) && b-p>=(1ll<<(i-1ll)))
            {
                ok=1;
                dif=b-p-(1ll<<(i-1ll));
                break;
            }
            i++;
            p=(p*2ll);
        }
        if(!ok)
        {
            db(-1)
            continue;
        }
        ll s1=min(dif,m-1);
        dif-=s1;
        cout << i+1 << ' ';
        ll res[55];
        res[0]=a;
        for(ll j=1ll;j<i;j++)
        {
            ll sss=0;
            for(ll u=0;u<j;u++)
                sss+=res[u];
            sss+=min((dif/(1ll<<(i-j-1ll))),m-1ll);
            dif-=min((dif/(1ll<<(i-j-1ll))),m-1ll)*(ll)((1ll<<(i-j-1ll)));
            sss++;
            res[j]=sss;
        }
        ll sss=0;
        for(ll u=0;u<i;u++)
            sss+=res[u];
        sss+=s1;
        sss++;
        res[i]=sss;
        for(ll j=0;j<=i;j++)
            cout << res[j] << ' ';
        cout << '\n';
    }

    return 0;
}