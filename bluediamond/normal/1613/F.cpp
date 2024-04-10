#include <bits/stdc++.h>

using namespace std;

ostream& operator << (ostream& os, vector<int> v) {
  for (int i=0;i<(int)v.size();i++){
    if(i){
      os<<" ";
    }
    os<<v[i];
  }
  return os;
}


typedef long long ll;
const int M = 998244353;

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

const int B1=31;
const int B2=dv(1,B1);
const int P=1<<23;

int getlog2(int a){
  int sol=0;
  while (a>=2)sol++,a/=2;
  return sol;
}

void fft(vector<int> &a,bool inv){
  int n=(int)a.size(),k=getlog2(n);

  for (int i=0;i<n;i++){
    int j=0;
    for (int bit=0;bit<k;bit++){
      if(i&(1<<bit))j+=(1<<(k-1-bit));
    }
    if(i<j){
      swap(a[i],a[j]);
    }
  }
  for (int l=2;l<=n;l*=2){
    int muling=(inv)?B2:B1;
    for (int j=l;j<P;j*=2){
      mulup(muling,muling);
    }
    for (int i=0;i<n;i+=l){
      int cur=1;
      for (int j=0;j<l/2;j++){
        assert(i+l/2+j<n);
        int x=a[i+j],y=a[i+l/2+j];
        mulup(y,cur);
        mulup(cur,muling);
        a[i+j]=add(x,y);
        a[i+l/2+j]=add(x,-y);
      }
    }
  }
  if(inv){
    int kek=dv(1,n);
    for (auto &x:a)mulup(x,kek);
  }
}

vector<int>mul(vector<int>a,vector<int>b){
  int want=(int)a.size()+(int)b.size(),sz=1;
  while (sz<=want)sz*=2;
  a.resize(sz,0);
  b.resize(sz,0);
  fft(a,0);
  fft(b,0);
  for (int i=0;i<sz;i++)mulup(a[i],b[i]);
  fft(a,1);
  while (!a.empty()&&a.back()==0)a.pop_back();
  return a;
}

vector<int> brute(vector<int>a,vector<int>b){
  vector<int>sol((int)a.size()+(int)b.size(),0);
  for (int i=0;i<(int)a.size();i++){
    for (int j=0;j<(int)b.size();j++){
      addup(sol[i+j],mul(a[i],b[j]));
    }
  }
  while (!sol.empty()&&sol.back()==0)sol.pop_back();
  return sol;
}

const int N=250000+7;
int n,fact[N],down[N];
vector<int>g[N];
vector<int>v[N];
set<pair<int,int>>s;

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

 // freopen ("input","r",stdin);


  fact[0]=1;
  for (int i=1;i<N;i++)fact[i]=mul(fact[i-1],i);

  cin>>n;
  for (int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int i=1;i<=n;i++){
    down[i]=(int)g[i].size()-1;
  }
  down[1]++;
  for (int i=1;i<=n;i++){
    v[i]={1,down[i]};
    s.insert({(int)v[i].size(),i});
  }

  while ((int)s.size()>1){
    int i=s.begin()->second;
    s.erase(s.begin());
    int j=s.begin()->second;
    s.erase(s.begin());
    v[i]=mul(v[i],v[j]);
    s.insert({(int)v[i].size(),i});
  }

  int i=s.begin()->second;

  v[i].resize(n+1,0);
  int sol=0;
  for (int bad=0;bad<n;bad++){
    int cur=v[i][bad];
    mulup(cur,fact[n-bad]);
    if(bad&1)cur=-cur;
    addup(sol,cur);
  }
  cout<<sol<<"\n";
  return 0;
}