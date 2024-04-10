#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
void add(int &x, int y)
{
    x+=y;
    if(x>=mod) x-=mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    char sy;
    vector <int> ch;
    while(cin>>sy)
    {
        ch.push_back(sy-'0');
    }
    reverse(ch.begin(), ch.end());
    int n=ch.size(), an=0, an2=0;
    for(short int x=2; x<=9; x++)
    {
        for(short int y=1; y<x; y++)
        {
            if(__gcd(x, y)==1)
            {

                short int m=9/x;
                int dp[n+1][10][10][2][2][1<<m][1<<m];

                for(short int q=0; q<=n; q++)
                {
                    for(short int osx=0; osx<10; osx++)
                    {
                        for(short int osy=0; osy<10; osy++)
                        {
                            for(short int gx=0; gx<2; gx++)
                            {
                                for(short int gy=0; gy<2; gy++)
                                {
                                    for(short int maskx=0; maskx<(1<<m); maskx++)
                                    {
                                        for(short int masky=0; masky<(1<<m); masky++)
                                        {
                                            dp[q][osx][osy][gx][gy][maskx][masky]=0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                dp[0][0][0][0][0][0][0]=1;
                for(short int q=0; q<n; q++)
                {
                    for(short int osx=0; osx<10; osx++)
                    {
                        for(short int osy=0; osy<10; osy++)
                        {
                            for(short int gx=0; gx<2; gx++)
                            {
                                for(short int gy=0; gy<2; gy++)
                                {
                                    for(short int maskx=0; maskx<(1<<m); maskx++)
                                    {
                                        for(short int masky=0; masky<(1<<m); masky++)
                                        {
                                            int va=dp[q][osx][osy][gx][gy][maskx][masky];
                                            if(va)
                                            {
                                                for(int i=0; i<=9; i++)
                                                {
                                                    short int nx=(x*i+osx)%10, nosx=(x*i+osx)/10, nmaskx=maskx;
                                                    if(nx and nx%x==0) nmaskx|=(1<<(nx/x-1));
                                                    short int ngx=(nx>ch[q] or (nx==ch[q] and gx)) ? 1 : 0;

                                                    short int ny=(y*i+osy)%10, nosy=(y*i+osy)/10, nmasky=masky;
                                                    if(ny and ny%y==0 and ny/y<=m) nmasky|=(1<<(ny/y-1));
                                                    short int ngy=(ny>ch[q] or (ny==ch[q] and gy)) ? 1 : 0;

                                                    add(dp[q+1][nosx][nosy][ngx][ngy][nmaskx][nmasky], va);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                int cu=0;
                for(int maskx=0; maskx<(1<<m); maskx++)
                {
                    for(int masky=0; masky<(1<<m); masky++)
                    {
                        if(maskx&masky)
                        {
                            add(cu, dp[n][0][0][0][0][maskx][masky]);
                        }
                    }
                }
                add(an, cu);
                add(an, cu);
            }
        }
    }
    int st=1;
    for(int a=0; a<n; a++)
    {
        an=(an+1ll*st*ch[a])%mod;
        st=(1ll*st*10)%mod;
    }
    cout<<an;
}