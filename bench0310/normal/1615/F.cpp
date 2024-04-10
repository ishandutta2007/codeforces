#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while(z--)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        for(int i=1;i<n;i+=2)
        {
            if(s[i]!='?') s[i]^=('0'^'1');
            if(t[i]!='?') t[i]^=('0'^'1');
        }
        const ll mod=1000000007;
        auto add=[&](ll a,ll b){return (a+b)%mod;};
        auto mul=[&](ll a,ll b){return (a*b)%mod;};
        const int S=n;
        vector a(2*n+1,ll(0));
        vector b(2*n+1,ll(0));
        a[S]=1;
        auto madd=[&](ll &x,ll y){x=add(x,y);};
        for(int i=0;i<n;i++)
        {
            vector na(2*n+1,ll(0));
            vector nb(2*n+1,ll(0));
            for(int j=-n;j<=n;j++)
            {
                for(int x=0;x<2;x++)
                {
                    if(s[i]!='?'&&s[i]!=('0'+x)) continue;
                    for(int y=0;y<2;y++)
                    {
                        if(t[i]!='?'&&t[i]!=('0'+y)) continue;
                        int nj=j+x-y;
                        if(!(-n<=nj&&nj<=n)) continue;
                        madd(na[nj+S],a[j+S]);
                        madd(nb[nj+S],add(b[j+S],mul(abs(nj),a[j+S])));
                    }
                }
            }
            a=na;
            b=nb;
        }
        cout << b[S] << "\n";
    }
    return 0;
}