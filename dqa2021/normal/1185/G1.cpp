#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
    int x=0; bool flg=false; char ch=G;
    for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
    for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
    return flg?-x:x;
}
typedef long long ll;
const int Mod=1e9+7;
 
int n,T,t[55],g[55],tot[3];
int id[55][55][55]; int idtot;
int dp[2510][5000];
int subdp[55][55][55][3];
int fac[55];
int ans;
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("A.out","w",stdout);
     
    n=read(),T=read();
    fac[0]=1; for (int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%Mod;
    for (int i=1;i<=n;i++)
    {
        t[i]=read(),g[i]=read()-1,tot[g[i]]++;
    }
    for (int i=0;i<=tot[0];i++)
        for (int j=0;j<=tot[1];j++)
            for (int u=0;u<=tot[2];u++)
                id[i][j][u]=++idtot;
    dp[0][id[0][0][0]]=1;
    tot[0]=tot[1]=tot[2]=0; int sum=0;
    for (int i=1;i<=n;i++)
    {
        tot[g[i]]++; sum+=t[i];
        for (int j=sum;j>=t[i];j--)
            for (int u=tot[0];u>=0;u--)
                for (int v=tot[1];v>=0;v--)
                    for (int e=tot[2];e>=0;e--)
                    {
                        if (g[i]==0&&u) dp[j][id[u][v][e]]=(dp[j][id[u][v][e]]+dp[j-t[i]][id[u-1][v][e]])%Mod;
                        else if (g[i]==1&&v) dp[j][id[u][v][e]]=(dp[j][id[u][v][e]]+dp[j-t[i]][id[u][v-1][e]])%Mod;
                        else if (g[i]==2&&e) dp[j][id[u][v][e]]=(dp[j][id[u][v][e]]+dp[j-t[i]][id[u][v][e-1]])%Mod;
                    }
    }
    for (int i=0;i<=tot[0];i++)
        for (int j=0;j<=tot[1];j++)
        {
            memset(subdp,0,sizeof subdp);
            if (i) subdp[1][i-1][j][0]=1;
            if (j) subdp[1][i][j-1][1]=1;
            subdp[1][i][j][2]=1;
            for (int u=1;u<n;u++)
                for (int v=0;v<=i;v++)
                    for (int e=0;e<=j;e++)
                    {
                        if (v) subdp[u+1][v-1][e][0]=(0LL+subdp[u+1][v-1][e][0]+subdp[u][v][e][1]+subdp[u][v][e][2])%Mod;
                        if (e) subdp[u+1][v][e-1][1]=(0LL+subdp[u+1][v][e-1][1]+subdp[u][v][e][0]+subdp[u][v][e][2])%Mod;
                        subdp[u+1][v][e][2]=(0LL+subdp[u+1][v][e][2]+subdp[u][v][e][0]+subdp[u][v][e][1])%Mod;
                    }
            for (int u=0;u<=tot[2];u++)
            {
                if (!i&&!j&&!u) continue;
                //printf("merge %d %d %d: %d * %d\n",i,j,u,subdp[i+j+u][0][0][0]+subdp[i+j+u][0][0][1]+subdp[i+j+u][0][0][2],dp[T][id[i][j][u]]);
                ans=(ans+1LL*(subdp[i+j+u][0][0][0]+subdp[i+j+u][0][0][1]+subdp[i+j+u][0][0][2])*dp[T][id[i][j][u]]%Mod*fac[i]%Mod*fac[j]%Mod*fac[u])%Mod;
            }
        }
    printf("%d\n",(ans+Mod)%Mod);
    return 0;
}