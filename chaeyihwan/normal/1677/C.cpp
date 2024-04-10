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

int ca[100002], cb[100002];
int inv[100002];

bool vis[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> ca[i];
        for(int i=1;i<=n;i++) cin >> cb[i];
        
        for(int i=1;i<=n;i++) inv[ca[i]] = i;
        
        for(int i=1;i<=n;i++) cb[i] = inv[cb[i]];
        
        for(int i=1;i<=n;i++) vis[i] = false;
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int siz = 1;
            vis[i] = true;
            int now = cb[i];
            while(i != now)
            {
                vis[now] = true;
                now = cb[now];
                siz++;
            }
            ans += siz/2;
        }
        
        ll ret = 0;
        for(int i=1;i<=ans;i++)
        {
            ret += n - 2*i + 1;
        }
        ret *= 2;
        cout << ret << "\n";
    }
}