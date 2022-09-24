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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    vector<int> a(k);
    int mx = -1;
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        mx = max(a[i] , mx);
        
    }
    if(mx > 25)
    cout << mx - 25 << "\n";
    else cout << 0;
    return 0;
}