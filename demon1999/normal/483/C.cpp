#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define r_s(a, j) a.resize(j)
#define p_b(a, j) a.push_back(j)
#define sz(a) a.size()
#define forn(i, n) for(int i = 0; i < n; i++)
#define fork(i, j, n) for(int i = j; i < n; i++)
#define ford(i, n) for(int i = n - 1; i >= 0; i--)
#define ford1(i, j, n) for(int i = n - 1; i >= j; j--)
typedef long long ll;
using namespace std;
const long ma = 131072;
ll k, n;
int main()
{
    cin >> n >> k;
    forn(i, k + 1)
    {
        if(i % 2 == 0)cout << i / 2 + 1 << " ";
        else cout << k + 1 - i / 2 << " ";
    }
    fork(i, k + 1, n)
        cout << i + 1 << " ";
    return 0;
}