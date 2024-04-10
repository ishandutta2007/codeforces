#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;
  while(t--) {
    int n,unu=0,doi=0;
    cin>>n;
    for (int i=1;i<=n;i++) {
      int x;
      cin>>x;
      unu+=(x==1);
      doi+=(x==2);
    }
    bool ok=0;
    for (int a=0;a<=unu;a++){
      int b=unu-a;
      /// a,b
    //  a+2*k=b+2*(doi-k)
  //    a-b=2*(doi-2*k)
      if ((a-b)%2==0) {
//        doi-2*k=(a-b)/2
//        2*k=doi-(a-b)/2
        int x=doi-(a-b)/2;
        if (x%2) continue;
        if (x>=0) ok=1;
      }
    }
    if (ok) cout << "YES\n"; else cout << "NO\n";
  }

}