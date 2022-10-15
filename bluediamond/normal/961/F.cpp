#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;

typedef long long ll;
const ll M=(ll)1e18+3;


ll add(ll a,ll b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}

ll mul(ll a,ll b){
  return a*(__int128)b%M;
}

ll pw(ll a, ll b) {
  ll r=1;
  while (b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}

ll dv(ll a,ll b){
  return mul(a,pw(b,M-2));
}

const int N=(int)1e6+7;
const ll B=103;
ll pt[N],pref[N],inv[N];
int n,a[N];
string s;

ll get(int l,int r){
  ll sol=add(pref[r],-pref[l-1]);
  return mul(sol,inv[l-1]);
}

int sol[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
    //freopen ("testing place","w",stdout);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  pt[0]=1;
  for (int i=1;i<N;i++)pt[i]=mul(pt[i-1],B);
  inv[N-1]=dv(1,pt[N-1]);
  for (int i=N-2;i>=0;i--)inv[i]=mul(inv[i+1],B);

  cin>>n>>s;
  for (int i=1;i<=n;i++){
    a[i]=s[i-1]-'a';
    pref[i]=add(pref[i-1],mul(pt[i-1],a[i]));
    sol[i]=-1;
  }

  for (int c=1;2*c<=n;c++){
    int lo=1,hi=c;
    while (lo<=hi){
      int l=(lo+hi)/2;
      if (get(l,2*c-l)==get(n+1-2*c+l,n-l+1)){
        sol[l]=c;
        hi=l-1;
      }else {
        lo=l+1;
      }
    }
  }

  for (int i=1;i<=(n+1)/2;i++){
    if (sol[i]!=-1){
      sol[i]=2*(sol[i]-i)+1;
    }
  }
  for (int i=1;i<=(n+1)/2;i++) {
    if (i>1)sol[i]=max(sol[i-1]-2,sol[i]);
    cout<<sol[i]<<" ";
  }
  cout<<"\n";


  return 0;
}