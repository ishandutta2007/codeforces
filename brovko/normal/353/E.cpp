#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    int n = str.size();

    vector <int> used(n);
    int y = 0;

    for(int i = 0; i < n; i++)
    {
        if(str[i] != str[(i + 1) % n])
            used[i] = ++y;
        else used[i] = 0;
    }

//    for(int i = 0; i < n; i++)
//        cout << used[i] << ' ';
//
//    cout << endl;

    set <int> s;

    for(int i = 1; i <= y; i++)
        s.insert(i);

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(used[i] != 0 && used[(i + 1) % n] == 0)
        {
            ans++;

            if(s.find(used[i]) != s.end())
                s.erase(used[i]);

            if(s.find(used[i] % y + 1) != s.end())
                s.erase(used[i] % y + 1);
        }
    }

    for(int i = 1; i <= 2 * y; i++)
    {
        int j = i;

        if(j > y)
            j -= y;

        if(s.find(j) != s.end())
        {
            ans++;

            s.erase(j);

            if(s.find(j % y + 1) != s.end())
                s.erase(j % y + 1);

            if(s.find(j == 1 ? y : j - 1) != s.end())
                s.erase(j == 1 ? y : j - 1);
        }
    }

    cout << ans;
}