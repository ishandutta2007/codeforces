
#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define int long long
using namespace std;
typedef vector<int> vi;
#define y1 abacaba
#define left sefude
//#define right sefudermano
typedef long long ll;
typedef pair<int,int> pii;
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll a,ll b,ll m){
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
 
const int N = 400100;
set<int> a[N],b[N];
 
 
struct node{
  ll mx,mn;
  bool flag;
  node operator+(const node &o) const{  // exemplo de operador de merge
    node r;
    r.flag = (flag || o.flag || (mn <= o.mx));
    r.mx = max(mx,o.mx);
    r.mn = min(mn,o.mn);
    return r;
  }
  node(){}
}tree[4*N];
 
 
void upd(int no,int i,int j,int p,node val){
  if(i == j){
    tree[no] = val;
    return;
  }
  int mid = (i + j) >> 1,l = no << 1 ,r = no << 1 | 1;
  if(p<=mid)upd(l,i,mid,p,val);
  else upd(r,mid+1,j,p,val);
  tree[no] = tree[l] + tree[r];
 
}
node query(){
  return tree[1];
}
 
 
const ll inf = 1e9;
int32_t main(){
  fastio;
  int n,m,q;
  cin >> n >> m >> q;
  for(int i=0;i<=n;i++){
    a[i].insert(2*m+1);
    b[i].insert(-1);
  }
  map<pii,int> used;
  
  for(int x=0;x<n;x++){
      node novo;
      novo.mx = *b[x].rbegin();
      novo.mn = *a[x].begin();
      novo.flag = novo.mn <= novo.mx;
      upd(1,0,n-1,x,novo);
  }
  
  while(q--){
    int x,y;
    cin>>x>>y;
    x--;
    if(used[pii(x,y)]){
      used[pii(x,y)] = 0;
      if(x%2==0){
        a[x/2].erase(y);
      }else b[x/2].erase(y);
    }else{
      used[pii(x,y)] =1 ;
      if(x%2==0)a[x/2].insert(y);
      else b[x/2].insert(y);
    }
    
    node novo;
    novo.mx = *b[x/2].rbegin();
    novo.mn = *a[x/2].begin();
    novo.flag = novo.mn <= novo.mx;
 
    upd(1,0,n-1,x/2,novo);
    int res = query().flag;
    cout << (res==0 ? "YES" : "NO")<<endl;  
  }
 
  // math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}