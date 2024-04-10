#include <bits/stdc++.h>

using namespace std;

bool home=1;
typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a,int b){
  a=add(a,b);
}

void mulup(int &a,int b){
  a=mul(a,b);
}

const int N=(int)1e6+7;
int n,perm[N],type[N];
bool eprim[N];

vector<int> divisors[N], primes, divisorstype[N];

void no(bool statement){
  if (statement)return;
  cout<<"0\n";
  exit(0);
}

int maps1[N];
int maps2[N];

int cnt1[N];
int cnt2[N];
int fact[N];
int pr[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  fact[0]=1;
  for (int i=1;i<N;i++)fact[i]=mul(fact[i-1],i);



  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>i[perm];
    pr[i]=1;
  }

  eprim[2]=1;
  for (int i=3;i<N;i+=2)eprim[i]=1;
  for (int i=3;i*i<N;i+=2)if (eprim[i])for (int j=i*i;j<N;j+=2*i)eprim[j]=0;

  for (int i=0;i<=n;i++){
    if (eprim[i])primes.push_back(i);
  }
  for (auto &p:primes){
    type[p]=n/p;
    for (int i=p;i<=n;i+=p)divisors[i].push_back(p),pr[i]*=p;
    for (int i=p;i<=n;i+=p)divisorstype[i].push_back(type[p]);
  }

  type[1]=1;
  divisors[1].push_back(1);
  divisorstype[1].push_back(1);


  for (int i=1;i<=n;i++) {
    if (!perm[i]) continue;
    no(divisorstype[i]==divisorstype[perm[i]]);
    auto v1=divisors[i];
    auto v2=divisors[perm[i]];
    for (int i=0;i<v1.size();i++){
      int p1=v1[i];
      int p2=v2[i];
      /// p1 maps to p2
      if (!maps1[p1]){
        maps1[p1]=p2;
      }
      if (!maps2[p2]){
        maps2[p2]=p1;
      }
      no(maps1[p1]==p2);
      no(maps2[p2]==p1);
    }
  }

  for (int i=1;i<=n;i++){
    if (maps1[i]==0){
      cnt1[type[i]]++;
    }
    if (perm[i]==0){
      cnt2[pr[i]]++;
    }
  }

  int sol=1;

  for (int i=1;i<=n;i++){
    sol=mul(sol,fact[cnt1[i]]);
    sol=mul(sol,fact[cnt2[i]]);
  }
  cout<<sol<<"\n";




  return 0;
}