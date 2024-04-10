#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, k;
        cin>>n>>k;
        bool us[60], ok=1;
        for(int a=0; a<60; a++) us[a]=0;
        for(int a=0; a<n; a++)
        {
            int x, i=0;
            scanf("%lld", &x);
            while(x)
            {
                if(x%k)
                {
                    if(x%k==1 and !us[i]) us[i]=1;
                    else ok=0;
                }
                x/=k, i++;
            }
        }
        cout<<(ok ? "YES\n" : "NO\n");
    }
}