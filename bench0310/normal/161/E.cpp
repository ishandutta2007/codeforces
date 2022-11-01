#include <bits/stdc++.h>

using namespace std;

const int N=100000;
vector<pair<int,int>> z={{1,2},{1,3},{2,3},{1,4},{2,4},{3,4}};
vector<int> ten(7,1);
int s[5][5];
int dp[N][5];

void ini()
{
    vector<bool> p(N,1);
    p[0]=p[1]=0;
    for(long long o=2;o<N;o++)
    {
        if(p[o]==0) continue;
        for(long long i=o*o;i<N;i+=o) p[i]=0;
    }
    for(int i=1;i<=6;i++) ten[i]=ten[i-1]*10;
    for(int o=0;o<N;o++)
    {
        int t=o;
        for(int i=0;i<5;i++)
        {
            if((t%10)==0)
            {
                for(int j=0;j<=9;j++) dp[o][i]+=p[o+ten[i]*j];
            }
            t/=10;
        }
    }

}

int solve(int sz)
{
    int n=(sz-2)*(sz-1)/2;
    int res=0;
    for(int o=0;o<ten[n];o++)
    {
        int t=o;
        for(int i=0;i<n;i++)
        {
            s[z[i].first][z[i].second]=s[z[i].second][z[i].first]=(t%10);
            t/=10;
        }
        int now=1;
        for(int i=1;i<sz;i++)
        {
            int a=0;
            for(int j=0;j<sz;j++) a+=ten[sz-j-1]*s[i][j];
            now*=dp[a][sz-i-1];
        }
        res+=now;
    }
    return res;
}

int main()
{
    ini();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int o=0;o<5;o++) for(int i=0;i<5;i++) s[o][i]=0;
        char t[6];
        scanf("%s",t);
        int sz=strlen(t);
        for(int i=0;i<sz;i++) s[i][0]=s[0][i]=(t[i]-'0');
        printf("%d\n",solve(sz));
    }
    return 0;
}