#include <bits/stdc++.h>

using namespace std;

int dis(int x1,int y1,int x2,int y2){
  return abs(x1-x2)+abs(y1-y2);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

//  freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    int x,y;
    cin>>x>>y;

    bool ok=0;

    for (int x2=-100;x2<=+100&&!ok;x2++){
      for (int y2=-100;y2<=+100&&!ok;y2++){
        int ac=dis(0,0,x2,y2);
        int ab=dis(0,0,x,y);
        int bc=dis(x2,y2,x,y);
        if (2*ac==ab&&2*bc==ab){
          ok=1;
          cout<<x2<<" "<<y2<<"\n";
        }
      }
    }
    if (!ok){
      cout<<"-1 -1\n";
    }
  }

  return 0;
}