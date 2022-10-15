#include <bits/stdc++.h>


using namespace std;

bool home = 1;

int com(int a,int b){
  int s=0;
  while(1){
    if(a==0){
      assert(b==0);
      break;
    }
    if(b==0){
      assert(a==0);
      break;
    }
    int x=a%10,y=b%10;
    a/=10;
    b/=10;
    s+=(x==y);
  }
  return s;

}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  int t;
  cin>>t;
  while(t--){
    int n,l,r;
    cin>>n;
    if(n>=100){
      l=100;
    }else{
      l=10;
    }
    r=10*l-1;
    int best=-1;
    for (int j=l;j<=r;j++){
      if(j%7)continue;
      if(best==-1)best=j;
      if(com(best,n)<com(j,n))best=j;
    }
    cout<<best<<"\n";
  }

  return 0;
}