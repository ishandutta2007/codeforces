#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, bl=300;
int dp[sz][bl];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=n-1; a>=0; a--)
    {
        for(int k=1; k<bl; k++)
        {
            if(a+ar[a]+k<n) dp[a][k]=dp[a+ar[a]+k][k]+1;
            else dp[a][k]=1;
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int p, k;
        scanf("%d%d", &p, &k);
        p--;
        if(k<bl) printf("%d\n", dp[p][k]);
        else
        {
            int an=0;
            while(p<n) p+=ar[p]+k, an++;
            printf("%d\n", an);
        }
    }
}