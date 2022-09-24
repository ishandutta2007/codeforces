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
#define mp make_pair
#define pb push_back
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[2005];
    int b[2005];
       int cnt = 0;
    for (int i = 0; i <  n; i++) {
        cin >> a[i];
        b[i] = a[i];
        if(a[i] == 1) cnt++;
    }
    int p = a[0];
    bool flag = 0;
    for(int i = 0; i < n ; i++)
    {
        p = __gcd(p , a[i]);
    }
    if(p != 1)
    {
        cout << -1;
        return 0;
    }
   if( cnt)
   {
       cout << n - cnt <<"\n";
       return 0;
   }
    int k = 1e9;
    int ans =   1e9;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = i; j < n; ++j)
        {
            k = __gcd(k, a[j]);
            if (k == 1)
            {
                ans = min(ans, j - i + n - 1);
                break;
            }
        }
    }
    cout << ans;
}