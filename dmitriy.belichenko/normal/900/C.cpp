#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define ll long long
const int MOD = 1e9 + 7;
const int N = 3e5;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int m1 = -1, m2 = -1, ind = -1;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > m1)
        {
            m2 = m1;
            m1 = a[i];
            ind = i;
            v[ind]--;
        }
        else if (a[i] > m2)
        {
            m2 = a[i];
            v[ind]++;
        }
    }
    int m = -N, ans = N;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > m)
        {
            m = v[i];
            ans = a[i];
        }
        else if (v[i] == m)
        {
            ans = min(a[i], ans);
        }
    }
    cout << ans << endl;
    return 0;
}