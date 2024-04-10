#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll

typedef long long ll;
typedef long double ld;


int f(int k) {
  vector<pair<int, int>> facs;
  for (int i = 2; i * i <= k; i++) {
    int cnt = 0;
    while (k % i == 0) {
      cnt++;
      k /= i;
    }
    if (cnt) {
      facs.push_back({i, cnt});
    }
  }
  if (k > 1) {
    facs.push_back({k, 1});
  }
  int sol = 1;
  for (auto &it : facs) {
    int cur = 1;
    for (int j = 1; j <= it.second; j++) {
      cur *= it.first;
    }
    sol *= (cur + 1);
  }
  return sol;
}

const int L = (int) 1e6 + 777;
bool pr[L];
vector<int> primes;

const int inf=(int)1e18;

int mul(int a, int b) {
  if (a==0||b==0)return 0;
  if(a<=inf/b)return a*b;
  return inf;
}

int pw(int a, int b){
  int r=1;
  while (b){
    if (b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}

bool isprime(int x) {
  if (x<=1) return 0;
  for (auto &p:primes){
    if (p*p>x)break;
    if (x%p==0) return 0;
  }
  return 1;
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ///
  }

  pr[2] = 1;
  for (int i = 3; i < L; i += 2) pr[i] = 1;

  for (int i = 3; i * i < L; i += 2) {
    if (pr[i]) {
      for (int j = i * i; j < L; j += 2 * i) {
        pr[j] = 0;
      }
    }
  }
  for (int i = 1; i < L; i++) {
    if (pr[i]) {
      primes.push_back(i);
    }
  }

  int n;
  cin >> n;
  vector<pair<int, int>>tog;
  unordered_map<int, int> code;
  vector<int> divis;
  vector<int> dp;
  {


    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divis.push_back(i);
        if (i * i == n) continue;
        divis.push_back(n / i);
      }
    }
    sort(divis.begin(), divis.end());
    vector<int> w((int) divis.size(),0);
    for (int i = 0; i < (int) divis.size(); i++) {
      code[divis[i]]=i;
      int val=divis[i]-1;
      if (isprime(val)) {
        w[i]=val;
        continue;
      } else {
        for (int pt=2;pw(2,pt)<=val&&w[i]==0;pt++){
          int l=0,r=(int)primes.size()-1;
          while (l<=r) {
            int md=(l+r)/2;
            int p=primes[md];
            int kek=pw(p,pt);
            if (kek==val){
              w[i]=p;
              break;
            }
            if (kek<val)l=md+1;
            else r=md-1;
          }
        }
      }
    }
    /**for (int i=0;i<(int) divis.size();i++) {
      cout<<"--->"<<divis[i]<<" : "<<w[i]<<"\n";
    }**/
    for (int i=0;i<(int) divis.size();i++) {
      if (w[i]) {
        tog.push_back({w[i],divis[i]});
      }
    }
    dp.resize((int)divis.size(),0);
  }
  sort(tog.begin(),tog.end());
  dp[code[1]]=1;
  int l=0;
  while (l<(int) tog.size()) {
    int r=l;
    while (r+1<(int) tog.size()&&tog[r+1].first==tog[r].first)r++;
    for (int i=(int)dp.size()-1;i>=0;i--){
      int x=divis[i];

      for (int j=l;j<=r;j++){
        int val=tog[j].second;
        if (x%val==0) {
          dp[i]+=dp[code[x/val]];
        }
      }
    }
    l=r+1;
  }
  cout<<dp.back()<<"\n";
  return 0;
}