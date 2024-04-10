#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
#define F0R(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define RFOR(i, a, b) for(int i=a; i>=b; i--)
#define MN 54
#define pb push_back
#define ll long long
#define vll vector<ll>
int amt[MN];
vi cards[6]; //[5] is just comms
int status[MN]; //0 = out before, 1 = in, 2 = in twice, 3 = in three times

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a0, x, y, k, M;
    cin >> n >> a0 >> x >> y >> k >> M;
    
    ll MOD = 998244353;
    
    vll a(1, a0);
    for (int i = 1; i < n; i++){
        a.pb((a[i-1] * x + y) % M);
        //cout << a[i] << ' ';
    }
    
    int BIG = 16 * 9 * 5 * 7 * 11 * 13;
    //vll tot(BIG, 0);
    vll cnt(BIG, 0);
    ll tot = 0;
    
    for(ll v : a){
        tot += v;
        cnt[v % BIG] += 1;
    }
    tot %= MOD;
    
    ll ans = 0;
    
    for (int i = 1; i <= k; i++){
        vll ncnt(BIG, 0);
        
        ans *= n;
        ans %= MOD;
        
        ans += tot;
        tot *= n;
        for (int v = 0; v < BIG; v++){
            ncnt[v] += (n - 1) * cnt[v];
            
            int u = (v - (v % i));
            
            tot -= cnt[v] * (v % i);
            ncnt[u] += cnt[v];
        }
        
        for (int v = 0; v < BIG; v++){
            ncnt[v] %= MOD;
        }
        tot %= MOD;
        tot += MOD;
        tot %= MOD;
        
        cnt = ncnt;
    }
    
    cout << (ans % MOD);
}