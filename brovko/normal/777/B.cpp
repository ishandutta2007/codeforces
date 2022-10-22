#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, used1[15], used2[15], used3[15];
char c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        used1[c - '0']++;
    }

    for(int i = 0; i < n; i++)
    {
        cin >> c;
        used2[c - '0']++;
    }

    int k1 = n;
    int k2 = 0;

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < used1[i]; j++)
    {
        int x = i;

        while(x < 10 && used2[x] == used3[x])
            x++;

        if(x < 10)
        {
            used3[x]++;
            k1--;
        }
    }

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < used1[i]; j++)
    {
        int x = i + 1;

        while(x < 10 && used2[x] == 0)
            x++;

        if(x < 10)
        {
            used2[x]--;
            k2++;
        }
    }

    cout << k1 << "\n" << k2;
}