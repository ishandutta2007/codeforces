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
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 4e5;
const int INF = 1e9;
ll MOD =  1000000007;
ll ans = 0LL;
pair <ll, int> a[400005];
ll flight[400005];
set <pair <ll, int> > price;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int u , v;
        cin >> u;
        v = i;
        u-= 2 * u;
        pair<ll, int> p = mp(1LL * u  , v);
        a[i] = p;
        if(i < k) price.insert(a[i]);
    }
    
        for (int i = k; i < n + k ; i++)
        {
            int index = 0;
            if (i < n)
            {
                price.insert(a[i]);
                index = price.begin()->snd;
            }
            else
            {
                index = price.begin()->snd;
            }
            flight[index] = i + 1;
            price.erase(price.begin());
        }
    
    for (int i = 0; i < n; i++)
    {
        ll payment = 1LL * (-a[i].first);
        ans += payment * (1LL * (flight[i] - i - 1));
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << flight[i] << " ";
    }
    return 0;
}