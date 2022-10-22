//! Oos Karim Rokhsat
#include<bits/stdc++.h>
using namespace std;

typedef double                      ld;
typedef long long                   ll;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define F                           first
#define S                           second
#define sep                         ' '
#define endl                        '\n'
#define file_io                     freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define error(x)                    cerr << "$$$ " << x << '\n';
#define error2(x,y)                 cerr << "#F : " << x << "      #S : " << y << '\n';
#define kill(x)                     return cout << x << endl , 0;
#define pb                          push_back

const ll MXN = (1LL << 18) + 10;
const ll MXM = 100 + 10;
const ll MX5 = 1e5 + 10;
const ll MX6 = 1e6 + 10;
const ll LOG = 20;
const ll INF = 8e18;
const ld eps = 1e-9;
const ll MOD = 1e9 + 7; //998244353;

ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
ll bmm(ll a,ll b){
    return (a%b==0 ? b : bmm(b,a%b));
}
string base2(ll n){
    string a="";while(n>=2){a+=(char)(n%2+'0');n/=2;}a+=(char)(n+'0');reverse(all(a));return a;
}


ll n, m, dp[MXN][MXM], Cnt[LOG];
string s;

int main(){
    fast_io
    //file_io
    cin >> s >> m;
    n = (int)s.size();

    dp[0][0] = 1;

    for(int mask = 0; mask < (1LL << n); mask ++){
        for(int j = 0; j < n; j ++){
            for(int mod = 0; mod < m; mod ++){
                if(mask & (1LL << j)) continue;
                if(mask || (s[j] - '0')){
                    dp[mask | (1LL << j)][(mod * 10 + (s[j] - '0')) % m] += dp[mask][mod];
                }
            }
        }
    }

    ll cnt = 1;
    for (ll i = 0; i < n ; i++) {
        cnt *= ++Cnt[s[i] - '0'];
    }

    ll ans = dp[(1LL << n) - 1][0] / cnt;
    cout << ans << endl;

    return 0;
}

//! N.N