#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 100005

ll ac[MAXN],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }

        ll mi=0,r1=-1e17;
        for(int i=0;i<n-1;i++)
        {
            ac[i+1]=ac[i]+a[i];
            r1=max(r1,ac[i+1]-mi);
            mi=min(mi,ac[i+1]);
        }

        mi=0;
        for(int i=1;i<n;i++)
        {
            ac[i]=ac[i-1]+a[i];
            r1=max(r1,ac[i]-mi);
            mi=min(mi,ac[i]);
        }

        if(sum>r1)
            db("Yes")
        else
            db("No")
    }


    return 0;
}