#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod=1e9+7;
int pl(int a, int b)
{
    int res=a+b;
    if(res>=mod) res-=mod;
    return res;
}
int mi(int a, int b)
{
    int res=a-b;
    if(res<0) res+=mod;
    return res;
}
int um(int a, int b){return (a*b)%mod;}
int sol(int x, int y, int k)
{
    int bix[31], biy[31], bik[31];
    for(int a=0; a<31; a++)
    {
        bix[a]=x%2, x/=2;
        biy[a]=y%2, y/=2;
        bik[a]=k%2, k/=2;
    }
    int su[32][2][2][2], q[32][2][2][2];
    for(int a=0; a<32; a++)
    {
        for(int b=0; b<2; b++)
        {
            for(int c=0; c<2; c++)
            {
                for(int d=0; d<2; d++)
                {
                    su[a][b][c][d]=0, q[a][b][c][d]=0;
                }
            }
        }
    }
    q[31][1][1][1]=1;
    for(int a=30; a>=0; a--)
    {
        for(int b=0; b<2; b++)
        {
            for(int c=0; c<2; c++)
            {
                for(int d=0; d<2; d++)
                {
                    int eg=2, fg=2, gg=2;
                    if(b==1 and bix[a]==0) eg--;
                    if(c==1 and biy[a]==0) fg--;
                    if(d==1 and bik[a]==0) gg--;
                    for(int e=0; e<eg; e++)
                    {
                        for(int f=0; f<fg; f++)
                        {
                            int neb=(e^f), nb=0, nc=0, nd=0;
                            if(b==1 and e==eg-1) nb=1;
                            if(c==1 and f==fg-1) nc=1;
                            if(neb<gg)
                            {
                                if(d==1 and neb==gg-1) nd=1;
                                q[a][nb][nc][nd]=pl(q[a][nb][nc][nd], q[a+1][b][c][d]);
                                int add=(neb<<a)%mod;
                                su[a][nb][nc][nd]=pl(su[a][nb][nc][nd], pl(su[a+1][b][c][d], um(add, q[a+1][b][c][d])));
                            }
                        }
                    }
                }
            }
        }
    }
    int res=0;
    for(int a=0; a<2; a++)
    {
        for(int b=0; b<2; b++)
        {
            for(int c=0; c<2; c++)
            {
                res=pl(res, su[0][a][b][c]);
                res=pl(res, q[0][a][b][c]);
            }
        }
    }
    return res;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int x, y, x2, y2, k, an=0;
        cin>>x>>y>>x2>>y2>>k;
        x--, y--, x2--, y2--;
        k--;
        an=pl(an, sol(x2, y2, k));
        if(x>0) an=mi(an, sol(x-1, y2, k));
        if(y>0) an=mi(an, sol(x2, y-1, k));
        if(x>0 and y>0) an=pl(an, sol(x-1, y-1, k));
        cout<<an<<"\n";
    }
}