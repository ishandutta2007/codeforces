#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N=(int)2e5+7;
const int INF=(int)1e18;
int n;
int a[2][N];
int sum[2][N];
int dif[2][N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("___input___.txt","r",stdin);

  bool ok=0;

  int tt;
  cin>>tt;
  for(int tc=1;tc<=tt;tc++){
    cin>>n;
    for(int i=0;i<2;i++){
      for(int j=1;j<=n;j++){
        cin>>a[i][j];
      }
    }
    for (int i=0;i<2;i++) {
      sum[i][n+1]=dif[i][n+1]=-INF;
    }
    for (int i=0;i<2;i++) {
      for(int j=1;j<=n;j++){
        if(a[i][j]!=0){
          a[i][j]++;
        }
      }
    }
    for(int j=n;j>=1;j--){
      for(int i=0;i<2;i++){
        sum[i][j]=max(sum[i][j+1],a[i][j]+j);
        dif[i][j]=max(dif[i][j+1],a[i][j]-j);
      }
    }
    int best=INF,temp=-1;
    for(int j=1;j<=n;j++){
      vector<int> rows;
      if (j%2==1) rows={0,1};else rows={1,0};
      for(int iter=0;iter<2;iter++)temp=max(temp+1,a[rows[iter]][j]),best=min(best,max({dif[rows[iter]][j+1]+j,sum[rows[iter]^1][j]-2*n+j-1,temp})+2*(n-j)-iter+1);
    }
    cout<<best<<"\n";
  }

}