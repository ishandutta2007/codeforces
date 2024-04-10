#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int T,a,b,res,n,m,s[N];

int main() {
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    res=0;
    if(a>b){
      a=n-a+1;
      b=n-b+1;
    }
    for(int i=1;i<=m;++i){
      scanf("%d",&s[i]);
    }
    sort(s+1,s+m+1);
    // cout << "\nArr = "; for(int i=1; i<=m;++i) cout << s[i] << ' ';cout <<endl;
    int k=b-a-1;
    int l=1,r=min(m,k);
    while(l<=r){
      int mid=(l+r)/2;
      bool ok=1;
      for(int i=mid,j=1;i;--i,++j){
        if(j+s[i]>=b){
          ok=0;
          break;
        }
      }
      // cout << "Mid = " << mid << " OK = " << ok << endl;
      if(ok){
        res=mid;
        l=mid+1;
      }else{
        r=mid-1;
      }
    }
    printf("%d\n",res);
  }
}