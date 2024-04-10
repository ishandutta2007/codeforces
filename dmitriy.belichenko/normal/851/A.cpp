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

const int N = 1e5;
const int INF = 1e9;
ll MOD =  1000000007;

int main()
{
    ::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , k , t;
    cin >> n >> k >> t;
    if (t < k + 1) cout << t ;
    else if (t < n + 1) cout << k;
    else cout << n + k - t;
    return 0;
}