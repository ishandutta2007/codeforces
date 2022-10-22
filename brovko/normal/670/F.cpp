#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

string s;
int a[10];

int kc(int n)
{
    if(n == 0)
        return 1;

    int ans = 0;

    while(n)
    {
        n /= 10;
        ans++;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    if(s == "10" || s == "01")
    {
        cout << 0;
        return 0;
    }

    int n = 1;

    while(n + kc(n) < s.size())
        n++;

    for(auto to:s)
        a[to - '0']++;

    while(n)
    {
        a[n % 10]--;
        n /= 10;
    }

    string t;

    cin >> t;

    for(auto to:t)
        a[to - '0']--;

    vector <string> v;

    string z = "0123456789";

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < a[i]; j++)
            v.push_back(z.substr(i, 1));

    int x = 0;

    for(auto to:t)
    {
        if(to > t[0] && x == 0)
            x = 2;

        if(to < t[0] && x == 0)
            x = 1;
    }

    if(x == 1)
        t = z.substr(t[0] - '0' - 1, 1) + t;
    else t = t.substr(0, 1) + t;

    v.push_back(t);

    sort(v.begin(), v.end());

    x = 0;

    while(v[x][0] == '0' && !(v[x].size() > 1 && v[x][1] == '1'))
        x++;

    string ans1 = "";

    if(v[x].size() == 1)
        ans1 += v[x];
    else ans1 += v[x].substr(1, v[x].size() - 1);

    for(int i = 0; i < v.size(); i++)
        if(i != x)
            {
                if(v[i].size() == 1)
                    ans1 += v[i];
                else ans1 += v[i].substr(1, v[i].size() - 1);
            }

    if(x + 1 < v.size())
    {
        x++;

        string ans2 = "";

        if(v[x].size() == 1)
            ans2 += v[x];
        else ans2 += v[x].substr(1, v[x].size() - 1);

        for(int i = 0; i < v.size(); i++)
            if(i != x)
                {
                    if(v[i].size() == 1)
                        ans2 += v[i];
                    else ans2 += v[i].substr(1, v[i].size() - 1);
                }

        ans1 = min(ans1, ans2);
    }

    cout << ans1;
}