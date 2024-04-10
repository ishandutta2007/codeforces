#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

const ll mod = 998244353;

int v[1000002];
ll pw[1000002];
ll dp[1000002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> v[i];
        
        bool flag = true;
        for(int i=n;i>n-k;i--)
        {
            if(v[i] > 0) flag = false;
        }
        if(!flag)
        {
            cout << "0\n";
            continue;
        }
        
        ll ans = 1;
        for(int i=1;i<=k;i++)
        {
            ans = (ans * i)%mod;
        }
        
        pw[0] = 1;
        for(int i=1;i<=n;i++) pw[i] = (pw[i-1] * (k+1))%mod;
        for(int i=1;i<=n;i++) dp[i] = 0;
        for(int i=1;i<=n-k;i++)
        {
            if(v[i] == 0) ans = (ans * (k+1))%mod;
            if(v[i] == -1) ans = (ans * (k+i))%mod;
        }
        
        cout << ans << "\n";
    }
}