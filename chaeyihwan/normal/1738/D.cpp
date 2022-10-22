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

int a[100002], b[100002];
int inv[100002];
vector<int> v[100002];

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=0;i<=n+1;i++) inv[i] = 0;
    for(int i=1;i<=n;i++) inv[b[i]] = 1;
    
    int now = n+1;
    for(int i=1;i<=n;i++) if(b[i] == 0) now = 0;
    
    for(int i=0;i<=n+1;i++) v[i].clear();
    
    for(int i=1;i<=n;i++)
        v[b[i]].push_back(i);
    
    int id = 1;
    int cnt = 0;
    bool flag = true;
    if(now == 0) flag = false;
    while(id <= n)
    {
        int nxt;
        for(int i : v[now])
            if(inv[i]) nxt = i;
        
        for(int i : v[now])
        {
            if(i != nxt) a[id++] = i;
            if(flag) cnt++;
        }
        
        a[id++] = nxt;
        now = nxt;
        flag = !flag;
    }
    
    cout << cnt << "\n";
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}