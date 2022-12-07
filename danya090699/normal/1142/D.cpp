#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
char s[sz], pref[22];
long long dp[11][11][11], dp2[11][11][11];
int su(int l, int r)
{
    if(l>=r) r+=11;
    int re=pref[r-1];
    if(l) re-=pref[l-1];
    if(re<0) re+=11;
    return re;
}
int main()
{
    for(int a=1; a<22; a++) pref[a]=(pref[a-1]+a)%11;

    //freopen("input.txt", "r", stdin);

    scanf("%s", s);

    long long an=0;
    for(int a=0; s[a]; a++)
    {
        int i=s[a]-'0';
        for(int l=0; l<11; l++)
        {
            for(int r=0; r<11; r++)
            {
                for(int p=0; p<11; p++)
                {
                    if(dp[l][r][p] and i<p)
                    {
                        int nl=r, nr=r+su(l, r), np=r+su(l, p)+i;
                        if(nl>=11) nl-=11;
                        if(nr>=11) nr-=11;
                        if(np>=11) np-=11;
                        if(np>=11) np-=11;
                        dp2[nl][nr][np]+=dp[l][r][p];
                    }
                }
            }
        }
        if(i) dp2[1][10][i]++;
        for(int l=0; l<11; l++)
        {
            for(int r=0; r<11; r++)
            {
                for(int p=0; p<11; p++)
                {
                    dp[l][r][p]=dp2[l][r][p], dp2[l][r][p]=0;
                    an+=dp[l][r][p];
                }
            }
        }
    }
    cout<<an;
}