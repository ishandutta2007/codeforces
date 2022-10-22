#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[100005], b[100005], k0;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    k0=n;

    for(int i=0;i<m;i++)
        {
            cin >> a[i];
            if(b[a[i]]==0)
                k0--;
            b[a[i]]++;

            if(k0==0)
            {
                cout << 1;
                for(int j=1;j<=n;j++)
                {
                    b[j]--;
                    if(b[j]==0)
                        k0++;
                }
            }
            else cout << 0;
        }
}