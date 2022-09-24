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


vector< vector<pair<int, int> > >g;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        ll n, k;
        cin>> n >>k;
        ll t = 1LL;
        for (int i=0; i<k; i++)
            t *= 10;
        ll ans=0;
        cout<<(t*n)/__gcd(t,n);
    }