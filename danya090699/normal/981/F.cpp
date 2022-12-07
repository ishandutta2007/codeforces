#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, l;
    cin>>n>>l;
    int da[n];
    vector <int> ca;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        ca.push_back(x);
    }
    sort(ca.begin(), ca.end());
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &da[a]), da[a]+=l;
    }
    sort(da, da+n);
    for(int i=1; i<3; i++)
    {
        for(int a=0; a<n; a++) ca.push_back(ca[a]+i*l);
    }
    int ll=-1, rr=l/2;
    while(rr-ll>1)
    {
        int mid=(ll+rr)>>1;
        int lg[n], rg[n], yk=0;
        for(int a=0; a<n; a++)
        {
            while(yk<n*3)
            {
                if(ca[yk]<=da[a]+mid) yk++;
                else break;
            }
            rg[a]=yk-1;
        }
        yk=n*3-1;
        for(int a=n-1; a>=0; a--)
        {
            while(yk>=0)
            {
                if(ca[yk]>=da[a]-mid) yk--;
                else break;
            }
            lg[a]=yk+1;
        }
        int add[n+1], cu=0, ok=0;
        for(int a=0; a<=n; a++) add[a]=0;
        for(int a=0; a<n; a++)
        {
            if(lg[a]<=rg[a])
            {
                lg[a]%=n, rg[a]%=n;
                lg[a]-=a, rg[a]-=a;
                if(lg[a]<0) lg[a]+=n;
                if(rg[a]<0) rg[a]+=n;
                if(lg[a]<=rg[a])
                {
                    add[lg[a]]++, add[rg[a]+1]--;
                }
                else
                {
                    add[lg[a]]++, add[n]--;
                    add[0]++, add[rg[a]+1]--;
                }
            }
        }
        for(int a=0; a<n; a++)
        {
            cu+=add[a];
            if(cu==n) ok=1;
        }
        if(ok) rr=mid;
        else ll=mid;
    }
    cout<<rr;
}