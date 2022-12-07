#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod=1e9+7;
int po(int a, int st)
{
    if(st==0) return 1;
    else
    {
        if(st&1) return (a*po(a, st-1))%mod;
        else
        {
            int x=po(a, st/2);
            return (x*x)%mod;
        }
    }
}
main()
{
    int n, m, k;
    cin>>n>>m>>k;
    if(k==-1 and(n+m)%2) cout<<0;
    else cout<<po(po(2, n-1), m-1);
}