#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar2[n];
    for(int a=0; a<n; a++) scanf("%d", &ar2[a]);
    for(int i=0; i<=25; i++)
    {
        int ar[n];
        for(int a=0; a<n; a++) ar[a]=ar2[a]&((1<<(i+1))-1);
        sort(ar, ar+n);
        //cout<<ar[0]<<" "<<ar[1];
        int l=0, r=0;
        long long su=0;
        for(int a=n-1; a>=0; a--)
        {
            if((ar[a]&(1<<i))==0)
            {
                while(l<n and ar[l]+ar[a]<(1<<i)) l++;
                while(r<n and ar[r]+ar[a]<(1<<(i+1))) r++;
                int q=r-l;
                if(a>=l and a<r) q--;
                //cout<<q<<" ";
                su+=q;
            }

        }
        l=0, r=0;
        for(int a=n-1; a>=0; a--)
        {
            if(ar[a]&(1<<i))
            {
                while(l<n and ar[l]+ar[a]<(1<<(i+1))) l++;
                while(r<n and ar[r]+ar[a]<3*(1<<i)) r++;
                int q=l+(n-r);
                if(a<l or a>=r) q--;
                //cout<<q<<" ";
                su+=q;
            }
        }
        su>>=1;
        if(su&1) an^=(1<<i);
    }
    cout<<an;
}