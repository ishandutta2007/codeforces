#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(long long &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
long long K;
int buf[20];
int sz;
long long calc(long long n){
  long long i;
  long long s;
  long long x;
  long long c;
  long long res = 0;
  i = s = 1;
  c = 0;
  while(s < n){
    x =min_L(10*s, n)- s;
    res += c * x;
    res += x * (x+1) / 2 * i;
    c += i * x;
    s += x;
    i++;
  }
  return res;
}
int main(){
  int KL2GvlyY;
  long long i;
  long long d;
  long long s;
  long long x;
  int Q5VJL1cS = rd_int();
  for(KL2GvlyY=(0);KL2GvlyY<(Q5VJL1cS);KL2GvlyY++){
    rd(K);K += (-1);
    long long e98WHCEY;
    long long cTE1_r3A;
    long long RZTsC2BF;
    e98WHCEY = 0;
    cTE1_r3A = 500000000;
    while(e98WHCEY < cTE1_r3A){
      if((e98WHCEY + cTE1_r3A)%2==0){
        RZTsC2BF = (e98WHCEY + cTE1_r3A) / 2;
      }
      else{
        RZTsC2BF = (e98WHCEY + cTE1_r3A + 1) / 2;
      }
      if(calc(RZTsC2BF) <= K){
        e98WHCEY = RZTsC2BF;
      }
      else{
        cTE1_r3A = RZTsC2BF - 1;
      }
    }
    x =cTE1_r3A;
    K -= calc(x);
    i = s = 1;
    d = 9;
    for(;;){
      if(K < i * d){
        break;
      }
      K -= i * d;
      i++;
      d *= 10;
      s *= 10;
    }
    s += K / i;
    K %= i;
    sz = 0;
    while(s){
      buf[sz++] = s % 10;
      s /= 10;
    }
    wt_L(buf[sz-1-K]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190921-1
 
// --- original code ---
// //no-unlocked
// ll K;
// int buf[20], sz;
// 
// ll calc(ll n){
//   ll i, s, x, c;
//   ll res = 0;
//   i = s = 1;
//   c = 0;
//   while(s < n){
//     x = min(10s, n) - s;
//     res += c * x;
//     res += x * (x+1) / 2 * i;
//     c += i * x;
//     s += x;
//     i++;
//   }
// 
//   return res;
// }
// 
// {
//   ll i, d, s, x;
//   REP(rd_int()){
//     rd(K--);
// 
//     x = bsearch_max[ll,x,0,5d8](calc(x) <= K);
//     K -= calc(x);
// 
//     i = s = 1;
//     d = 9;
//     for(;;){
//       if(K < i * d) break;
//       K -= i * d;
//       i++;
//       d *= 10;
//       s *= 10;
//     }
//     s += K / i;
//     K %= i;
// 
//     sz = 0;
//     while(s) buf[sz++] = s % 10, s /= 10;
//     wt(buf[sz-1-K]);
//   }
// }