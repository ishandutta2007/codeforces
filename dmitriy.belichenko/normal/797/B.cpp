#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;


int main()
{
    int n;
    cin >> n;
    long long mn = 10000;
    long long mx= -10000;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if (a > 0) sum += a;
        if (a % 2)
        {
            if (a > 0) mn = min(mn, a);
            else mx = max(mx, a);
        }
    }
    
    long long ans = -10001;
    
    if (sum % 2) ans = sum;
    else {
        if (mn < 10000) ans = max(ans, sum - mn);
        if (mx > -10000) ans = max(ans, sum + mx);
    }
    
    cout << ans;
    return 0;
}