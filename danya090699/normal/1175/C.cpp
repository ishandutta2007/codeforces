#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, k;
        scanf("%d%d", &n, &k);
        int ar[n], be=2e9, x;
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        for(int a=0; a+k<n; a++)
        {
            if(de(ar[a+k]-ar[a], 2)<be) be=de(ar[a+k]-ar[a], 2), x=(ar[a]+ar[a+k])>>1;
        }
        printf("%d\n", x);
    }
}