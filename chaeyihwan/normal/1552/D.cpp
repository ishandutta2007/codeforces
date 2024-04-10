#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool flag = false;
int a[10], n;

void _find(int i, int now)
{
    if(i == n-1)
    {
        if(now == a[n-1]) flag = true;
        return;
    }
    _find(i+1, now + a[i]);
    _find(i+1, now);
    _find(i+1, now - a[i]);
}

void solve()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    flag = false;
    for(int i=0;i<n;i++)
    {
        _find(0, 0);
        swap(a[i], a[n-1]);
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}