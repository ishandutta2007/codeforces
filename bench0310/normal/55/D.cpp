#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

const int mod=2520;
vector<array<int,4>> v(48);
int rev[4][3][2][2];

ll solve(ll n)
{
    string s=to_string(n);
    int len=s.size();
    vector<vector<array<ll,2>>> now(48,vector<array<ll,2>>(mod,{0,0}));
    now[0][0][1]=1;
    for(int o=0;o<len;o++)
    {
        int num=(s[o]-'0');
        vector<vector<array<ll,2>>> nxt(48,vector<array<ll,2>>(mod,{0,0}));
        for(int m=0;m<48;m++)
        {
            for(int i=0;i<mod;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    auto [a,b,c,d]=v[m];
                    if(j==2) a=max(a,1);
                    if(j==3) b=max(b,1);
                    if(j==4) a=max(a,2);
                    if(j==5) c=max(c,1);
                    if(j==6)
                    {
                        a=max(a,1);
                        b=max(b,1);
                    }
                    if(j==7) d=max(d,1);
                    if(j==8) a=max(a,3);
                    if(j==9) b=max(b,2);
                    int nm=rev[a][b][c][d];
                    int ni=(10*i+j)%mod;
                    nxt[nm][ni][0]+=now[m][i][0];
                    if(j<num) nxt[nm][ni][0]+=now[m][i][1];
                    if(j==num) nxt[nm][ni][1]+=now[m][i][1];
                }
            }
        }
        now=nxt;
    }
    ll res=0;
    for(int m=0;m<48;m++)
    {
        vector<int> opt;
        auto [a,b,c,d]=v[m];
        if(a>0) opt.push_back((1<<a));
        if(b==1) opt.push_back(3);
        if(b==2) opt.push_back(9);
        if(c==1) opt.push_back(5);
        if(d==1) opt.push_back(7);
        for(int i=0;i<mod;i++)
        {
            bool ok=1;
            for(int j:opt) ok&=((i%j)==0);
            if(ok) res+=(now[m][i][0]+now[m][i][1]);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int id=0;
    for(int a=0;a<=3;a++) for(int b=0;b<=2;b++) for(int c=0;c<=1;c++) for(int d=0;d<=1;d++) v[id++]={a,b,c,d};
    for(int i=0;i<48;i++)
    {
        auto [a,b,c,d]=v[i];
        rev[a][b][c][d]=i;
    }
    int t;
    cin >> t;
    while(t--)
    {
        ll l,r;
        cin >> l >> r;
        cout << solve(r)-solve(l-1) << "\n";
    }
    return 0;
}