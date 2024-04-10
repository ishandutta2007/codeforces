#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, Max, k;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int x = -1;
    while(x < n)
    {
        cin >> s;
        x += s.size() + 1;

        k = 0;
        for(auto to:s)
            if(to >= 'A' && to <= 'Z')
                k++;
        Max = max(Max, k);
    }

    cout << Max;
}