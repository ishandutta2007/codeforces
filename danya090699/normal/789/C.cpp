#include <bits/stdc++.h>
#define int long long
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=-1e18;
    cin>>n;
    int ar[n], ar2[n-1], ar3[n-1];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<n-1; a++)
    {
        ar2[a]=mo(ar[a]-ar[a+1]);
        if(a%2==1) ar2[a]*=-1;
        ar3[a]=-ar2[a];
    }
    int suf1[n], suf2[n];
    suf1[n-1]=0, suf2[n-1]=0;
    for(int a=n-2; a>=0; a--)
    {
        suf1[a]=max(ar2[a], ar2[a]+suf1[a+1]);
        suf2[a]=max(ar3[a], ar3[a]+suf2[a+1]);
        an=max(an, suf1[a]), an=max(an, suf2[a]);
    }
    cout<<an;
}