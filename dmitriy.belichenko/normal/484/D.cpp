#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <functional>
#include <iomanip>
#include <queue>
#include <numeric>
#include <bitset>
#include <iterator>
#define double long double
#define ll long long
#define pb push_back
using namespace std;
const double PI = acos(-1);
const int N = 2e6 + 10;
ll a[N] , pref[N];
ll low , high;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >>  n;
    int mn = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mn = a[0];
    high = a[0];
    low = -mn;
    for(int i = 0; i < n ; i++)
    {
        int peek = a[i];
        pref[i] = max(0LL , max(low + peek , high - peek));
        low = max(low , pref[i] - a[i + 1]);
        high = max(high , pref[i] + a[i + 1]);
    }
    cout << pref[n - 1] << "\n";
}