#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int q[71], dp[1<<19], dp2[1<<19];
int po(int x, int y)
{
    if(y==0) return 1;
    else
    {
        if(y%2) return (1ll*x*po(x, y-1))%mod;
        else
        {
            int x2=po(x, y/2);
            return (1ll*x2*x2)%mod;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    vector <int> de;
    for(int a=2; a<=70; a++)
    {
        bool ok=1;
        for(int b=a-1; b>1; b--)
        {
            if(a%b==0) ok=0;
        }
        if(ok) de.push_back(a);
    }
    int n=de.size();
    int m;
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int x;
        scanf("%d", &x);
        q[x]++;
    }
    dp[0]=1;
    for(int a=1; a<=70; a++)
    {
        int qq=1, mask=0, su[2]={0, 0};
        for(int b=0; b<=q[a]; b++)
        {
            su[b%2]+=qq;
            if(su[b%2]>=mod) su[b%2]-=mod;
            qq=(1ll*qq*(q[a]-b))%mod;
            qq=(1ll*qq*po(b+1, mod-2))%mod;
        }
        if(a==1)
        {
            su[0]+=su[1], su[1]=0;
            if(su[0]>=mod) su[0]-=mod;
        }

        for(int b=0; b<n; b++)
        {
            int x=0, ch=a;
            while(ch%de[b]==0)
            {
                ch/=de[b], x^=1;
            }
            if(x) mask+=(1<<b);
        }
        for(int b=0; b<(1<<n); b++)
        {
            dp2[b]=(dp2[b]+1ll*dp[b]*su[0])%mod;
            dp2[b^mask]=(dp2[b^mask]+1ll*dp[b]*su[1])%mod;
        }
        for(int b=0; b<(1<<n); b++)
        {
            dp[b]=dp2[b], dp2[b]=0;
        }
    }
    int an=dp[0]-1;
    if(an<0) an+=mod;
    cout<<an;
}