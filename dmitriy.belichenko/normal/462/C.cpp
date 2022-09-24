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
char c[4][4];
const int N = 3e5 + 7;
bool check()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(c[i][j] == '.') return true;
        }
    }
     return false;
}
ll psum[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin() , a.rend());
    psum[0] = a[0];
    for(int i = 1 ; i < n; i++)
    {
        psum[i] += psum[i - 1] + a[i];
    }
    if(n == 1)
    {
        cout << psum[n - 1] << "\n";
        return  0;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += 1LL * psum[i];
      // cout << psum[i] << " ";
    }
   // cout << "\n";
    cout << ans + psum[n - 1] - a[0]<< "\n";
    
}