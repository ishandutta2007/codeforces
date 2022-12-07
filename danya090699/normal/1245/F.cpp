#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=30;
int getbit(int x, int i)
{
    if(x&(1<<i)) return 1;
    else return 0;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int l, r;
        cin>>l>>r;
        int dp[sz+1][16];
        for(int i=0; i<=sz; i++) for(int mask=0; mask<16; mask++) dp[i][mask]=0;
        dp[0][0]=1;
        for(int a=0; a<sz; a++)
        {
            int bl=getbit(l, sz-1-a);
            int br=getbit(r, sz-1-a);

            //cout<<bl<<" "<<br<<"\n";

            for(int mask=0; mask<16; mask++)
            {
                int la=getbit(mask, 0);
                int ra=getbit(mask, 1);
                int lb=getbit(mask, 2);
                int rb=getbit(mask, 3);

                for(int i=0; i<2; i++)
                {
                    for(int j=0; i+j<2; j++)
                    {
                        if((bl==0 or i or la) and
                           (br or i==0 or ra) and
                           (bl==0 or j or lb) and
                           (br or j==0 or rb))
                        {
                            //if(i==0 and dp[i][mask]) cout<<mask<<" ";
                            int nla=la|(i!=bl), nra=ra|(i!=br), nlb=lb|(j!=bl), nrb=rb|(j!=br);
                            dp[a+1][nla+(nra<<1)+(nlb<<2)+(nrb<<3)]+=dp[a][mask];
                        }
                    }
                }
            }
        }
        //cout<<dp[1][0];
        int an=0;
        for(int mask=0; mask<16; mask++) an+=dp[sz][mask];
        cout<<an<<"\n";
    }
}