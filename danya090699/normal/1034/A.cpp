#include <bits/stdc++.h>
using namespace std;
const int sz=15e6+10;
int q[sz];
bitset <sz> pri;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, d=0;
    cin>>n;
    int an=n, ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        d=__gcd(d, ar[a]);
    }
    for(int a=0; a<n; a++) q[ar[a]/d]++;
    for(int a=2; a<sz; a++)
    {
        if(pri[a]==0)
        {
            int cu=0;
            for(int b=a; b<sz; b+=a)
            {
                cu+=q[b], pri[b]=1;
            }
            an=min(an, n-cu);
        }
    }
    if(an==n) cout<<-1;
    else cout<<an;
}