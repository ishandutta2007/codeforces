#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=4e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0;
    cin>>n>>k;
    int ar[n], ne[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    ne[n-1]=n;
    for(int a=n-2; a>=0; a--)
    {
        if(ar[a+1]!=1) ne[a]=a+1;
        else ne[a]=ne[a+1];
    }
    for(int a=0; a<n; a++)
    {
        int p=1, su=0, yk=a;
        while(yk<n)
        {
            if(inf/p<ar[yk]) break;
            p*=ar[yk], su+=ar[yk];
            //cout<<yk<<" "<<p<<" "<<su<<"\n";
            if(p%k==0)
            {
                if(p/k>=su)
                {
                    int q=ne[yk]-yk-1;
                    if(su+q>=p/k) an++;
                }
            }
            su+=ne[yk]-yk-1;
            yk=ne[yk];
        }
    }
    cout<<an;
}