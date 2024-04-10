#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int M;

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

const int N=80+7;
int comb[N][N],aleg_distinct[N][N],total[N][N], bad[N][N]; /// total[i][j] = length i and their or has j bits

int main() {
#ifndef ONLINE_JUDGE
  freopen ("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE


  int n, k;
  cin>>n>>k>>M;

  for (int i=0;i<N;i++) {
    comb[i][0]=1;
    for (int j=1;j<=i;j++) {
      comb[i][j]=add(comb[i-1][j-1],comb[i-1][j]);
    }
  }

  total[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=k;j++) {
      total[i][j]=pw(2, i*j);
      aleg_distinct[i][j]=1;
      for (int k=0;k<i;k++) {
        mulup(aleg_distinct[i][j], add(pw(2,j),-k-1));
      }
      for (int j2=0;j2<j;j2++) {
        addup(total[i][j], -mul(total[i][j2], comb[j][j2]));
        addup(aleg_distinct[i][j], -mul(aleg_distinct[i][j2], comb[j][j2]));
      }
      bad[i][j]=0;
      for (int i2=0;i2<i;i2++) {
        for (int j2=0;j2<j;j2++) {
          if (i2==i-1 && n%2==1 && i==n) continue;
          int ways=1;
          mulup(ways,add(total[i2][j2],-bad[i2][j2]));
          mulup(ways,comb[i][i2]);
          mulup(ways,comb[j][j2]);
          mulup(ways,pw(2, (i-i2)*j2));
          mulup(ways,aleg_distinct[i-i2][j-j2]);
          addup(bad[i][j],ways);
        }
      }
    }
  }
  int print_sol=0;
  for(int j=0;j<=k;j++) {
    addup(print_sol, mul(comb[k][j], add(total[n][j], -bad[n][j])));
  }
  cout<<print_sol<<"\n";
}