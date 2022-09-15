#include <iostream>
using namespace std;

typedef long long ll;
#define FOR(i, n) for(ll i = 0; i < n; i++)
#define FOR2(i, a, b) for(ll i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

ll m;
ll h[2], a[2], x[2], y[2];
ll cycle[2], firstcyc[2], firsatis[2];
ll g[1000000];

ll fm(ll h, ll k){
    return (x[k] * h + y[k]) % m;
}

void findcycle(ll k){
    int buf = h[k];
    FOR(i, m) {buf = fm(buf, k);}
    int buf2 = buf;
    FOR(i, m) {buf2 = fm(buf2, k); if (buf2 == buf) {cycle[k] = i + 1; return;}}
}

void findfirst(ll k){
    
    ll f = h[k];
    g[0] = h[k];
    FOR(i, m + 1) {f = fm(f, k); g[i + 1] = f; if (i >= cycle[k] && f == g[i - cycle[k]]) {firstcyc[k] = i - cycle[k] - 1; return;}}
}

ll u, v, d;

void Euclid(ll a, ll b){
	if (b == 0){u = 1; v = 0; d = 1; return;}
	Euclid(b, a % b); ll x1 = v; ll y1 = u - (a / b) * v; u = x1; v = y1;
}

void solve(){
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    cin>>m>>h[0]>>a[0]>>x[0]>>y[0]>>h[1]>>a[1]>>x[1]>>y[1];
    findcycle(0); findcycle(1); findfirst(0); findfirst(1);
    firsatis[0] = firsatis[1] = -1;
    int buf = h[0]; FOR(i, m + cycle[0]) {if (buf == a[0]) {firsatis[0] = i; break;} buf = fm(buf, 0);}
    buf = h[1]; FOR(i, m + cycle[1]) {if (buf == a[1]) {firsatis[1] = i; break;} buf = fm(buf, 1);}
	if (firsatis[0] <= firstcyc[0] && firsatis[1] <= firstcyc[1]) {if (firsatis[0] == firsatis[1]) cout<<firsatis[0]; else cout<<-1; return;}
	if (firsatis[0] <= firstcyc[0] && firsatis[1] > firstcyc[1]) {if (firsatis[0] > firstcyc[1] && firsatis[0] % cycle[1] == firsatis[1] % cycle[1]) cout<<firsatis[0]; else cout<<-1; return;}
	if (firsatis[0] > firstcyc[0] && firsatis[1] <= firstcyc[1]) {if (firsatis[1] > firstcyc[0] && firsatis[1] % cycle[0] == firsatis[0] % cycle[0]) cout<<firsatis[1]; else cout<<-1; return;}
	Euclid(cycle[0], cycle[1]); ll gc = gcd(cycle[0], cycle[1]);
	if (firsatis[0] % gc != firsatis[1] % gc) {cout<<-1; return;}
	ll k = (firsatis[1] - firsatis[0]) / gc * u;
	ll lc = lcm(cycle[0], cycle[1]);
	ll i = 0;
	while (1) {if (k * cycle[0] + i * lc + firsatis[0] > firsatis[1]) {ll j = (k * cycle[0] + i * lc + firsatis[0]) % lc; while (j <= MAX(firstcyc[0], firstcyc[1])) j += lc; cout<<j ; return;} i++;}
}

int main(){
    solve();
    return 0;
}