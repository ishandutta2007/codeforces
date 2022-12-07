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
        int n, su=0, ok=1;
        cin>>n;
        int pr;
        cin>>pr;
        for(int a=1; a<n; a++)
        {
            int x;
            scanf("%lld", &x);
            if(x>pr) su+=x-pr;
            if(x<su) ok=0;
            pr=x;
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}