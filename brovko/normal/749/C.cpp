#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, used[200005];
char a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int N = 20;
    int x = 0;
    int y = 0;

    while(N--)
    {
        for(int i = 0; i < n; i++)
        {
            if(used[i] == 0)
            {
                if(a[i] == 'D')
                {
                    if(x)
                    {
                        x--;
                        used[i] = 1;
                    }
                    else y++;
                }
                else
                {
                    if(y)
                    {
                        y--;
                        used[i] = 1;
                    }
                    else x++;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            cout << a[i];
            return 0;
        }
    }
}