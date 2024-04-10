#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
bitset <sz> dp[1<<16];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    dp[0][0]=1;
    for(int mask=0; mask<(1<<n); mask++)
    {
        for(int a=sz-1; a; a--) if(a%k==0 and dp[mask][a]) dp[mask][a/k]=1;
        for(int i=0; i<n; i++)
        {
            int nmask=mask|(1<<i);
            if(nmask!=mask) dp[nmask]|=dp[mask]<<ar[i];
        }
    }
    if(dp[(1<<n)-1][1])
    {
        cout<<"YES\n";
        int s=(1<<n)-1, su=1, p[n];
        for(int a=0; a<n; a++) p[a]=0;
        while(s)
        {
            if(su*k<sz and dp[s][su*k])
            {
                for(int i=0; i<n; i++) if(s&(1<<i)) p[i]++;
                su*=k;
            }
            else
            {
                for(int i=0; i<n; i++)
                {
                    if((s&(1<<i)) and su>=ar[i] and dp[s-(1<<i)][su-ar[i]])
                    {
                        s-=(1<<i), su-=ar[i];
                        break;
                    }
                }
            }
        }
        multiset <pair <int, int>, greater <pair <int, int> > > se;
        for(int a=0; a<n; a++) se.insert({p[a], ar[a]});
        while(se.size()>1)
        {
            pair <int, int> x=*se.begin();
            se.erase(se.begin());
            pair <int, int> y=*se.begin();
            se.erase(se.begin());
            cout<<x.second<<" "<<y.second<<"\n";
            x.second+=y.second;
            while(x.second%k==0) x.second/=k, x.first--;
            se.insert(x);
        }
    }
    else cout<<"NO";
}