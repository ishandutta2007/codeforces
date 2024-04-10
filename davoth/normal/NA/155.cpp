#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long int               ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define sz(x)                       (ll) x.size()
#define PB(x)                       push_back(x)
#define bs(a , x)                   binary_search(a , a + sizeof(a) / sizeof(a[0] , x)
#define ts(x)                       to_string(x)
#define jjoin(x)                    for (auto i : x) cout << i.F << " ";
#define all(x)                      (x).begin(),(x).end()
#define bsv(a , x)                  binary_search(all(a), x)
#define Sort(x)                     sort(all((x)))
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define kill(x)                     return cout << x << endl , 0;
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }
const ll MAXN = 1e6 + 10;
const ll MAXA = 101;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
const ld PI = 4*atan((ld)1);
ll b[MAXN] , oof[35], po[33];
void bib(ll x)
{
    for(ll i = 32 ; i >= 0 ; i--){
        if(x >= po[i]){
            x -= po[i];
            oof[i]++;
        }
    }
    return ;
}
int main()
{
    fast_io;
    set_random;
    ll n = input() , m = input();
    for (ll i = 0 ; i < 33 ; i++)
        po[i] = 1LL << i;
    for (ll i = 0 ; i < n ; i++)
    {
        ll t;
        cin >> t;
        bib(t);
    }
    for (ll i = 0 ; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b , b + m);
    bool flag = 0;
    for (ll i = 0 ; i < m ; i ++)
    {
        flag = 0;
        for (ll j = 0 ; j < 33 ; j++)
        {
            if (oof[j] >= 1 && j == b[i]){
                oof[j]--;
                flag = true;
                break;
            }
            if (oof[j] >= 1 && j > b[i]){
                oof[j] --;
                for(ll p=j-1; p>=b[i];p--) oof[p]++;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            kill(i);
        }
    }
    kill(m);
    return 0;
}