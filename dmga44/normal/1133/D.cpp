#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005
#define mod ((ll)(1e9+7))

ll a[MAXN],b[MAXN];
map<pii,int> m;

int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];

    int res=0,c1=0;
    for(int i=0;i<n;i++)
    {
        if(!b[i])
        {
            if(!a[i])
            {
                c1++;
                continue;
            }
            m[pii(mod,0)]++;
            res=max(res,m[pii(mod,0)]);
        }
        else if(a[i])
        {
            int c=gcd(abs(a[i]),abs(b[i]));
            a[i]/=c;
            b[i]/=c;
            if((a[i]<0)!=(b[i]<0))
            {
                a[i]=abs(a[i]);
                b[i]=abs(b[i]);
                a[i]*=-1;
            }
            else
            {
                a[i]=abs(a[i]);
                b[i]=abs(b[i]);
            }
            m[pii(a[i],b[i])]++;
            res=max(res,m[pii(a[i],b[i])]);
        }
    }
    db(res+c1)

    return 0;
}