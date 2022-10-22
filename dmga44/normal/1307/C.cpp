#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;

ll fa[26],fab[26][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        int v=s[i]-'a';
        for(int j=0;j<26;j++)
            fab[j][v]+=fa[j];
        fa[v]++;
    }

    ll res=0;
    for(int i=0;i<26;i++)
    {
        res=max(res,fa[i]);
        for(int j=0;j<26;j++)
            res=max(res,fab[i][j]);
    }
    db(res)

    return 0;
}