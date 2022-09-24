
#include <iostream>
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
const long long N = 2e3+5;
int g[N][N];

long long gcd(long long  a,long long b)
{
    if (b == 0)
    {
        return a;
    }
    
    else
    {
        return gcd(b, a % b);
    }
}
 bool pri( int k)
{
    if( k == 1) return false;
    for(int i = 2; i * i <= k; i++)
    {
        
        if( k % i == 0) return false;
    }
    return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        //std::cout << "Hello, World!\n";
    int n , m ;
    cin >> n ;
    int a[100005];
    int mn = 1e9+3;
    int mx = -1;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(a[i] , mn);
        mx = max(a[i] , mx);

    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i]!= mn && a[i] != mx) ans++;
    }
    cout << ans;
       return 0;
}