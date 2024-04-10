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

int a[200002];

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    int l = -1, r = -1;
    for(int i=1;i<n;i++)
    {
        if(l == -1 && a[i] == a[i+1]) l = i;
        if(a[i] == a[i+1]) r = i;
    }
    
    if(l == r)
    {
        cout << "0\n";
        return;
    }
    else
    {
        cout << max(1, r-l-1) << "\n";
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}