#include <bits/stdc++.h>

using namespace std;

const int N=1000+7;
int n,m,a[N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int k;
  cin>>n>>m>>k;

  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  for (int i=1;i<=k;i++){
    int r=1,c;
    cin>>c;
    while (r<=n){
      if (a[r][c]==1){a[r][c]=2;c++;continue;}
      if (a[r][c]==2){a[r][c]=2;r++;continue;}
      if (a[r][c]==3){a[r][c]=2;c--;continue;}
    }
    cout<<c<<" ";
  }
  cout<<"\n";
  return 0;
}