#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a, k[10];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int f = 0;

    for(int i = 0; i < 6; i++)
    {
        cin >> a;
        k[a]++;

        if(k[a] == 4)
        {
            k[a] -= 4;
            f = 1;
        }
    }

    if(f == 0)
    {
        cout << "Alien";
        return 0;
    }

    for(int i = 0; i < 10; i++)
        if(k[i] == 2)
        {
            cout << "Elephant";
            return 0;
        }

    cout << "Bear";
}