#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0, inf=1e9;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        if(ar[a]==1) q++;
    }
    if(q) cout<<n-q;
    else
    {
        int an=inf;
        for(int a=0; a<n; a++)
        {
            int cur=ar[a], yk=a+1;
            while(cur!=1 and yk<n)
            {
                cur=__gcd(cur, ar[yk]), yk++;
            }
            if(cur==1) an=min(an, (yk-a-1)+(n-1));
        }
        if(an==inf) cout<<-1;
        else cout<<an;
    }
}