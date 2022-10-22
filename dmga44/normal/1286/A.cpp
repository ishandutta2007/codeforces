#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 105

vector<pip> act;
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a;
    cin >> n;
    vector<pii> p;
    int c[2];
    c[0]=n/2;
    c[1]=(n+1)/2;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(a)
        {
            p.push_back(pii(a,i));
            c[a&1]--;
        }
    }
    if(c[0]+c[1]==n)
    {
        if(n==1)
            db(0)
        else
            db(1)
        return 0;
    }

    int base=0;
    for(int i=0;i<p.size();i++)
    {
        int pos=p[i].second;
        int t=p[i].first&1;
        if(!i && pos)
        {
            base++;
            if(!t)
                act.push_back(pip(1,pii(pos,0)));
            else
                act.push_back(pip(1,pii(0,pos)));
        }
        if(i==p.size()-1 && pos!=n-1)
        {
            base++;
            if(!t)
                act.push_back(pip(1,pii(n-1-pos,0)));
            else
                act.push_back(pip(1,pii(0,n-1-pos)));
        }
        if(i && t!=(p[i-1].first&1))
            base++;
        if(i && t==(p[i-1].first&1) && pos!=p[i-1].second+1)
        {
            base+=2;
            if(!t)
                act.push_back(pip(2,pii(pos-p[i-1].second-1,0)));
            else
                act.push_back(pip(2,pii(0,pos-p[i-1].second-1)));
        }
    }
    for(auto y : act)
        for(int i=n-y.second.first;i>=0;i--)
            for(int j=n-y.second.second;j>=0;j--)
                dp[i+y.second.first][j+y.second.second]=max(dp[i+y.second.first][j+y.second.second],dp[i][j]+y.first);
    ll m=0;
    for(int i=0;i<=c[0];i++)
        for(int j=0;j<=c[1];j++)
            m=max(m,dp[i][j]);
    db(base-m)

    return 0;
}
/**
7
1 0 0 5 0 0 2
5
0 5 0 2 3
**/