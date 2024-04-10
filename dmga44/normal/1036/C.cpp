#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 20

ll dp[20][4];

void precalc()
{
    dp[1][0]=1;
    dp[1][1]=9;
    for(int i=2;i<20;i++)
    {
        dp[i][0]=1;
        dp[i][1]=dp[i-1][1]+9;
        dp[i][2]=dp[i-1][2]+9*dp[i-1][1];
        dp[i][3]=dp[i-1][3]+9*dp[i-1][2];
    }
}

ll ans(string s,int x)
{
    ll res=0;
    if(s.size()==1 && x>0)
        return s[0]-'0'+1;
    if(x==0)
        return 1;
    string pass="",p=" ";
    for(int i=1;i<s.size();i++)
    {
        p[0]=s[i];
        pass+=p;
    }
    for(int i=0;i<s[0]-'0';i++)
    {
        if(!i)
        {
            for(int j=0;j<=x;j++)
                res+=dp[s.size()-1][j];
        }
        else
        {
            for(int j=0;j<x;j++)
                res+=dp[s.size()-1][j];
        }
    }
//    db(pass)
    if(s[0]=='0')
        res+=ans(pass,x);
    else
        res+=ans(pass,x-1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precalc();

    int t;
    cin >> t;
    while(t--)
    {
        string l,r;
        cin >> l >> r;
        int cont=0;
        for(auto y : l)
            if(y!='0')
                cont++;
//        db(ans(r,3))
//        db(ans(l,3))
        db(ans(r,3)-ans(l,3)+(cont<=3))
//        db("")
    }

    return 0;
}