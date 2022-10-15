#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;
  while (t--){
    int x1,p1,x2,p2;
    cin>>x1>>p1>>x2>>p2;
    int p=min(p1,p2);
    p1-=p;
    p2-=p;
    for (int i=1;i<=p1&&x1<=x2;i++)x1*=10;
    for (int i=1;i<=p2&&x2<=x1;i++)x2*=10;
    if(x1==x2){
      cout<<"=\n";
    }else{
      if(x1>x2){
        cout<<">\n";
      }else{
        cout<<"<\n";
      }
    }
  }

  return 0;
}