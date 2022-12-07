#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int ma[5][5], re[5][5], t[5][5];

int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
void mul(int n, int st, int mod)
{
    while(st)
    {
        if(st&1)
        {
            for(int a=0; a<n; a++)
            {
                for(int b=0; b<n; b++)
                {
                    t[a][b]=0;
                    for(int c=0; c<n; c++) t[a][b]=(t[a][b]+re[a][c]*ma[c][b])%mod;
                }
            }
            for(int a=0; a<n; a++) for(int b=0; b<n; b++) re[a][b]=t[a][b];
        }
        st>>=1;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<n; b++)
            {
                t[a][b]=0;
                for(int c=0; c<n; c++) t[a][b]=(t[a][b]+ma[a][c]*ma[c][b])%mod;
            }
        }
        for(int a=0; a<n; a++) for(int b=0; b<n; b++) ma[a][b]=t[a][b];


    }
}
main()
{
    //freopen("input.txt", "r", stdin);

    int n, f[3], c, an=1;
    cin>>n>>f[0]>>f[1]>>f[2]>>c;

    ma[0][2]=1, ma[1][2]=1, ma[2][2]=1;
    ma[1][0]=1;
    ma[2][1]=1;

    for(int a=0; a<3; a++) for(int b=0; b<3; b++) re[a][b]=(a==b);

    mul(3, n-3, mod-1);

    for(int i=0; i<3; i++) an=(an*po(f[i], re[i][2]))%mod;

    for(int a=0; a<5; a++) for(int b=0; b<5; b++) ma[a][b]=0;

    ma[0][2]=1, ma[1][2]=1, ma[2][2]=1;
    ma[1][0]=1;
    ma[2][1]=1;

    ma[3][2]=1, ma[3][3]=1;

    ma[4][3]=1, ma[4][4]=1;


    for(int a=0; a<5; a++) for(int b=0; b<5; b++) re[a][b]=0;

    re[3][3]=2, re[4][4]=2;

    mul(5, n-3, mod-1);

    an=(an*po(c, (re[3][2]+re[4][2])%(mod-1)))%mod;

    cout<<an;

}