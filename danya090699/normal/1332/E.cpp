#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, l, r;
    cin>>n>>m>>l>>r;
    int ma[2][2], cu[2][2]={{1, 0}, {0, 1}}, t[2][2], qq=n*m, q[2]={(r-l+1)/2, (r-l+1)/2};
    if((r-l+1)&1)
    {
        if(l&1) q[1]++;
        else q[0]++;
    }
    //cout<<q[0]<<" "<<q[1]<<"\n";
    for(int a=0; a<2; a++) for(int b=0; b<2; b++) ma[a][b]=q[a^b];
    while(qq)
    {
        if(qq&1)
        {
            for(int a=0; a<2; a++)
            {
                for(int b=0; b<2; b++)
                {
                    t[a][b]=0;
                    for(int c=0; c<2; c++) t[a][b]=(t[a][b]+cu[a][c]*ma[c][b])%mod;
                }
            }
            for(int a=0; a<2; a++) for(int b=0; b<2; b++) cu[a][b]=t[a][b];
        }
        qq>>=1;
        for(int a=0; a<2; a++)
        {
            for(int b=0; b<2; b++)
            {
                t[a][b]=0;
                for(int c=0; c<2; c++) t[a][b]=(t[a][b]+ma[a][c]*ma[c][b])%mod;
            }
        }
        for(int a=0; a<2; a++) for(int b=0; b<2; b++) ma[a][b]=t[a][b];
    }
    int an=cu[0][0];
    if((n*m)&1) an=(an+cu[0][1])%mod;
    cout<<an;
}