#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=998244353;
int add(int a,int b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}
int mul(int a,int b){
  return a*(ll)b%M;
}
int add(int a,int b,int c){
  return add(add(a,b),c);
}
int mul(int a,int b,int c){
  return mul(mul(a,b),c);
}
int add(int a,int b,int c,int d){
  return add(add(a,b,c),d);
}
int mul(int a,int b,int c,int d){
  return mul(mul(a,b,c),d);
}
int add(int a,int b,int c,int d,int e){
  return add(add(a,b,c,d),e);
}
int mul(int a,int b,int c,int d,int e){
  return mul(mul(a,b,c,d),e);
}
int add(int a,int b,int c,int d,int e,int f){
  return add(add(a,b,c,d,e),f);
}
int mul(int a,int b,int c,int d,int e,int f){
  return mul(mul(a,b,c,d,e),f);
}
int add(int a,int b,int c,int d,int e,int f,int g){
  return add(add(a,b,c,d,e,f),g);
}
int mul(int a,int b,int c,int d,int e,int f,int g){
  return mul(mul(a,b,c,d,e,f),g);
}
int add(int a,int b,int c,int d,int e,int f,int g,int h){
  return add(add(a,b,c,d,e,f,g),h);
}
int mul(int a,int b,int c,int d,int e,int f,int g,int h){
  return mul(mul(a,b,c,d,e,f,g),h);
}
int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}
int dv(int a,int b){
  return mul(a,pw(b,M-2));
}
void addup(int &a,int b){
  a=add(a,b);
}
void mulup(int &a,int b){
  a=mul(a,b);
}
void dvup(int &a,int b){
  a=dv(a,b);
}

const int P=31;
const int IP=dv(1,P);
const int L=1<<23;

void fft(vector<int>&a,int k,bool inv){
  int n=(1<<k);
  for(int i=0;i<n;i++){
    int j=0;
    for(int bit=0;bit<k;bit++){
      if(i&(1<<bit)){
        j+=(1<<(k-1-bit));
      }
    }
    if(i<j){
      swap(a[i],a[j]);
    }
  }
  for(int l=2;l<=n;l*=2){
    int mlt=((inv)?(IP):(P));
    for(int j=l;j<L;j*=2)mlt=mlt*(ll)mlt%M;
    for(int i=0;i<n;i+=l){
      int cur=1;
      for(int j=0;j<l/2;j++){
        int x=a[i+j];
        int y=a[i+l/2+j];
        y=y*(ll)cur%M;
        cur=cur*(ll)mlt%M;
        a[i+j]=x+y;
        if(a[i+j]>=M)a[i+j]-=M;
        a[i+l/2+j]=x-y;
        if(a[i+l/2+j]<0)a[i+l/2+j]+=M;
      }
    }
  }
  if(inv){
    int mlt=dv(1,n);
    for(auto&x:a)x=x*(ll)mlt%M;
  }
}
vector<int>conv_smart(vector<int>a,vector<int>b){
  int k=0;
  while((1<<k)<(int)a.size()+(int)b.size())k++;
  a.resize((1<<k),0);
  b.resize((1<<k),0);
  fft(a,k,0);
  fft(b,k,0);
  for(int i=0;i<(1<<k);i++)a[i]=a[i]*(ll)b[i]%M;
  fft(a,k,1);
  return a;
}

int main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE


  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int n, xx, yy;
  cin >> n >> xx >> yy;
  vector<int> a(xx + 1, 0), b(xx + 1, 0);
  for (int i = 0; i <= n; i++) {
    int p;
    cin >> p;
    assert(0 <= p && p <= xx);
    assert(0 <= xx - p && xx - p <= xx);
    a[p] = 1;
    b[xx - p] = 1;
  }
  vector<int> prod = conv_smart(a, b);
  int limit = (int) 1e6 + 7;
  vector<int> solution(limit + 1, -1);
  for (int w = 1; w <= limit; w++) {
    if (w % 2 == 0) {
      int dif = w / 2 - yy;
      if (dif > 0) {
        /// a[i] - a[j] = dif
        /// a[i] + (x - a[j]) = x + dif
        if (xx + dif < (int) prod.size() && prod[xx + dif]) {
          for (int i = w; i <= limit; i += w) {
            solution[i] = w;
          }
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l;
    cin >> l;
    cout << solution[l] << " ";
  }
  cout << "\n";
  return 0;
}