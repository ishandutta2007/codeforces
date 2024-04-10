#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
struct ma
{
    int m[2][2]={{0, 2}, {1, 1}};
};
ma cu, st;
void um(ma &m1, ma &m2, ma &re)
{
    for(int a=0; a<2; a++)
    {
        for(int b=0; b<2; b++)
        {
            re.m[a][b]=0;
            for(int c=0; c<2; c++) re.m[a][b]=(re.m[a][b]+m1.m[a][c]*m2.m[c][b])%mod;
        }
    }
}
ma po(int x)
{
    ma an;
    if(x==0) an=st;
    else
    {
        if(x%2==1)
        {
            ma m1=po(x-1);
            um(m1, cu, an);
        }
        else
        {
            ma m1=po(x/2);
            um(m1, m1, an);
        }
    }
    return an;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    cin>>k;
    for(int a=0; a<2; a++) for(int b=0; b<2; b++) st.m[a][b]=(a==b);
    for(int a=0; a<k; a++)
    {
        int x;
        scanf("%lld", &x);
        cu=po(x);
    }
    int ch=cu.m[0][0], zn=(cu.m[0][0]+cu.m[0][1])%mod;
    if(ch%2==1) ch+=mod;
    if(zn%2==1) zn+=mod;
    cout<<ch/2<<"/"<<zn/2;
}