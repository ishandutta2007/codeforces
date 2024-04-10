#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=(int)1e9+7;
const int FACTN=300000+7;
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
const int N=(int)1e6+7;
int f[N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int n;
  cin>>n;
  for (int i=1;i<=n;i++) {
    int x;
    cin>>x;
    f[x]++;
  }
  for (int bit=0;bit<20;bit++) {
    for (int i=1;i<N;i++) {
      if(f[i]&&(i&(1<<bit))){
        f[i-(1<<bit)]+=f[i];
      }
    }
  }

  for (int i=0;i<N;i++){
    f[i]=add(pw(2,f[i]),-1);
  }

  int sol=0;

  for (int i=0;i<N;i++) {
    int coef=1;
    for(int bit=0;(1<<bit)<=i;bit++){
      if(i&(1<<bit)){
        coef*=-1;
      }
    }
    if(coef==1){
      addup(sol,f[i]);
    }else{
      assert(coef==-1);
      addup(sol,-f[i]);
    }
  }
  cout<<sol<<"\n";


}