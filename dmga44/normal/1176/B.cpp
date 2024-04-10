#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAXN 105

ll dp[MAXN],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,a;
        cin >> n;
        int f[3];
        f[0]=f[1]=f[2]=0;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            f[a%3]++;
        }
        db(f[0]+min(f[1],f[2])+(f[1]+f[2]-2*(min(f[1],f[2])))/3)
    }

    return 0;
}