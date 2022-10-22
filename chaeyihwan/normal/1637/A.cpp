#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[10002];

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    int j=1;
    bool b = false;
    for(int i=2;i<=n;i++)
    {
        if(a[i] > a[i-1]) j = i;
        if(a[i] < a[i-1])
        {
            b = true;
            break;
        }
    }

    if(!b)
    {
        cout << "NO\n";
        return;
    }

    for(int i=j;i<=n-i+j;i++)
    {
        swap(a[i], a[n-i+j]);
    }

    bool flag = true;

    for(int i=2;i<=n;i++)
    {
        if(a[i] > a[i-1]) flag = false;
    }

    if(!flag) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}