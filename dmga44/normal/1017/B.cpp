#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005

ll dp[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='0')
        {
            if(b[i]=='0')
                res+=dp[2]+dp[3];
            else
                res+=dp[2];
        }
        else
        {
            if(b[i]=='0')
                res+=dp[1]+dp[0];
            else
                res+=dp[0];
        }
        dp[a[i]-'0'+a[i]-'0'+b[i]-'0']++;
    }
    db(res)

    return 0;
}