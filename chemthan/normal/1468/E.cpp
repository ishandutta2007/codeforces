#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int a[4],T,res;
int b[]={0,1,2,3};

int main() {
  scanf("%d",&T);
  while(T--){
    for(int i=0;i<4;++i)scanf("%d",a+i);
    sort(b,b+4);
    res=0;
    do{
      res=max(res,min(a[b[0]],a[b[1]])*min(a[b[2]],a[b[3]]));
    }while(next_permutation(b,b+4));
    printf("%d\n",res);
  }
}