#include <bits/stdc++.h>

using namespace std;


const int N=(int)2e5+100+7;
const int L=N-7;
int n;
int q;
int a[N];
int lazy_set[4*N];

struct T{
  int sum;
  int len;
  int pref0;
  int pref1;
  int suf0;
  int suf1;
};

T gol;
T t[4*N];

T operator + (T a, T b){
  int sum=a.sum+b.sum;
  int len=a.len+b.len;
  int pref0=a.pref0+b.pref0*(a.pref0==a.len);
  int pref1=a.pref1+b.pref1*(a.pref1==a.len);
  int suf0=b.suf0+a.suf0*(b.suf0==b.len);
  int suf1=b.suf1+a.suf1*(b.suf1==b.len);

  return {sum,len,pref0,pref1,suf0,suf1};
}

void build(int v,int tl,int tr){
  lazy_set[v]=-1;
  if(tl==tr){
    t[v]=gol;
    t[v].len=1;
    t[v].pref0=1;
    t[v].suf0=1;
  }else{
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=t[2*v]+t[2*v+1];
  }
}

void push(int v,int tl,int tr){
  if(lazy_set[v]!=-1){
    t[v].sum=lazy_set[v]*(tr-tl+1);
    assert(lazy_set[v]==0||lazy_set[v]==1);
    if(lazy_set[v]==0){
      t[v].pref1=t[v].suf1=0;
      t[v].pref0=tr-tl+1;
      t[v].suf0=tr-tl+1;
    }else{

      t[v].pref0=t[v].suf0=0;
      assert(lazy_set[v]==1);
      t[v].pref1=tr-tl+1;
      t[v].suf1=tr-tl+1;
    }
    if(tl<tr){
      lazy_set[2*v]=lazy_set[v];
      lazy_set[2*v+1]=lazy_set[v];
    }
    lazy_set[v]=-1;
  }
}

void make_set(int v,int tl,int tr,int l,int r,int x){
  push(v,tl,tr);
  if(tr<l||r<tl)return;
  if(l<=tl&&tr<=r){
    lazy_set[v]=x;
    push(v,tl,tr);
    return;
  }
  int tm=(tl+tr)/2;
  make_set(2*v,tl,tm,l,r,x);
  make_set(2*v+1,tm+1,tr,l,r,x);
  t[v]=t[2*v]+t[2*v+1];
}

T get(int v,int tl,int tr,int l,int r){
  push(v,tl,tr);
  if(tr<l||r<tl)return gol;
  if(l<=tl&&tr<=r){
    return t[v];
  }
  int tm=(tl+tr)/2;
  return get(2*v,tl,tm,l,r)+get(2*v+1,tm+1,tr,l,r);
}

void build(){
  build(1,1,L);
}

void make_set(int l,int r,int x){
  make_set(1,1,L,l,r,x);
}

T get(int l,int r){
  return get(1,1,L,l,r);
}

/**
111111111110 => +
000000000001 =>


000000000001 => -
111111111110

**/

void add(int x){

  int sol=x+get(x,L).pref1;
  if(x<=sol-1){
    make_set(x,sol-1,0);
  }
  make_set(sol,sol,1);
}

void sub(int x){
  int sol=x+get(x,L).pref0;
  if(x<=sol-1){
    make_set(x,sol-1,1);
  }
  make_set(sol,sol,0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen("___input___.txt","r",stdin);
  cin>>n>>q;
  build(1,1,L);
  for(int i=1;i<=n;i++){
    cin>>a[i];

    add(a[i]);
  }
  for(int iq=1;iq<=q;iq++){
    int k,x;
    cin>>k>>x;
    sub(a[k]);
    a[k]=x;
    add(a[k]);
    cout<<L-get(1,L).suf0<<"\n";
  }
}