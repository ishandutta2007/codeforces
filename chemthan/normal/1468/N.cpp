#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int a[3],T,res,b[5];

int main() {
  scanf("%d",&T);
  while(T--){
    for(int i=0;i<3;++i)scanf("%d",a+i);
    for(int i=0;i<5;++i)scanf("%d",b+i);
    res=1;
    for(int i=0;i<3;++i){
      a[i]-=b[i];
      if(a[i]<0)res=0;
    }
    for(int i=0;i<2;++i){
      if(a[i]>=b[i+3]){
        b[i+3]=0;
      }else b[i+3]-=a[i];
    }
    if(a[2]<b[3]+b[4])res=0;
    if(res)puts("YES");
    else puts("NO");
  }
}