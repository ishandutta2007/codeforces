#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 200005

int fac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,x;
        cin >> n >> x;
        for(int i=0;i<=2*n;i++)
            fac[i]=0;

        string s;
        cin >> s;
        ll ac=0;
        for(int i=0;i<n;i++)
        {
            fac[ac+n]++;
            if(s[i]=='0')
                ac++;
            else
                ac--;
        }
//        fac[ac+n]++;

        if(ac==0 && -n<=x && x<=n && fac[x+n])
            db(-1)
        else if(ac==0)
            db(0)
        else
        {
            ll res=0;
            if(-n<=x && x<=n)
            {
                while(-n<=x && x<=n)
                {
                    res+=fac[n+x];
                    x-=ac;
                }
            }
            else
            {
                for(int i=0;i<=2*n;i++)
                    if(((x>n && ac>0) || (x<-n && ac<0)) && ((n+x+(ll)(abs(ac)*1e10))%abs(ac))==(i%abs(ac)))
                        res+=fac[i];
            }
            db(res)
        }
    }

    return 0;
}