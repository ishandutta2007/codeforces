#include <iostream>
#include <cstdio>
#include <utility>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <bitset>
#include <fstream>
using namespace std;
int main()
{
    long long n ;
    int k;
    cin >> n >> k;
    vector<long long> a(k);
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    int ind = 1;
    long long ost = 1e18;
    for(int i = 0; i < k; i++)
    {
        ost = min(ost , n % a[i]);
        if(ost == n % a[i])
        {
            ans = n / a[i];
            ind = i + 1;
        }
    }
    cout << ind << " " << ans << "\n";
    return 0;
}