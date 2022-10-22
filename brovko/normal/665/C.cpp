#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == s[i + 1])
        {
            char c = 'a';

            if(i + 2 < s.size())
                c = s[i + 2];

            s[i + 1] = 'a';

            if(s[i] == 'a' || c == 'a')
                s[i + 1]++;

            if((s[i] == 'b' || c == 'b') && s[i + 1] == 'b')
                s[i + 1]++;
        }
    }

    cout << s;
}