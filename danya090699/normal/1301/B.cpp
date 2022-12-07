#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
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
        int ar[n], l=inf, r=-inf;
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        for(int a=0; a<n; a++)
        {
            if(ar[a]>=0)
            {
                if((a and ar[a-1]==-1) or (a+1<n and ar[a+1]==-1))
                {
                    l=min(l, ar[a]);
                    r=max(r, ar[a]);
                }
            }
        }
        int x=0, d=0;
        if(l!=inf) x=(l+r)>>1;
        for(int a=0; a<n; a++) if(ar[a]==-1) ar[a]=x;
        for(int a=0; a+1<n; a++) d=max(d, abs(ar[a]-ar[a+1]));
        printf("%d %d\n", d, x);
    }
}