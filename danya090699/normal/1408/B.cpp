#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int ar[n];
        for(int a=0; a<n; a++) cin>>ar[a];
        int q=0;
        for(int a=0; a+1<n; a++) q+=(ar[a]!=ar[a+1]);
        if(k==1)
        {
            if(q==0) cout<<"1\n";
            else cout<<"-1\n";
        }
        else cout<<max(1, de(q, k-1))<<"\n";
    }
}