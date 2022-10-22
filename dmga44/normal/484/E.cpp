    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
/// Macros:
//#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
/// Constraints:
const int maxn = 100010;
const int mod = 1000000007;
const int mod2 = 10007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Functions------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
mt19937_64 r(time(0));
int rng (int a, int b){
    return uniform_int_distribution<int>(a,b)(r);
}
/// My Code -------------------------------------------------

int a[maxn], imp[maxn], ans[maxn], n, m;
vector<ii> compress;
vector<pair<ii,ii>> q;
vector<int> upd[maxn];
struct node{
    int l, r, mx, sz;
    node(int _sz,int _l,int _r,int _mx){
        sz = _sz;
        l = _l;
        r = _r;
        mx = _mx;
    }
    node(){
        l = r = mx = sz = 0;
    }
};
node st[maxn*4];

node merge_(node a,node b){
    node c = node();

    c.sz = a.sz + b.sz;

    c.l = a.l;
    if( a.l == a.sz ) c.l = a.l + b.l;

    c.r = b.r;
    if( b.r == b.sz ) c.r = b.r + a.r;

    c.mx = max( a.mx , b.mx );
    c.mx = max( c.mx , a.r + b.l );

    return c;
}

void build(int nod,int l,int r){
    if( l == r ){
        st[nod] = node(1,0,0,0);
        return;
    }
    int mi = ( l + r ) >> 1;
        build(2*nod,l,mi);
        build(2*nod+1,mi+1,r);
    st[nod] = merge_( st[2*nod] , st[2*nod+1] );
}

void update(int nod,int l,int r,int id,int val){
    if( l == r ){
        st[nod] = node(1,val,val,val);
        return;
    }
    int mi = ( l + r ) >> 1;

    if( id <= mi )
        update(2*nod,l,mi,id,val);
    else
        update(2*nod+1,mi+1,r,id,val);

    st[nod] = merge_( st[2*nod] , st[2*nod+1] );
}

node query(int nod,int l,int r,int x,int y){
    if( l > y || r < x ) return node(0,0,0,0);
    if( l >= x && r <= y ) return st[nod];
    int mi = ( l + r ) >> 1;
    return merge_( query(2*nod,l,mi,x,y) , query(2*nod+1,mi+1,r,x,y) );
}

void dandc(int l,int r,vector<pair<ii,ii>> qu){
    if( l == r ){
        for( auto i : qu )
            ans[i.s.s] = l;
        return;
    }
    int mi = ( l + r + 1 ) >> 1;

    vector<pair<ii,ii>> ql, qr;
    for( auto i : qu ){
        if( query(1,1,n,i.f.f,i.f.s).mx >= i.s.f ) qr.pb(i);
            else ql.pb(i);
    }

    int nl = l, nr = mi - 1;
    int nmi = ( nl + nr + 1 ) / 2;

    for(int i=mi-1; i>=nmi; i--)
        for( auto j : upd[i] )
            update(1,1,n,j,1);

    dandc(nl,nr,ql);

    for(int i=mi-1; i>=nmi; i--)
        for( auto j : upd[i] )
            update(1,1,n,j,0);

    nl = mi, nr = r;
    nmi = ( nl + nr + 1 ) / 2;

    for(int i=mi; i<nmi; i++)
        for( auto j : upd[i] )
            update(1,1,n,j,0);

    dandc(nl,nr,qr);

    for(int i=mi; i<nmi; i++)
        for( auto j : upd[i] )
            update(1,1,n,j,1);

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n;

    compress.pb({-1,-1});
    for(int i=1; i<=n; i++){
        cin >> a[i];
        compress.pb({a[i],i});
    }

    sort(all(compress));
    int curr = 0;
    for(int i=1; i<compress.size(); i++){
        if( compress[i].f != compress[i-1].f ){
            curr ++;
            imp[curr] = a[compress[i].s];
        }
        a[compress[i].s] = curr;
    }

    for(int i=1; i<=n; i++){
        upd[a[i]].pb(i);
    }

    cin >> m;

    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        q.pb({{u,v},{w,i}});
    }

    build(1,1,n);

    for(int i=100000; i>=(100000+1+1)/2; i--){
        for( auto j : upd[i] )
            update(1,1,n,j,1);
    }
    dandc(1,100000,q);

    for(int i=1; i<=m; i++){
        cout << imp[ans[i]] << '\n';
    }

    return 0;
}