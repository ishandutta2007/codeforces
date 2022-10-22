#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1005

int a[MAXN];
bool mk[MAXN];

int dfs(int u)
{
    mk[u]=1;
    if(!mk[a[u]])
        return dfs(a[u]);
    else
        return a[u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
    }

    for(int i=0;i<n;i++)
    {
        cout << dfs(i)+1 << ' ';
        for(int j=0;j<n;j++)
            mk[j]=0;
    }

    return 0;
}