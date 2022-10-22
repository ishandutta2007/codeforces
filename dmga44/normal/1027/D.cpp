#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

int a[MAXN],c[MAXN],res,r[MAXN];
bool mk[MAXN];

void solve(int u)
{
    r[u]=c[u];
    int p=a[u];
    while(p!=u)
    {
        r[u]=min(r[u],c[p]);
        p=a[p];
    }
    res+=r[u];
}

void dfs(int u)
{
    mk[u]=1;
    if(!mk[a[u]])
        dfs(a[u]);
    else if(!r[a[u]])
        solve(a[u]);
    r[u]=r[a[u]];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> c[i];
    for(int i=0;i<n;a[i]--,i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        if(!mk[i])
            dfs(i);
    db(res)

    return 0;
}