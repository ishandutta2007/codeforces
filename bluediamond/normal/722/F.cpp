#include <bits/stdc++.h>

using namespace std;

bool home = 1;

//#define int ll

typedef long double ld;
//typedef long long ll;
typedef __int128 ll;

ll d;

pair<ll,ll>gcd(ll a,ll b){
  if(b==0){
    d=a;
    return {1,0};
  }else{
    auto it=gcd(b,a%b);
    return {it.second,it.first-(a/b)*it.second};
  }
}

pair<ll,ll>bad={(ll)1e18+11,(ll)1e18+11};

pair<ll,ll>solve(ll a,ll b, ll c){
  auto it=gcd(a,b);
  if(c%d)return bad;
  c/=d;
  it.first*=c;
  it.second*=c;
  return it;
}

ll solve(ll c1,ll r1,ll c2,ll r2){
  ll l=c1*c2/__gcd(c1,c2);
  auto it=solve(c1,-c2,r2-r1);
  if(it==bad)return -1;
  ll cox=c1*it.first+r1;
  cox%=l;
  if(cox<0)cox+=l;
  return cox;
}

pair<ll,ll>operator+(pair<ll,ll>a,pair<ll,ll>b){
  ll j=solve(a.first,a.second,b.first,b.second);
  if(j==-1)return bad;
  return {a.first*b.first/__gcd(a.first,b.first),j};
}


const int N=(int)1e5+7;
int lg[N];

int solve(vector<pair<ll,ll>> v){
  int sol=0;
  int n=(int)v.size(),kmax=log2(n)+1;
  vector<vector<pair<ll,ll>>> tab(kmax,vector<pair<ll,ll>>(n,{1,0}));
  for (int i=0;i<n;i++)tab[0][i]=v[i];
  for (int k=1;(1<<k)<=n;k++)for (int i=0;i+(1<<k)-1<n;i++){
    if(tab[k-1][i]==bad|tab[k-1][i+(1<<(k-1))]==bad)tab[k][i]=bad;else
      tab[k][i]=tab[k-1][i]+tab[k-1][i+(1<<(k-1))];
  }
  function<pair<ll,ll>(int,int)> get=[&](int l,int r){
    int k=lg[r-l+1];
    if(tab[k][l]==bad||tab[k][r-(1<<k)+1]==bad)return bad;
    return tab[k][l]+tab[k][r-(1<<k)+1];
  };
  int l=0;
  for (int i=0;i<n;i++){
    while(get(l,i)==bad)l++;
    sol=max(sol,i-l+1);
  }
  return sol;
  for (int i=0;i<(int)v.size();i++){
    pair<ll,ll>cur={1,0};
    for (int j=i;j<(int)v.size();j++){
      cur=cur+v[j];
      if(cur==bad)break;
      sol=max(sol,j-i+1);
    }
  }
  return sol;
}

int n,m,le[N];
vector<pair<int,int>>pz[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  for (int i=2;i<N;i++)lg[i]=1+lg[i/2];

  cin>>n>>m;
  for (int i=1;i<=n;i++){
    int k;
    cin>>k;
    le[i]=k;
    for (int j=0;j<k;j++){
      int x;
      cin>>x;
      pz[x].push_back({i,j});
    }
  }

  for (int x=1;x<=m;x++){
    int sol=0;
    int l=0;
    while(l<(int)pz[x].size()){
      int r=l;
      while(r+1<(int)pz[x].size()&&pz[x][r+1].first==pz[x][r].first+1)r++;
      vector<pair<ll,ll>> vals;
      for (int i=l;i<=r;i++)
        vals.push_back(
                       {le[pz[x][i].first],
                       pz[x][i].second});
      sol=max(sol,solve(vals));
      l=r+1;
    }
    cout<<sol<<"\n";
  }

  return 0;
}