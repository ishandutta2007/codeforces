#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, k;
    cin>>n>>x>>k;
    int ar[n], q=0;
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    for(int a=0; a<n; a++)
    {
        if(k==0)
        {
            if(ar[a]%x!=0)
            {
                int r=ar[a]+(x-ar[a]%x)-1;
                q+=(upper_bound(ar, ar+n, r)-ar)-(lower_bound(ar, ar+n, ar[a])-ar);
            }
        }
        else
        {
            int l=ar[a];
            if(ar[a]%x!=0) l+=x-ar[a]%x;
            l+=(k-1)*x;
            int r=l+x-1;
            q+=(upper_bound(ar, ar+n, r)-ar)-(lower_bound(ar, ar+n, l)-ar);
        }
    }
    cout<<q;
}