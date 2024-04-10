#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<"YES\n"<<(n/2)*2-1<<"\n";
        for(int a=1; a+2<=n; a+=2) printf("%d %d %d\n", a, a+1, a+2);
        for(int a=1; a+2<n; a+=2) printf("%d %d %d\n", a, a+1, n);
    }
    else
    {
        int su=0;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            su^=x;
        }
        if(su) cout<<"NO";
        else
        {
            cout<<"YES\n"<<n-3<<"\n1 2 3\n";
            for(int a=4; a+2<=n; a+=2)
            {
                printf("%d %d %d\n", a, a+1, a+2);
                printf("%d %d %d\n", 1, a, a+1);
            }
        }
    }
}