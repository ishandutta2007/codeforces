#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int r[50002][5];

bool cmp(int x, int y)
{
    int cnt = 0;
    for(int i=0;i<5;i++) if(r[x][i] < r[y][i]) cnt++;
    if(cnt >= 3) return 1;
    else return 0;
}

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<5;j++) cin >> r[i][j];
    }

    int now = 1;
    for(int i=2;i<=n;i++)
    {
        if(!cmp(now, i)) now = i;
    }

    bool flag = true;
    for(int i=1;i<=n;i++)
    {
        if(i == now) continue;
        if(!cmp(now, i)) flag = false;
    }

    if(flag) cout << now << "\n";
    else cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}