#include <bits/stdc++.h>
using namespace std;
const int sz=3700, mod=998244353;
int us[2][sz], dp[2][sz][sz], tr[sz][sz], fact[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n[2], m, lef[2], an=0;
    cin>>n[0]>>n[1]>>m;
    lef[0]=n[0], lef[1]=n[1];

    int n2=max(n[0], n[1]);

    for(int a=0; a<=n2; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=(tr[a-1][b-1]+tr[a-1][b])%mod;
    }
    fact[0]=1;
    for(int a=1; a<=n2; a++) fact[a]=(1ll*fact[a-1]*a)%mod;


    for(int a=0; a<m; a++)
    {
        for(int j=0; j<2; j++)
        {
            for(int i=0; i<2; i++)
            {
                int p;
                cin>>p;
                p--;
                us[i][p]=1;
            }
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n[i]; a++) if(us[i][a]) lef[i]--;

        dp[i][0][0]=1;
        for(int a=0; a<n[i]; a++)
        {
            for(int b=0; b<=n[i]; b++)
            {
                dp[i][a+1][b]=(dp[i][a+1][b]+dp[i][a][b])%mod;
                if(a+2<=n[i] and us[i][a]==0 and us[i][a+1]==0) dp[i][a+2][b+1]=(dp[i][a+2][b+1]+dp[i][a][b])%mod;
            }
        }
    }
    for(int a=0; a*2<=lef[0]; a++)
    {
        for(int b=0; b*2<=lef[1]; b++)
        {
            if(a*2+b<=lef[0] and b*2+a<=lef[1])
            {
                int add=(1ll*dp[0][n[0]][a]*dp[1][n[1]][b])%mod;
                //if(a==0 and b==2) cout<<add;
                add=(1ll*add*tr[lef[0]-a*2][b])%mod;
                add=(1ll*add*fact[b])%mod;
                add=(1ll*add*tr[lef[1]-b*2][a])%mod;
                add=(1ll*add*fact[a])%mod;
                an=(an+add)%mod;

                //cout<<a<<" "<<b<<" "<<add<<"\n";

            }
        }
    }
    cout<<an;
}