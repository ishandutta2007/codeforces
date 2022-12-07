#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int sum(int a, int b)
{
    return (a+b<mod) ? a+b : a+b-mod;
}
inline int mul(int a, int b)
{
    return (1ll*a*b)%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, T, q[3]={0, 0, 0};
    cin>>n>>T;
    vector <int> sp[3];
    for(int a=0; a<n; a++)
    {
        int va, ty;
        cin>>va>>ty;
        sp[--ty].push_back(va), q[ty]++;
    }
    int dp[q[0]+1][q[1]+1][q[2]+1][T+1], t[q[0]+1][q[1]+1][q[2]+1][T+1];
    for(int a=0; a<=q[0]; a++)
    {
        for(int b=0; b<=q[1]; b++)
        {
            for(int c=0; c<=q[2]; c++)
            {
                for(int d=0; d<=T; d++) dp[a][b][c][d]=0, t[a][b][c][d]=0;
            }
        }
    }
    dp[0][0][0][0]=1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<sp[i].size(); j++)
        {
            int w=sp[i][j];
            for(int a=0; a<=q[0]; a++)
            {
                for(int b=0; b<=q[1]; b++)
                {
                    for(int c=0; c<=q[2]; c++)
                    {
                        for(int d=0; d<=T; d++)
                        {
                            int va=dp[a][b][c][d];
                            if(va)
                            {
                                t[a][b][c][d]=sum(t[a][b][c][d], va);
                                int na=a, nb=b, nc=c, nd=d+w;
                                if(nd<=T)
                                {
                                    if(i==0) na++;
                                    else if(i==1) nb++;
                                    else nc++;
                                    t[na][nb][nc][nd]=sum(t[na][nb][nc][nd], va);
                                }
                            }
                        }
                    }
                }
            }
            for(int a=0; a<=q[0]; a++)
            {
                for(int b=0; b<=q[1]; b++)
                {
                    for(int c=0; c<=q[2]; c++)
                    {
                        for(int d=0; d<=T; d++) dp[a][b][c][d]=t[a][b][c][d], t[a][b][c][d]=0;
                    }
                }
            }
        }
    }
    int dp2[q[0]+1][q[1]+1][q[2]+1][3];
    for(int a=0; a<=q[0]; a++)
    {
        for(int b=0; b<=q[1]; b++)
        {
            for(int c=0; c<=q[2]; c++)
            {
                for(int i=0; i<3; i++) dp2[a][b][c][i]=0;
            }
        }
    }
    dp2[0][0][0][0]=1;
    for(int a=0; a<q[0]+q[1]+q[2]; a++)
    {
        for(int b=0; (b<=a and b<=q[0]); b++)
        {
            for(int c=0; (c+b<=a and c<=q[1]); c++)
            {
                int d=a-b-c;
                if(d<=q[2])
                {
                    for(int i=0; i<3; i++)
                    {
                        int va=dp2[b][c][d][i];
                        if(va)
                        {
                            if(b<q[0] and (i!=0 or a==0))
                            {
                                dp2[b+1][c][d][0]=sum(dp2[b+1][c][d][0], mul(va, b+1));
                            }
                            if(c<q[1] and (i!=1 or a==0))
                            {
                                dp2[b][c+1][d][1]=sum(dp2[b][c+1][d][1], mul(va, c+1));
                            }
                            if(d<q[2] and (i!=2 or a==0))
                            {
                                dp2[b][c][d+1][2]=sum(dp2[b][c][d+1][2], mul(va, d+1));
                            }
                        }
                    }
                }
            }
        }
    }
    int an=0;
    for(int a=0; a<=q[0]; a++)
    {
        for(int b=0; b<=q[1]; b++)
        {
            for(int c=0; c<=q[2]; c++)
            {
                int su=sum(dp2[a][b][c][0], sum(dp2[a][b][c][1], dp2[a][b][c][2]));
                an=sum(an, mul(su, dp[a][b][c][T]));
            }
        }
    }
    cout<<an;
}