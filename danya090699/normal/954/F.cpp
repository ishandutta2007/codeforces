#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int sm[3][3], re[3][3], te[3][3], q[4];
void mul(int (*m1)[3], int (*m2)[3])
{
    for(int a=0; a<3; a++) for(int b=0; b<3; b++) te[a][b]=0;
    for(int a=0; a<3; a++)
    {
        for(int b=0; b<3; b++)
        {
            for(int c=0; c<3; c++) te[a][b]=(te[a][b]+m1[a][c]*m2[c][b])%mod;
        }
    }
    for(int a=0; a<3; a++) for(int b=0; b<3; b++) m1[a][b]=te[a][b];
}
void po(int st)
{
    for(int a=0; a<3; a++) for(int b=0; b<3; b++) re[a][b]=(a==b);
    while(st)
    {
        if(st&1) mul(re, sm);
        mul(sm, sm);
        st>>=1;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <pair <int, pair <int, int> > > sp;
    for(int a=0; a<n; a++)
    {
        int i, l, r;
        cin>>i>>l>>r;
        i--, l--, r;
        sp.push_back(make_pair(l, make_pair(i, 1)));
        sp.push_back(make_pair(r, make_pair(i, -1)));
    }
    sp.push_back(make_pair(1, make_pair(3, 1)));
    sp.push_back(make_pair(m, make_pair(3, -1)));
    sort(sp.begin(), sp.end());
    int dp[3]={0, 1, 0}, dp2[3]={0, 0, 0}, yk=0;
    while(yk<sp.size())
    {
        int l=sp[yk].first;
        while(yk<sp.size())
        {
            if(sp[yk].first==l)
            {
                q[sp[yk].second.first]+=sp[yk].second.second;
                yk++;
            }
            else break;
        }
        if(yk<sp.size())
        {
            int r=sp[yk].first;
            for(int a=0; a<3; a++)
            {
                for(int b=0; b<3; b++) sm[a][b]=(abs(a-b)<2 and q[b]==0);
            }
            po(r-l);
            for(int a=0; a<3; a++)
            {
                for(int b=0; b<3; b++) dp2[b]=(dp2[b]+dp[a]*re[a][b])%mod;
            }
            for(int a=0; a<3; a++)
            {
                dp[a]=dp2[a], dp2[a]=0;
            }
        }
    }
    cout<<dp[1];
}