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
int MOD = 1e9 + 7;
using namespace std;
map<int, double > bi;
long long sum(long long a, long long b)
{
    a += b;
    return a % MOD;
    if (a >= MOD)
        return a - MOD;
    else return a ;
}
long long mult(long long a, long long b)
{
    long long c = 1LL * a * b;
    return c % MOD;
}
int poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
long long tolong(const string &s)
{
    long long res = 0;
    for(int i  = 0; i < s.size(); i++)
    {
        res += (s[i] - '0') * pow(10 , s.size() - i - 1);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c , n , k;
    cin >> n >> k >> c;
    int seed = 239;
    //cin >> seed;
    vector<int> a(k);
    srand(time(0));
//    for(int i = 0; i < k; i++)
//    {
//        a[i] = rand() % c + 1;
//    }
   // for(int i = 0; i < k; i++) cout << a[i] << " ";
   // cout << "\n";
    vector<int> arr(n + 1 , 1e9);
    arr[0] = 0;
  //  cout << "\n";
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
       // int dir = rand() % 2;
        int dir;
        //cin >> dir;
        if(a[i] <= c / 2) dir = 0;
        else dir = 1;
        if(dir == 0)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(arr[j] > a[i])
                {
                    arr[j] = a[i] ;
                    cout << j << endl;
                    break;
                }
            }
        }
        else
        {
            for(int j = n ; j >= 1; j--)
            {
                if(arr[j] < a[i] || arr[j] == 1e9)
                {
                    arr[j] = a[i] ;
                    cout << j << endl;
                    break;
                }
            }
        }
//        for(int j = 1; j <= n; j++)
//        {
//            if(arr[j] != 1e9)
//                cerr << arr[j] << " ";
//            else cerr<< '-' << " ";
//        }
//        cerr << "\n";
      if(is_sorted(arr.begin() + 1 , arr.end()))
      {
          if(*max_element(arr.begin() + 1, arr.end()) != 1e9)
         // cout << i << endl;
          return 0;
      }
        
    }
    return 1;
    
}