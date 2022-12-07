#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    /*int n=40, k=12;
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int a=3; a<=n; a++)
    {
        dp[a]=(dp[a-1]==0 or dp[a-2]==0 or dp[a-k]==0);
    }
    for(int a=0; a<=n; a++) cout<<dp[a];*/

    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, k, an;
        cin>>n>>k;
        if(k%3!=0) an=(n%3>0);
        else
        {
            n%=(k+1);
            if(n<k and n%3==0) an=0;
            else an=1;
        }
        if(an) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
}