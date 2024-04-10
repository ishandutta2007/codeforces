#include <bits/stdc++.h>

bool home = 1;

using namespace std;

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

struct Secv{
  ll first;
  ll dif;
  ll cnt;
};

bool is_in_secv(Secv s, ll x){
  x-=s.first;
  if(x<0) return 0;
  if(x%s.dif) return 0;
  x/=s.dif;
  return x<s.cnt;
}

ll get_first(Secv s) {
  return s.first;
}

ll get_last(Secv s){
  return s.first+s.dif*(s.cnt-1);
}

Secv read_secv() {
  int first,dif,cnt;
  cin>>first>>dif>>cnt;
  return {first, dif, cnt};
}

vector<ll> get_divis(ll x) {
  vector<ll> sol;
  for (ll i=1;i*i<=x;i++){
    if(x%i==0){
      sol.push_back(i);
      if(i*i==x) continue;
      sol.push_back(x/i);
    }
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int tests;
  cin>>tests;
  for (int tc=1;tc<=tests;tc++){
    Secv b=read_secv();
    Secv c=read_secv();
    bool ok=0;

    if(c.dif%b.dif==0){
      ok=(is_in_secv(b,get_first(c))&&is_in_secv(b,get_last(c)));
    }
    if(!ok){
      cout<<"0\n";
      continue;
    }
    if(!is_in_secv(b,get_first(c)-c.dif)) {
      cout<<"-1\n";
      continue;
    }
    if(!is_in_secv(b,get_last(c)+c.dif)) {
      cout<<"-1\n";
      continue;
    }
    vector<ll> divis_dif=get_divis(c.dif);
    ll sol=0;
    for (auto &dif:divis_dif){
      if(dif*b.dif/__gcd(dif,b.dif)!=c.dif) continue;
      sol=(sol+(c.dif/dif)*(c.dif/dif))%M;
    }
    cout<<sol<<"\n";
  }

}