#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, an=1;
        cin>>n>>k;
        int ar[n], w[n];
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            ar[a]--;
            w[a]=-1;
        }
        for(int a=0; a<k; a++)
        {
            int x;
            scanf("%d", &x);
            x--;
            w[x]=a;
        }
        for(int a=0; a<n; a++)
        {
            if(w[ar[a]]!=-1)
            {
                int q=0;
                if(a and w[ar[a-1]]<w[ar[a]]) q++;
                if(a+1<n and w[ar[a+1]]<w[ar[a]]) q++;
                //cout<<q<<" ";

                an=1ll*an*q%mod;
            }
        }
        printf("%d\n", an);
    }
}