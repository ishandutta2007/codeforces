#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int nax=(int)1e5+7;
const int mod=(int)1e9+7;
int n;
vector<int>g[nax];
int aa[nax];
int dp[nax][2];

int mul(int a,int b)
{
        return a*(ll)b%mod;
}

int add(int a,int b)
{
        a+=b;
        if(a>=mod)
                return a-mod;
        if(a<0)
                return a+mod;
        return a;
}

int expow(int a,int b)
{
        int r=1;
        while(b)
        {
                if(b&1)
                        r=mul(r,a);
                a=mul(a,a);
                b>>=1;
        }
        return r;
}

int inv(int a)
{
        return expow(a,mod-2);
}

int dv(int a,int b)
{
        return mul(a,inv(b));
}

void dfs(int nod)
{
        for(auto &nou:g[nod])
                dfs(nou);
        /// din toate vin cu 0
        /// din toate vin cu 0 si din unul vin cu 1
        int prod0=1;
        for(auto &nou:g[nod])
                prod0=mul(prod0,dp[nou][0]);
        int a=prod0,b=0;
        for(auto &nou:g[nod])
        {
                int cur=dv(prod0,dp[nou][0]);
                cur=mul(cur,dp[nou][1]);
                b=add(b,cur);
        }
        if(aa[nod]==0)
        {
                dp[nod][0]=add(a,b);
                dp[nod][1]=b;
        }
        else
        {
                dp[nod][0]=a;
                dp[nod][1]=a;
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>n;
        for(int i=1;i<n;i++)
        {
                int p;
                cin>>p;
                g[p+1].push_back(i+1);
        }
        for(int i=1;i<=n;i++)
                cin>>aa[i];
        dfs(1);
        cout<<dp[1][1]<<"\n";
        return 0;
}