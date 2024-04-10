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
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , d;
    cin >> n >> d;
    vector<int> a(n) , suff(n + 1);
    for(int i = 0; i  < n; i++)
    {
        cin >> a[i];
    }
    suff[n] = -1e9 - 1;
    vector<int> pref(n);
    pref[0] = a[0];
   if(a[0] > d)
{
cout << -1;
return 0;
}
    for(int i = 1; i< n; i++)
    {
        pref[i] =pref[i - 1] + a[i];
        if(pref[i] > d)
        {
            cout << -1;
            return 0;
        }
    }
    for(int i  = n - 1 ; i >= 0; i--)
    {
        suff[i] = max(pref[i] , suff[i + 1]);
    }
    int b = 0;
    int sum = 0;
    for(int i  = 0; i < n; i++)
    {
        if(a[i] == 0 && pref[i] < -b)
        {
            int to = d - b - suff[i];
            b += to;
            sum ++;
            if(pref[i] < -b)
            {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << sum << "\n";
}