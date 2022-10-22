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

int a[100002];

void solve()
{
    int n; cin >> n;
    vector<ll> fire, frost;
    ll sum = 0;
    ll sm = 1e10;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++)
    {
        ll b; cin >> b;
        if(a[i] == 0) fire.push_back(b);
        else frost.push_back(b);
        sum += b;
        sm = min(sm, b);
    }
    sort(fire.rbegin(), fire.rend());
    sort(frost.rbegin(), frost.rend());
    
    int n1 = (int)fire.size();
    int n2 = (int)frost.size();
    
    if(n1 == 0 || n2 == 0)
    {
        cout << sum << "\n";
        return;
    }
    if(n1 == n2)
    {
        cout << 2 * sum - sm << "\n";
        return;
    }
    if(n1 > n2)
    {
        swap(fire, frost);
        swap(n1, n2);
    }
    
    for(int i=0;i<n1;i++)
    {
        sum += fire[i] + frost[i];
    }
    
    cout << sum << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}