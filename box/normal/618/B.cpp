#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ll = long long;
using pii = pair<long long, int>;
//#define int ll
const int MOD = 1000000007;

int a[55][55];
int ans[55];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  set<int> att;
  for(int i=1;i<=n;i++)att.insert(i);
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
  for(int x=1;x<=n;x++){
    int r=0,z=0;
    for(int i:att){
      z=0;
      for(int j:att){
        if((i!=j)&&(z!=0)&&(a[i][j]!=z))
          goto NO;
        else if(i!=j) z=a[i][j];
      }
      r=i; break;
      NO:;
    }
    ans[r]=z;
    att.erase(r);
  }
  for(int i=1;i<=n;i++) cout<<(ans[i]?ans[i]:n)<<" \n"[i==n];
}