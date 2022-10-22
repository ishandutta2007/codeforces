#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, p[100005], a[100005], up[100005][30], is_new[100005], ans[100005], pos[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        up[i][0] = p[i];

    for(int j = 1; j < 30; j++)
        for(int i = 0; i < n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    for(int i = 0; i < n; i++)
        is_new[i] = 1;

    for(int i = 0; i < n; i++)
        is_new[p[i]] = 0;

    int k = 0, Max = 0;

    for(int i = 0; i < n; i++)
        if(is_new[i])
        {
            k++;
            Max = a[i];
        }

    int T = max(0, (Max - n) / k);

//    cout << "!" << T << endl;

    for(int i = 0; i < n; i++)
    {
        int x = i;

        for(int j = 0; j < 30; j++)
            if(T & (1 << j))
                x = up[x][j];

        pos[i] = x;
    }

//    for(int i = 0; i < n; i++)
//        cout << pos[i] << ' ';
//
//    cout << endl;

    set <int> s;

    for(int i = 0; i < n; i++)
        s.insert(i + 1);

    for(int i = 0; i < n; i++)
        if((*s.lower_bound(a[pos[i]])) == a[pos[i]])
        {
            ans[i] = (*s.lower_bound(a[pos[i]]));
            s.erase(ans[i]);
        }

    for(int i = 0; i < n; i++)
        if(ans[i] == 0)
        {
            ans[i] = (*s.lower_bound(a[pos[i]]));
            s.erase(ans[i]);
        }

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}