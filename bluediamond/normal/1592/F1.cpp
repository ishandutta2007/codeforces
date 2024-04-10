#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500+7;
int n,m,a[N][N],v[N][N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin>>n>>m;
  for (int i=1;i<=n;i++) {
    string s;
    cin>>s;
    for (int j=1;j<=m;j++) {
      a[i][j]=(s[j-1]!='W');
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      v[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];
    }
  }
  int sum=0;
  bool red=0;

  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      a[i][j]=v[i][j];
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      sum+=v[i][j];
      if (i<n&&j<m&&v[i][j]&&v[i][m]&&v[n][j]&&v[n][m]){
        red=1;
      }
    }
  }

  cout<<sum-red<<"\n";
}