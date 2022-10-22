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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int a, b;
vector<int> A, B;
bool used[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b;
    for (int i = 1; i <= 100000; ++i)
    {
        if (a <= 0)
        {
            break;
        }
        a -= i;
        A.push_back(i);
        used[i] = true;
    }
    if (a < 0)
    {
        A.erase(find(A.begin(), A.end(), -a));
        used[-a] = false;
        a = 0;
    }
    for (int i = 1; i <= 100000; ++i)
    {
        if (used[i])
        {
            continue;
        }
        if (i <= b)
        {
            b -= i;
            B.push_back(i);
            used[i] = true;
        }
    }
    cout << A.size() << endl;
    for (auto i : A)
    {
        cout << i << ' ';
    }
    cout << endl
         << B.size() << endl;
    for (auto i : B)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}