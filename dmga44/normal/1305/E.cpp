#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 5005

ll res[MAXN],f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    ll sum=0;
    for(int i=0;i<n;i++)
        res[i]=i+1;
    for(int i=n-1;i>=0;i--)
        for(int j=i-1;j>=0;j--)
            if(res[i]-res[j]<res[j])
            {
                sum++;
                f[i]++;
            }

    if(m>sum)
        db(-1)
    else
    {
        int dif=sum-m;
        for(int i=n-1;i>=0;i--)
        {
            if(dif==0)
                break;
            if(dif>=f[i])
            {
                res[i]=1e9-((n-i)*1e5);
                dif-=f[i];
            }
            else
            {
                for(int j=res[i]+1;1;j++)
                {
                    int cant=0;
                    for(int u=i-1;u>=0;u--)
                        if(j-res[u]<res[u])
                            cant++;
                    if((f[i]-cant)==dif)
                    {
                        res[i]=j;
                        dif=0;
                        break;
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}