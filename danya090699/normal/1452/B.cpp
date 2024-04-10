#include <bits/stdc++.h>
#define int long long
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int su=0, ma=0;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%lld", &x);
            su+=x;
            ma=max(ma, x);
        }
        printf("%lld\n", max(ma, de(su, n-1))*(n-1)-su);
    }
}