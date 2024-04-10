#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int k, c[10];
string s;

int f()
{
    int ans = 1;

    for(int i = 0; i < 10; i++)
        ans *= c[i];

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    s = "codeforces";

    while(true)
    {
        for(int i = 0; i < 10; i++)
        {
            if(f() >= k)
            {
                for(int j = 0; j < 10; j++)
                    while(c[j]--)
                        cout << s[j];

                return 0;
            }

            c[i]++;
        }
    }
}