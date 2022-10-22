#include<bits/stdc++.h>
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC optimization("O3")
using namespace std;

///Macros
#define int  long long
#define it(x) x::iterator
#define pb push_back
#define pf push_front
#define lb lower_bound
#define up upper_bound
#define fs first
#define sc second
#define endl '\n'
#define pf push_front
#define all(x) x.begin() , x.end()
#define sz(x) (int)(x.size())

#define FOR(i,a,n) for(int i=a;i<(n);i++)
#define FO(i,n) for(int i=0;i<(n);i++)
#define RFOR(i,a,n) for(int i=(n)-1;i>=a;i--)
#define RFO(i,n) for(int i=(n)-1;i>=0;i--)
#define gof(i,n) for(auto &i: n);

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

///Constraints:
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
const ull mod = 1000000007;
const ld pi = acos(-1);
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lg2ll(x) 63 - __builtin_clzll(x)
#define lgx(x,b) ( log(x) / log(b) )
#define YN(x) cout<<((x)?("YES"):("NO"))<<fl;
#define yn(x) cout<<((x)?("Yes"):("No"))<<fl;
/*void print(vector<int>v){for(auto that:v)cout<<that<<" ";cout<<endl;}
vector<int>read(int cnt){vi v(cnt);for(int i=0;i<cnt;i++)cin>>v[i];return v;}*/


/*#include<ext/pb_ds/assoc_container.hpp> // Common file
#include<ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
//comenta el define long long int
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
// find_by_order
// order_of_key



/// Quick Pow------------------------------------------------
int qpow(int b,int e)
{
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b %mod ;
    int pwur = qpow(b,e>>1);
    return pwur * pwur %mod;
}
///Inverso Modular
int InverM(int a,int b)
{
    int eso=a-(a/b)*b;
    if(eso==0)
        return 0;
    int ans=(1-b*InverM(b,eso))/eso;
    if(ans<0)
        ans+=b;
    return ans;

}

/// Variables------------------------------------------------
int tc,n,m,k,q;
vector<int> G[100001];
vector<ii> Ans;
void DFS(int u,int p,int t){
  int d=sz(G[u]);
   bool b=false;
    int cont=t;
    Ans.pb({u,t});
 for(auto v: G[u]){
 if(v==p)
 continue;
 if(cont==m){
 int d=sz(G[u]);
cont-=d;
Ans.pb({u,cont});
 }
 cont++;
 DFS(v,u,cont);
 Ans.pb({u,cont});

 }
 if(cont>=t){
 Ans.pb({u,t-1});
 }

}

void problem()
{
    cin>>n;
   for(int i=1;i<n;i++){
       int a,b;
       cin>>a>>b;
       G[a].pb(b);
       G[b].pb(a);
       m=max(m,sz(G[a]));
        m=max(m,sz(G[b]));
   }
   DFS(1,-1,0);
   Ans.erase(Ans.end()-1);
   cout<<sz(Ans)<<endl;
   for(auto a: Ans){cout<<a.fs<<' '<<a.sc<<endl;}
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(0);
    //freopen("a.in","w",stdin)
    //freopen("a.out","w",stdout);

    tc=1;
    while(tc--)
    {

        problem();
        cout<<endl;
    }

}





///Tips
//Busqueda Binaria
//Precomputing
//Dinamic Programming
//Revisar constraints