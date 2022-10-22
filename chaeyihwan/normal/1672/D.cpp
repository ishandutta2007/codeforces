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

int a[200002], b[200002], cnt[200002];

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) cnt[i] = 0;
    
    bool flag = true;
    for(int i=n,j=n;i>=1;i--)
    {
        if(a[j] == b[i])
        {
            j--;
            continue;
        }
        
        if(i == n)
        {
            flag = false;
            break;
        }
        
        if(b[i] == b[i+1])
        {
            cnt[b[i]]++;
            continue;
        }
        
        else
        {
            while(a[j] != b[i])
            {
                cnt[a[j]]--;
                if(cnt[a[j]] < 0 || j == 0)
                {
                    flag = false;
                    break;
                }
                j--;
            }
            j--;
        }
    }
    
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}