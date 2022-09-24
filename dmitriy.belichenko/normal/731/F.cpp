#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
#include<bitset>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#define fst first
#define snd second
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define sq(a) (long double)a * a
using namespace std;
typedef long long ll;
const int N = 1e7;
int n , x, a[N], psum[N];
ll ans ;
int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        a[p]++;
    }
    for(int i = 2e5 + 1 ; i > 0; i--)
    {
        psum[i] = psum[i + 1] + a[i];
    }
    for(int i = 1 ; i <= 2e5 + 1 ; i++)
    {
        if(a[i] > 0)
        {
            ll sum = 0;
            for(int j = i ; j <= 2e5 + 1; j += i)
            {
              sum += 1LL * ( psum[j] - psum[j + i] ) * j;
              ans = max(ans , sum);
            }
        }
    }
    cout<< ans << "\n";
    return 0;
}