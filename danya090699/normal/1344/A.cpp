#include <bits/stdc++.h>
using namespace std;
int f(int x, int mod)
{
    if(x>=0) return x%mod;
    else return (mod-(abs(x)%mod))%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d", &n);
        bool us[n], ok=1;
        for(int a=0; a<n; a++) us[a]=0;
        for(int a=0; a<n; a++)
        {
            int add;
            scanf("%d", &add);
            int i=f(a+add, n);
            if(us[i]) ok=0;
            else us[i]=1;
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}