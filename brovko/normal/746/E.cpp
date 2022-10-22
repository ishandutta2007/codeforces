#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[200005], kc, k;
map <int, int> used;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        used[a[i]]++;

        if(a[i] % 2 == 0)
            kc++;
    }

    int x = 1;
    int y = 2;

    for(int i = 0; i < n; i++)
        if(used[a[i]] >= 2)
        {
            k++;
            used[a[i]]--;

            if(a[i] % 2 == 0)
                kc--;

            if(kc >= n / 2)
            {
                while(used[x])
                    x += 2;

                if(x > m)
                {
                    cout << -1;
                    return 0;
                }

                used[x]++;

                a[i] = x;
            }
            else
            {
                while(used[y])
                    y += 2;

                if(y > m)
                {
                    cout << -1;
                    return 0;
                }

                used[y]++;
                kc++;

                a[i] = y;
            }
        }

    for(int i = 0; i < n; i++)
        {

            if(kc > n / 2 && a[i] % 2 == 0)
            {
                while(used[x])
                    x += 2;

                if(x > m)
                {
                    cout << -1;
                    return 0;
                }

                used[x]++;
                kc--;

                a[i] = x;
                k++;
            }
            else if(kc < n / 2 && a[i] % 2 != 0)
            {
                while(used[y])
                    y += 2;

                if(y > m)
                {
                    cout << -1;
                    return 0;
                }

                used[y]++;
                kc++;

                a[i] = y;
                k++;
            }
        }

    cout << k << "\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}