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
        int ar[n], ok=1;
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        vector <pair <int, int> > sp;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            if(x!=ar[a]) sp.push_back({a, x-ar[a]});
        }
        for(int a=0; a<sp.size(); a++)
        {
            if(sp[a].second<0) ok=0;
            if(a+1<sp.size() and (sp[a].first+1!=sp[a+1].first or sp[a].second!=sp[a+1].second)) ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
}