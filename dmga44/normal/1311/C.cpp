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
#define MAXN 200005

ll freqs[MAXN][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,x;
        cin >> n >> m;
        string s;
        cin >> s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
                freqs[i+1][j]=freqs[i][j];
            freqs[i+1][(s[i]-'a')]++;
        }

        ll res[26];
        for(int i=0;i<26;i++)
            res[i]=0;
        for(int i=0;i<m;i++)
        {
            cin >> x;
            for(int j=0;j<26;j++)
                res[j]+=freqs[x][j];
        }
        for(int j=0;j<26;j++)
            res[j]+=freqs[n][j];

        for(int i=0;i<26;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}