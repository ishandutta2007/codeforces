#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a;
    cin >> n >> m;
    int f[2],g[2];
    f[0]=f[1]=g[0]=g[1]=0;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        f[a&1]++;
    }

    for(int i=0;i<m;i++)
    {
        cin >> a;
        g[a&1]++;
    }

    int res=min(g[0],f[1])+min(g[1],f[0]);

    db(res)

    return 0;
}