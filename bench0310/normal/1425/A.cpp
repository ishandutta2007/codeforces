#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*const int N=500;
    vector<ll> dp(N+1,0);
    for(int i=1;i<=N;i++)
    {
        if(i&1) dp[i]=1+(i-1-dp[i-1]);
        else
        {
            cout << i << ": ";
            ll a=1+(i-1-dp[i-1]);
            ll b=i/2+(i/2-dp[i/2]);
            if(a>b) cout << "-1" << endl;
            else if(a<b) cout << "/2" << endl;
            else cout << "either" << endl;
            dp[i]=max(a,b);
        }
    }*/
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll res=0;
        auto mv=[&]()->ll
        {
            if(n==4) return 2;
            else if(n&1) return 1;
            else if((n/2)&1) return n/2;
            else return 1;
        };
        while(n>0)
        {
            ll x=mv();
            res+=x;
            n-=x;
            n-=mv();
        }
        cout << res << "\n";
    }
    return 0;
}