#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n,add;
int consume[N],have[N];

ll sum=0;

inline bool ok(ld t)
{
    ld now=t;
    for(int i=1;i<=n;i++)
    {
        ld val=have[i]-t*consume[i];
        if(val<0)
            now+=val/add;
    }
    return now>=0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>add;
    for(int i=1;i<=n;i++)
        cin>>consume[i]>>have[i];
    for(int i=1;i<=n;i++)
        sum+=consume[i];
    if((ll)add>=sum)
    {
        cout<<"-1\n";
        return 0;
    }
    ld lo=0;
    ld hi=1e18;
    for(int i=1;i<=100;i++)
    {
        ld mid=(lo+hi)/2;
        if(ok(mid))
            lo=mid;
        else
            hi=mid;
    }
    cout<<fixed<<setprecision(6)<<lo<<"\n";
    return 0;
}