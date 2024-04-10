

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
//#include "optimization.h"
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 500;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;
int n , m;

int main()
{
    ll ans = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<pair<int , int> > sz(3);
    int x1 , x2 , y1 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ans = 2 * (abs(x1 - x2) + 1) + 2 * (abs(y1 - y2) + 1);
    if(x1 - x2 == 0)
    {
        ans = 4 + 2 * (abs(y1 - y2) + 1);
    }
    if(y1 - y2 == 0)
    {
        ans = 4 + 2 * (abs(x1 - x2) + 1);
    }
    if(x1 == x2 && y1 == y2 ) ans = 0;
    cout << ans << "\n";
    return 0;
}