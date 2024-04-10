
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

int field[1000][1000];

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
int n , m;
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
    int n;
    cin >> n;
    vector<long long>a(n);
    
    for(int i =0; i< n; i++)
    {
        cin >> a[i];
    }
    long long mn = LONG_MAX;
    sort(a.begin(), a.end());
    for(int i = 0;i < n-1; i++ )
    {
        mn = min(abs(a[i]-a[i+1]) , mn);
    }
   // for(int i = 0; i < n; i++) cout <<a[i] << " ";
    int cnt = 0;
    for(int i =0;i < n-1; i++)
    {
        if(abs( a[i] - a[i+1]) == mn) cnt++;
    }
    //if(abs( a[0] - a[n-1]) == mn) cnt++;

    cout << mn << " " << cnt<< endl;
    return 0;
}