#include <bits/stdc++.h>

using namespace std;

typedef long long ll;




signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

 /// freopen ("input","r",stdin);

  int t;
  cin>>t;

  while (t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0)),cnt=a,good=a;
    int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
    int r=-1,c=-1;
    for (int i=0;i<n;i++){
      string s;
      cin>>s;
      for (int j=0;j<m;j++){
        if(s[j]=='#'){
          a[i][j]=1;
        }else{
          if(s[j]=='L'){
            assert(r==-1);
            assert(c==-1);
            r=i;
            c=j;
          }else{
            assert(s[j]=='.');
          }
        }
      }
    }
    assert(r!=-1);
    assert(c!=-1);

    for (int k=0;k<4;k++){
      for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){

          if(a[i][j]==0){
            int rn=i+dr[k],cn=j+dc[k];
            if(0<=rn&&0<=cn&&rn<n&&cn<m&&a[rn][cn]==0)cnt[i][j]++;
          }
        }
      }
    }



    function<void(int,int)>backprop = [&](int r,int c){
      good[r][c]=1;
      for (int k2=0;k2<4;k2++){
        int rr=r+dr[k2];
        int cc=c+dc[k2];
        if(0<=rr&&0<=cc&&rr<n&&cc<m)cnt[rr][cc]--;
      }
      for (int k=0;k<4;k++){
        int rn=r+dr[k];
        int cn=c+dc[k];
        if(0<=rn&&0<=cn&&rn<n&&cn<m&&a[rn][cn]==0&&cnt[rn][cn]<=1&&good[rn][cn]==0){

          backprop(rn,cn);
        }
      }
    };

    backprop(r,c);

    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        if(a[i][j]){
          cout<<"#";
        }else{
          if(i==r&&j==c){
            cout<<"L";
          }else{
            if(good[i][j]){
              cout<<"+";
            }else{
              cout<<".";
            }
          }
        }
      }
      cout<<"\n";
    }
  }


  return 0;
}