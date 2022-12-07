#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, mi=1e18, su=0;
        scanf("%lld", &n);
        pair <int, int> ar[n];
        for(int a=0; a<n; a++) scanf("%lld%lld", &ar[a].first, &ar[a].second);
        for(int a=0; a<n; a++)
        {
            int pr=a-1;
            if(pr==-1) pr+=n;
            int x=max(0ll, ar[a].first-ar[pr].second);
            su+=x, mi=min(mi, ar[a].first-x);
        }
        printf("%lld\n", su+mi);
    }
}