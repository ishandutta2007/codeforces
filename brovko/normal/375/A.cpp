#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s;

int f()
{
    int ans = 0;

    for(int i = 0; i < s.size(); i++)
        ans = (ans * 10 + s[i] - '0') % 7;

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();

    int pos1 = 0, pos6 = 0, pos8 = 0, pos9 = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
            pos1 = i;

        if(s[i] == '6')
            pos6 = i;

        if(s[i] == '8')
            pos8 = i;

        if(s[i] == '9')
            pos9 = i;
    }

    s[pos1] = '9';
    s[pos6] = '9';
    s[pos8] = '9';
    s[pos9] = '9';

    sort(s.rbegin(), s.rend());

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                for(int l = 0; l < 4; l++)
                    if((1 << i) + (1 << j) + (1 << k) + (1 << l) == 15)
                    {
                        s[i] = '1';
                        s[j] = '6';
                        s[k] = '8';
                        s[l] = '9';

                        if(!f())
                        {
                            cout << s;
                            return 0;
                        }
                    }
}