#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, l, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> l >> r;
    int k=0;
    int s1=0;
    int s2=0;
    for(int i=0;i<n;i++)
        if(k<l)
        {
            s1+=(1ll << k);
            k++;
        }
        else s1++;

    k=0;

    for(int i=0;i<n;i++)
    {
        if(k<r)
        {
            s2+=(1ll << k);
            k++;
        }
        else s2+=(1ll << (k-1));
    }

    cout << s1 << ' ' << s2;
}