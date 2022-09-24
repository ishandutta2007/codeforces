
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
const int MOD = 2e9 + 7;
const int N = 3e5;
using namespace std;
vector<long long> sqr;
int a[N] , b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int left = b[0];
    if (a[0] != 0)
    {
        cout << "no";
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] > left)
        {
            cout << "no";
            return 0;
        }
        left = max(left, b[i]);
    }
    if (left < m)
    {
        cout << "no";
        return  0;
    }
    cout << "yes";
    return 0;
}