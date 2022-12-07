#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, sum=0, an=0;
    cin>>n;
    int mask[n], va[n];
    for(int a=0; a<n; a++) scanf("%lld%lld", &va[a], &mask[a]), sum+=va[a];
    for(int i=0; i<62; i++)
    {
        int cu=0, ch=0;
        for(int a=0; a<n; a++)
        {
            if((mask[a]&(1ll<<i)) and mask[a]<(1ll<<(i+1))) cu+=va[a];
        }
        if((sum>0 and cu>0) or (sum<0 and cu<0)) ch=1;
        if(ch)
        {
            an+=(1ll<<i);
            for(int a=0; a<n; a++) if(mask[a]&(1ll<<i)) va[a]=-va[a];
        }
    }
    cout<<an;
}