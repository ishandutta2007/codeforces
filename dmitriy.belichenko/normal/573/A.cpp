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
    vector<ll> a(n);
    cin >> a[0];
    ll t = a[0];
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
        t = __gcd(a[i] , t);
        cnt[a[i]]++;
    }
    //cout << t << "\n";
    for(int i = 0; i < n; i++)
    {
        a[i] = a[i] / t;
     //   cout << a[i] << "\n";
        while(a[i] % 2 == 0) a[i] /= 2;
        while(a[i] % 3 == 0) a[i] /= 3;
        if(a[i] != 1)
        {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;

}