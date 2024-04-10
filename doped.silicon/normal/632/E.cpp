// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
int n = sz(a), L = 31 - __builtin_clz(n);
static vector<complex<long double>> R(2, 1);
static vector<C> rt(2, 1); // (^ 10% fas te r i f double)
for (static int k = 2; k < n; k *= 2) {
R.resize(n); rt.resize(n);
auto x = polar(1.0L, acos(-1.0L) / k);
rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
}
vi rev(n);
rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
for (int k = 1; k < n; k *= 2)
for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
C z = rt[j+k] * a[i+j+k]; // (25% fas te r i f handro l led )
a[i + j + k] = a[i + j] - z;
a[i + j] += z;
}
}
typedef vector<ll> vl;
vl convMod(const vl &a, const vl &b, ll M) {
if (a.empty() || b.empty()) return {};
vl res(sz(a) + sz(b) - 1);
int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
vector<C> L(n), R(n), outs(n), outl(n);
rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
fft(L), fft(R);
rep(i,0,n) {
int j = -i & (n - 1);
outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
}
fft(outl), fft(outs);
rep(i,0,sz(res)) {
ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
}
return res;
}

#define pb push_back

vector<ll>vx,v;
ll M=1002938241;
vector<ll> power(vector<ll>res,ll y)
{
    if(y==0)
    {
        return vx;
    }
    vector<ll> aa= power(res,y/2);
    aa=convMod(aa,aa,M);
    if(y&1)
    {
        aa=convMod(aa,res,M);
    }
    return aa;
}
void solve()
{   
    ll n,m;
    cin>>n>>m;
    v.clear();
    for(int i=0;i<1001;i++)
    {
        v.pb(0);
    }
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v[x]=1;
    }
    vx.pb(1);
    vector<ll>ans=power(v,m);
    M=1000000007;
    // rep(i,min((ll)1000*m+1,(ll)ans.size()))
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i])
        {
            cout<<i<<' ';
        }
    }
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++)
    {
        solve();
    }
}