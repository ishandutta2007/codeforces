#include <bits/stdc++.h>
using namespace std;
int de(int x, int y)
{
    return x/y+(x%y>0);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        if(m<=n/k) cout<<m<<"\n";
        else cout<<n/k-de(m-n/k, k-1)<<"\n";
    }
}