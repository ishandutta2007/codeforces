#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p;
vector<vector<int> > ch;
vector<pair<ll, ll> > c;
vector<int> s;
ll inf = 1e18;
vector<array<vector<ll>, 2> >DP;

void rec(int i){
    DP[i][0][0]=0;
    DP[i][0][1]=c[i].first;
    DP[i][1][1]=c[i].second;
    s[i] = 1;
    for(auto e:ch[i]){
        rec(e);
        s[i]+=s[e];
        for(int j=s[i];j>=0;--j){
            for(int k=max(0, j-s[i]+s[e]);k<=s[e] && k<=j;++k){
                DP[i][0][j] = min(DP[i][0][j], DP[i][0][j-k]+DP[e][0][k]);
                DP[i][1][j] = min(DP[i][1][j], DP[i][1][j-k]+min(DP[e][0][k], DP[e][1][k]));
            }
        }
    }
}

int main()
{
    #ifdef LOCAL_RUN
    freopen("inC.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif // LOCAL_RUN
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n;
    ll m;
    cin >> n >> m;
    p.resize(n, -1);
    ch.resize(n);
    c.resize(n);
    DP.resize(n ,{vector<ll>(n+1, inf), vector<ll>(n+1, inf)});
    s.resize(n);
    for(int i=0;i<n;++i){
        cin >> c[i].first >> c[i].second;
        if(i){
            cin >> p[i];
            ch[--p[i]].emplace_back(i);
        }
        c[i].second = c[i].first - c[i].second;
    }
    rec(0);
    int ans = upper_bound(DP[0][1].begin()+1, DP[0][1].end(), m)-DP[0][1].begin()-1;
    ans = max(ans, (int)(upper_bound(DP[0][0].begin()+1, DP[0][0].end(), m)-DP[0][0].begin()-1));
    cout << ans << "\n";


    return 0;
}