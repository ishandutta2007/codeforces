#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
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
const int MOD = 1e9 + 7;
const int N = 1e5;
using namespace std;
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int m = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != -1)
        {
            int cur = a[i];
           // a[i] = -1;
            for(int j = i + 1; j < n; j++)
            {
                if(a[j] != -1 && a[j] < cur)
                {
                    cur = a[j];
                    a[j] = -1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] != -1) ans++;
    }
    cout << ans << "\n";
}