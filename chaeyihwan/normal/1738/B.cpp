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

ll s[100002], a[100002];

void solve()
{
    int n, k; cin >> n >> k;
    for(int i=n-k+1;i<=n;i++) cin >> s[i];
    
    if(k == 1)
    {
        cout << "Yes\n";
        return;
    }
    
    for(int i=n-k+2;i<=n;i++) a[i] = s[i] - s[i-1];
    for(int i=n-k+3;i<=n;i++) if(a[i-1] > a[i])
    {
        cout << "No\n";
        return;
    }
    if(s[n-k+2] > a[n-k+2] * (n-k+2)) cout << "No\n";
    else cout << "Yes\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}