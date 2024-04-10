#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N=(int)1e5+7;
const int INF=(int)1e18;
int n;
int l[N],r[N],c[N],mn[N],mx[N],sol[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=1;i<=n;i++){
      cin>>l[i]>>r[i]>>c[i];
      sol[i]=INF;
    }
    mn[1]=l[1];
    mx[1]=r[1];
    for (int i=2;i<=n;i++){
      mn[i]=min(mn[i-1],l[i]);
      mx[i]=max(mx[i-1],r[i]);
    }
    map<int,int> f1,f2;
    map<pair<int,int>, int>minc;
    for (int i=1;i<=n;i++){
      pair<int,int>cur={l[i],r[i]};
      if(!minc.count(cur)){
        minc[cur]=c[i];
      }else{
        minc[cur]=min(minc[cur],c[i]);
      }
      if(minc.count({mn[i],mx[i]})){
        sol[i]=min(sol[i],minc[{mn[i],mx[i]}]);
      }
      if(!f1.count(l[i])){
        f1[l[i]]=c[i];
      }else{
        f1[l[i]]=min(f1[l[i]],c[i]);
      }
      if (!f2.count(r[i])){
        f2[r[i]]=c[i];
      }else{
        f2[r[i]]=min(f2[r[i]],c[i]);
      }
      assert(f1.count(mn[i]));
      assert(f2.count(mx[i]));
      sol[i]=min(sol[i],f1[mn[i]]+f2[mx[i]]);
    }
    for (int i=1;i<=n;i++){
      cout<<sol[i]<<"\n";
    }
  }

  return 0;
}