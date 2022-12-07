#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        scanf("%d", &n);
        pair <int, int> ar[n];
        for(int a=0; a<n; a++)
        {
            scanf("%d%d", &ar[a].first, &ar[a].second);
        }
        sort(ar, ar+n);
        multiset <int> se;
        int q=0;
        long long su=0;
        for(int a=n-1; a>=0; a--)
        {
            se.insert(ar[a].second);
            while(q<ar[a].first-a)
            {
                su+=(*se.begin());
                se.erase(se.begin());
                q++;
            }
        }
        printf("%lld\n", su);
    }
}