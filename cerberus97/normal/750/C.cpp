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

const int N = 2e5 + 10;

int main()
{
    int n, lo = -1e8, hi = 1e8, ch = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int c, d;
        cin >> c >> d;

        if (d == 1)
        {
            if (lo < 1900-ch)
                lo = 1900-ch;
        }

        else
        {
            if (hi >= 1900-ch)
                hi = 1900-ch-1;
        }

        ch += c;
    }

    if (lo > hi)
    {
        cout << "Impossible\n";
    }

    else if (hi == 1e8)
    {
        cout << "Infinity\n";
    }

    else
    {
        cout << hi+ch << endl;
    }

    return 0;
}