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
#define MAXN 105

string s[MAXN];
bool ok[MAXN];
int dir[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            bool ko=1;
            for(int k=0;k<m;k++)
                ko&=(s[i][k]==s[j][m-k-1]);
            if(ko)
                dir[i]=j;
        }

        ok[i]=1;
        for(int j=0;j<m;j++)
            ok[i]&=(s[i][j]==s[i][m-j-1]);
    }

    vector<string> p1,pm,p2;
    for(int i=0;i<n;i++)
    {
        if(dir[i])
        {
            p1.push_back(s[i]);
            p2.push_back(s[dir[i]]);
        }
        else if(ok[i] && !pm.size())
            pm.push_back(s[i]);
    }

    reverse(p2.begin(),p2.end());

    db(m*(p1.size()+pm.size()+p2.size()))

    for(auto y :p1)
        cout << y;
    if(pm.size())
        cout << pm[0];
    for(auto y :p2)
        cout << y;
    cout << '\n';

    return 0;
}