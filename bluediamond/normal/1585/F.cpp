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

const int N=(int)2e5+7;
int n,init[N],len[N],stop[N];
int tree[4*N],lazy_a[4*N],lazy_b[4*N],sl[4*N];

void build(int v,int tl,int tr) {
  lazy_a[v]=1;
  lazy_b[v]=0;
  if(tl==tr){
    tree[v]=(len[tl])*(tl<=stop[1])%M;
    sl[v]=len[tl]%M;
  }else{
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    tree[v]=add(tree[2*v],tree[2*v+1]);
    sl[v]=add(sl[2*v],sl[2*v+1]);
  }
}

void push(int v,int tl,int tr) {
  if(lazy_a[v]!=1||lazy_b[v]!=0) {
    tree[v]=mul(lazy_a[v],tree[v]);
    addup(tree[v],mul(lazy_b[v],sl[v]));
    if (tl<tr){
      for (int v2=2*v;v2<=2*v+1;v2++) {
        mulup(lazy_a[v2],lazy_a[v]);
        mulup(lazy_b[v2],lazy_a[v]);
        addup(lazy_b[v2],lazy_b[v]);
      }
    }
    lazy_a[v]=1;
    lazy_b[v]=0;
  }
}

void apl(int v,int tl,int tr, int l,int r,int aa,int bb) {
  push(v,tl,tr);
  if(tr<l||r<tl) return;
  if(l<=tl&&tr<=r){

    lazy_a[v]=aa;
    lazy_b[v]=bb;
    push(v,tl,tr);
    return;
  }
  int tm=(tl+tr)/2;
  apl(2*v,tl,tm,l,r,aa,bb);
  apl(2*v+1,tm+1,tr,l,r,aa,bb);
  tree[v]=add(tree[2*v],tree[2*v+1]);
}

void apl(int l,int r,int aa,int bb){
  if(l>r)return;
  apl(1,1,n,l,r,aa,bb);
}

int get() {
  push(1,1,n);
  return tree[1];
}

void print(int v,int tl,int tr){
  push(v,tl,tr);
  if(tl<tr) {
    int tm=(tl+tr)/2;
    print(2*v,tl,tm);
    print(2*v+1,tm+1,tr);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  vector<int> so;
  cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>init[i];
    so.push_back(init[i]);
  }
  {
    sort(so.begin(), so.end());
    so.resize(unique(so.begin(),so.end())-so.begin());
    int last=0;
    for (int i=1;i<=(int)so.size();i++){
      len[i]=so[i-1]-last;
      last=so[i-1];
    }
  }

  for (int i=1;i<=n;i++) {
    stop[i]=lower_bound(so.begin(),so.end(),init[i])-so.begin()+1;
  }
  {
    build(1,1,n);
  }
  {
    for (int iter=2;iter<=n;iter++) {
      int x=stop[iter];
      push(1,1,n);

      int p=get();


      apl(1,n,add(0,-1),p);
      apl(x+1,n,0,0);


    }
  }
  {
    cout<<get()<<"\n";
  }
}