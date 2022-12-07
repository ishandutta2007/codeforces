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
        int n, l, r, t=0, ok=1;
        scanf("%d%d", &n, &l);
        r=l;
        for(int a=0; a<n; a++)
        {
            int ct, lg, rg;
            scanf("%d%d%d", &ct, &lg, &rg);
            l=max(l-(ct-t), lg);
            r=min(r+(ct-t), rg);
            t=ct;
            if(l>r) ok=0;
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}