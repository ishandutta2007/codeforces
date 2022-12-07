#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m, t;
    cin>>n>>k>>m>>t;
    for(int a=0; a<t; a++)
    {
        int ty, i;
        cin>>ty>>i;
        if(ty)
        {
            if(i<=k) k++;
            n++;
        }
        else
        {
            if(k>i) k-=i, n-=i;
            else n=i;
        }
        cout<<n<<" "<<k<<"\n";
    }
}