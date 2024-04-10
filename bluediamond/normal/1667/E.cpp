#include <bits/stdc++.h>

bool home=1;

using namespace std;

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

const int N=(int)4e5+7;
int n;
int fact[N];
int ifact[N];
int value[N];
int guy[N];

int comb(int n,int k){
  assert(0<=k&&k<=n&&n<N);
  return mul(fact[n],mul(ifact[k],ifact[n-k]));
}

int ways[N],www[N];

const int P=31;
const int DIM=1<<23;
const int IP=dv(1,P);

void fft(vector<int> &a,bool inv){
  int n=(int)a.size();
  int k=0;
  while((1<<k)<n) k++;
  assert((1<<k)==n);

  for (int i=0;i<n;i++){
    int j=0,sc=0;
    for(int bit=0;bit<k;bit++){
      if(i&(1<<bit)){
        j+=(1<<(k-1-bit));
        sc+=(1<<bit);
      }
    }
    if(i>j) continue;
    swap(a[i],a[j]);
  }

  for(int l=2;l<=n;l*=2){
    int mlt=((inv)?(IP):(P));
    for(int k=l;k<DIM;k*=2) mlt=mul(mlt,mlt);
    for(int i=0;i<n;i+=l){
      int cur=1;
      for(int j=0;j<l/2;j++){
        int x=a[i+j];
        int y=mul(cur,a[i+l/2+j]);
        a[i+j]=add(x,y);
        a[i+l/2+j]=add(x,-y);
        mulup(cur,mlt);
      }
    }
  }

  if(inv){
    int invn=dv(1,n);
    for(auto&x:a){
      mulup(x,invn);
    }
  }
}

vector<int> smart_conv(vector<int> a, vector<int> b){
  int n=1;
  while(n<=(int)a.size()+(int)b.size()) n*=2;

  a.resize(n,0);
  b.resize(n,0);

  fft(a,0);
  fft(b,0);

  for(int i=0;i<n;i++) mulup(a[i],b[i]);

  fft(a,1);
  return a;
}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif

  fact[0]=1;
  for(int i=1;i<N;i++) fact[i]=mul(fact[i-1],i);
  ifact[N-1]=dv(1,fact[N-1]);
  for(int i=N-2;i>=0;i--) ifact[i]=mul(ifact[i+1],i+1);


  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }


  cin>>n;
  assert(n%2==1);
  int limit=(n-1)/2;

  {
    ways[0]=www[0]=1;
    int cur=1;

    for (int i=1;i<=n;i++){
      if(i-limit-1>=0){
        addup(cur,-www[i-limit-1]);
      }
      ways[i]=mul(fact[i-1],cur);
      www[i]=mul(ifact[i],ways[i]);
      addup(cur,www[i]);
    }

    for(int k=n-limit;k<=n;k++){
      value[k]=1;
      mulup(value[k],ways[k-1]);
      mulup(value[k],ifact[k-1]);
      mulup(value[k],fact[n-k-1]);
    }

  }

  {
    cout<<ways[n-1]<<" ";
  }

  n++;
  {
    for (int k=0;k<=n;k++){
      guy[k+n]=ifact[k];
    }
  }

  vector<int> x,y;
  for(int i=0;i<=2*n;i++) x.push_back(value[i]), y.push_back(guy[i]);

  vector<int> z=smart_conv(x,y);


  for (int i=2;i<n;i++){
    cout<<mul(z[2*n-i],mul(i-1,fact[n-1-i]))<<" ";
  }
  cout<<"\n";
}