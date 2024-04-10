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
const int N = 200005;
int n , x, a[N], psum[N];
ll ans;

int main()
{
    int n;
    map<int , int> cnt;
    cin >> n;
    vector<int> h(n);
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int p = 0;
    for(int i = 0; i < n; i++)
    {
        p = min(p , h[i] - i - 1);
        ans[i] = p + i + 1;
    }
    p = n + 1;
    for(int i = n - 1; i >= 0; i--)
    {
        p = min(p , h[i] + i + 1);
        ans[i] = min(ans[i] , p - i - 1);
    }
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
    //    cout << ans[i] << " ";
        res = max(ans[i] * 1LL , res);
    }
    cout << res << "\n";
    return 0;

}