#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, k, an=0, q=1;
        cin>>n>>k;
        if(n==2 and k==3) cout<<"NO\n";
        else
        {
            while(k)
            {
                if(an==n)
                {
                    an=-1;
                    break;
                }
                if(k>=q) k-=q, q*=4, an++;
                else
                {
                    int need=(1ll<<an)*2-1;
                    if(need<=k) an++;
                    k=0;
                    break;
                }
            }
            if(an==-1) cout<<"NO\n";
            else cout<<"YES "<<n-an<<"\n";
        }
    }
}