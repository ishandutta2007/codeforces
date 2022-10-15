#include <bits/stdc++.h>

using namespace std;
///#define int long long

bool home = 1;

class linearSieve { /// linear Sieve
public:
  vector<int> primes;
  vector<int> lp;
  void put(int Limit) {
    primes.clear();
    lp.clear();
    lp.resize(Limit + 1, 0);
    for (int i = 2; i <= Limit; i++) {
      if (!lp[i]) {
        lp[i] = i;
        primes.push_back(i);
      }
      for (int j = 0; j < (int) primes.size() && primes[j] * i <= Limit && primes[j] <= lp[i]; j++) {
        lp[primes[j] * i] = primes[j];
      }
    }
  }
} ls;

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  const int VMAX=5032107+7;
  const int INF=(int)1e9+7;
  ls.put(VMAX);

  int n,q;
  cin>>n>>q;
  vector<int> a(n);

  for(auto&x:a){
    cin>>x;
    int sol=1;
    while(x>1){
      int prime=ls.lp[x],cnt=0;
      while(x%prime==0){
        x/=prime;
        cnt++;
      }
      if(cnt&1){
        sol*=prime;
      }
    }
    x=sol;
  }

  /// 1 2 3 4 5  6  7
  /// 2 3 5 7 11 13 17
  vector<vector<int>> primes(n);

  for(int i=0;i<n;i++){
    int x=a[i];
    while(x>1){
      primes[i].push_back(ls.lp[x]);
      x/=ls.lp[x];
    }
  }

  vector<vector<int>> whensol(n, vector<int> (16,-INF));
  vector<vector<int>> last(VMAX,vector<int>(8,-INF));

  for(int i=0;i<n;i++){
    int sz=(int)primes[i].size();
    if(i) whensol[i]=whensol[i-1];
    for(int mask=0;mask<(1<<sz);mask++){
      int prod=1,cnt=0;
      for(int j=0;j<sz;j++){
        if(mask&(1<<j)){
          prod*=primes[i][j];
          cnt++;
        }
      }
      for (int j=0;j<8;j++){
        whensol[i][j+sz-cnt]=max(whensol[i][j+sz-cnt],last[prod][j]);
      }
      last[prod][sz-cnt]=i;

    }
  }

  while(q--){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    int sol=INF;
    for(int j=0;j<16;j++){
      if(whensol[r][j]>=l){
        sol=j;
        break;
      }
    }
    cout<<sol<<"\n";
  }

  return 0;
}