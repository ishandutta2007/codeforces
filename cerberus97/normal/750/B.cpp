/*
Author : Cerberus97
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define fast_cin() ios_base::sync_with_stdio(false);

const int N = 55;

int main()
{
    int n, st = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int t;
        string s;
        cin >> t >> s;

        if (s[0] == 'N')
        {
            if (st - t < 0)
            {
                cout << "NO" << endl;
                return 0;
            }

            st -= t;
        }

        else if (s[0] == 'S')
        {
            if (st + t > 20000)
            {
                cout << "NO" << endl;
                return 0;
            }

            st += t;
        }

        else if (st == 0 or st == 20000)
        {
            cout << "NO\n";
            return 0;
        }
    }

    if (st)
        cout << "NO\n";

    else
        cout << "YES\n";

    return 0;
}