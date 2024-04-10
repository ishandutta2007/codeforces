#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int q[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        for(int b=1; b*b<=x; b++)
        {
            if(x%b==0)
            {
                q[b]++;
                if(b!=x/b) q[x/b]++;
            }
        }
    }
    long long an=1;
    for(int a=1; a<sz; a++)
    {
        if(q[a]>=n-1)
        {
            an=an/__gcd(an, 1ll*a)*a;
        }
    }
    cout<<an;
}