#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int res=0;
        int sz=0,ty=-1;
        for(int i=0;i<n;i++)
        {
            if(i && ty!=s[i]-'0')
            {
                if(!ty)
                {
                    if(sz==i)
                        res+=(sz/(k+1));
                    else
                        res+=((sz-k)/(k+1));
                }
                sz=0;
            }
            ty=s[i]-'0';
            sz++;
        }
        if(!ty)
        {
            if(sz!=n)
                res+=(sz/(k+1));
            else
                res=(1+(sz-1)/(k+1));
        }
        db(res)
    }

    return 0;
}