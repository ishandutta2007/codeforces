#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#include<unordered_map>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 1e3;
const int INF = 1e9;
const int MOD = 1e9 + 7;
vector<int> pt;
int n , k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a , b;
    cin >> a >> b;
    if(b == a) cout << "1" << "\n";
    if(b - a == 1LL) cout << b % 10 << "\n";
    if(b - a == 2LL) cout << (((a + 1) % 10) * (b % 10)) % 10;
    if(b - a == 3LL) cout << (((a + 1) % 10) * (b % 10) * ((a + 2) % 10)) % 10;
    if(b - a == 4LL) cout << ((a + 1) % 10 * ((a + 2) % 10) * (b % 10) * ((a + 3) % 10)) % 10;
    if(b - a >= 5) cout << 0 << "\n";
    return 0;
}