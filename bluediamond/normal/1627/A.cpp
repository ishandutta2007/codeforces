#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

const int N=50+7;
int n,m,r,c,a[N][N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--){
    cin>>n>>m>>r>>c;
    int cnt=0;
    bool e=0;
    for (int i=1;i<=n;i++){
      string s;
      cin>>s;
      for (int j=1;j<=m;j++){
        a[i][j]=(s[j-1]=='B');
        cnt+=a[i][j];
        if (a[i][j]){
          if(i==r||j==c)e=1;
        }
      }
    }
    if(cnt==0){
      cout<<"-1\n";
      continue;
    }
    if (a[r][c]){
      cout<<"0\n";
      continue;
    }
    if(e)cout<<"1\n";else cout<<"2\n";
  }
  return 0;
}