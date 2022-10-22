#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int hh, mm;

int f(int x, int y)
{
    if(x / 10 == 7 || x % 10 == 7 || y / 10 == 7 || y % 10 == 7)
        return 1;
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    cin >> hh >> mm;
    int k = 0;

    while(f(hh, mm) == 0)
    {
        k++;
        mm -= x;
        if(mm < 0)
        {
            hh--;
            mm += 60;
        }

        if(hh < 0)
            hh += 24;
    }

    cout << k;
}