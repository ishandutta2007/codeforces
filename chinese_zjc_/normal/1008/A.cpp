//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
string yuan = "aeiou";
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != 'n' && yuan.find(s[i]) >= yuan.length())
        {
            if (s.length() == i + 1 || yuan.find(s[i + 1]) >= yuan.length())
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}