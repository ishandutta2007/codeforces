#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m;
    cin>>n>>k>>m;
    int sq=(k+1)<<m;
    int ma[sq][sq], re[sq][sq];
    for(int a=0; a<sq; a++) for(int b=0; b<sq; b++) re[a][b]=(a==b), ma[a][b]=0;
    for(int a=0; a<=k; a++)
    {
        for(int b=0; b<(1<<m); b++)
        {
            ma[(a<<m)+b][(a<<m)+(b>>1)]=1;
            if(a<k)
            {
                ma[(a<<m)+b][((a+1)<<m)+(b>>1)+(1<<(m-1))]=1+__builtin_popcount(b);
            }
        }
    }
    while(n)
    {
        if(n&1)
        {
            int t[sq][sq];
            for(int a=0; a<sq; a++)
            {
                for(int b=0; b<sq; b++)
                {
                    t[a][b]=0;
                    for(int c=0; c<sq; c++) t[a][b]=(t[a][b]+1ll*re[a][c]*ma[c][b])%mod;
                }
            }
            for(int a=0; a<sq; a++) for(int b=0; b<sq; b++) re[a][b]=t[a][b];
        }
        n>>=1;
        int t[sq][sq];
        for(int a=0; a<sq; a++)
        {
            for(int b=0; b<sq; b++)
            {
                t[a][b]=0;
                for(int c=0; c<sq; c++) t[a][b]=(t[a][b]+1ll*ma[a][c]*ma[c][b])%mod;
            }
        }
        for(int a=0; a<sq; a++) for(int b=0; b<sq; b++) ma[a][b]=t[a][b];
    }
    int an=0;
    for(int a=0; a<(1<<m); a++) an=(an+re[0][(k<<m)+a])%mod;
    cout<<an;
}