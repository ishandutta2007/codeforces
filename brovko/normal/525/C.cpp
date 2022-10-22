#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[100005], k[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        k[a[i]]++;

    sort(a, a + n);

    for(int i = n - 1; i >= 0; i--)
    {
        if(k[a[i]] % 2)
        {
            k[a[i]]--;
            a[i]--;
            k[a[i]]++;
        }
    }

    int l = 1e6;
    int ans = 0;

    for(int r = 1e6; r >= 0; r--)
    {
        l = min(l, r);

        if(l == r)
        {
            ans += k[l] / 4 * l * l;
            k[l] %= 4;
            l--;
        }

        if(k[r] >= 2)
        {
            while(l >= 0 && k[l] < 2)
                l--;
        }

//        if(k[r] >= 2)
//            cout << r << ' ' << l << endl;

        if(l < 0)
            break;

        while(k[r] >= 2 && k[l] >= 2)
        {
            k[r] -= 2;
            k[l] -= 2;
            ans += l * r;
        }
    }

    cout << ans;
}