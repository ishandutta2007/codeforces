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

int chk[1002];
int d[1002];
int uf[1002];

int f(int x)
{
    if(x == uf[x]) return x;
    return uf[x] = f(uf[x]);
}
void u(int x, int y)
{
    x = f(x); y = f(y);
    uf[x] = y;
}

int ask(int x)
{
    cout << "? " << x << endl;
    int k; cin >> k;
    return k;
}

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) chk[i] = 0;
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=1;i<=n;i++) uf[i] = i;
    
    while(true)
    {
        int now = 0;
        for(int i=1;i<=n;i++)
        {
            if(chk[i] == 0 && d[i] >= d[now]) now = i;
        }
        if(now == 0) break;
        chk[now] = 1;
        for(int j=1;j<=d[now];j++)
        {
            int adj = ask(now);
            u(adj, now);
            if(chk[adj]) break;
            else chk[adj] = 1;
        }
    }
    
    cout << "! ";
    for(int i=1;i<=n;i++) cout << f(i) << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}