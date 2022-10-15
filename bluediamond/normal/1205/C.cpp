#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;

const int N=50+7;
int n,a[N][N];
bool ipa[N][N][N][N];


int ask(int r1,int c1,int r2,int c2) {
  assert(1<=r1&&r1<=r2&&r2<=n);
  assert(1<=c1&&c1<=c2&&c2<=n);
  assert(r1+c1+2<=r2+c2);
  cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
  int sol;
  cin>>sol;
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  cin>>n;


  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      a[i][j]=-1;
    }
  }

  a[1][1]=1;
  a[n][n]=0;


  for(int i=1; i<=n; i++) {
    if(i%2==0) {
      int xr=1^ask(i-1,1,i,2);
      a[i][2]=a[i-1][1]^xr;
      for(int j=4; j<=n; j+=2) {
        int xr=1^ask(i,j-2,i,j);
        a[i][j]=a[i][j-2]^xr;
      }
    } else {
      if(i>=3) {
        int xr=1^ask(i-2,1,i,1);
        a[i][1]=a[i-2][1]^xr;
      }
      for(int j=3; j<=n; j+=2) {
        int xr=1^ask(i,j-2,i,j);
        a[i][j]=a[i][j-2]^xr;
      }
    }
  }

  a[1][2]=0;
  for(int i=1; i<=n; i++) {
    if(i%2==1) {
      /// find a[i][2]
      if(i>=3) {
        int xr=1^ask(i-1,1,i,2);
        a[i][2]=a[i-1][1]^xr;
      }
      for(int j=4; j<=n; j+=2) {
        int xr=1^ask(i,j-2,i,j);
        a[i][j]=a[i][j-2]^xr;
      }
    } else {
      /// find a[i][3]
      int xr=1^ask(i-1,2,i,3);
      a[i][3]=a[i-1][2]^xr;
      /// find a[i][1]
      xr=1^ask(i,1,i,3);
      a[i][1]=a[i][3]^xr;
      for(int j=5; j<=n; j+=2) {
        int xr=1^ask(i,j-2,i,j);
        a[i][j]=a[i][j-2]^xr;
      }
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      assert(a[i][j]!=-1);
    }
  }

  vector<vector<bool>> all;

  for(int S=0; S<2; S++) {
    all.push_back({});
    if(S) {
      for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
          if((i+j)%2==1) {
            a[i][j]^=1;
          }
        }
      }
    }
    for(int i1=0; i1<=n+1; i1++)
      for(int i2=0; i2<=n+1; i2++)
        for(int i3=0; i3<=n+1; i3++)
          for(int i4=0; i4<=n+1; i4++) {
            ipa[i1][i2][i3][i4]=0;
          }
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        ipa[i][j][i][j]=1;
        if(i+1<=n) {
          ipa[i][j][i+1][j]=(a[i][j]==a[i+1][j]);
        }
        if(j+1<=n) {
          ipa[i][j][i][j+1]=(a[i][j]==a[i][j+1]);
        }
      }
    }


    for(int r1=1; r1<=n; r1++) {
      for(int c1=1; c1<=n; c1++) {
        for(int r2=r1; r2<=n; r2++) {
          for(int c2=c1; c2<=n; c2++) {
            if(r1+c1+2<=r2+c2) {
              if(a[r1][c1]==a[r2][c2]) {
                bool ok=0;
                ok|=ipa[r1+1][c1][r2-1][c2];
                ok|=ipa[r1+1][c1][r2][c2-1];
                ok|=ipa[r1][c1+1][r2-1][c2];
                ok|=ipa[r1][c1+1][r2][c2-1];
                ipa[r1][c1][r2][c2]=ok;
              }
              all.back().push_back(ipa[r1][c1][r2][c2]);
            }
          }
        }
      }
    }

    if(S) {
      for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
          if((i+j)%2==1) {
            a[i][j]^=1;
          }
        }
      }
    }
  }

  assert(all[0]!=all[1]);
  int pz=0;
  bool deja=0;
  for(int r1=1; r1<=n&&!deja; r1++) {
    for(int c1=1; c1<=n&&!deja; c1++) {
      for(int r2=r1; r2<=n&&!deja; r2++) {
        for(int c2=c1; c2<=n&&!deja; c2++) {
          if(r1+c1+2<=r2+c2) {
            if(all[0][pz]!=all[1][pz]){
              deja=1;
              int x=ask(r1,c1,r2,c2);
              if(x!=all[0][pz]){
                for(int i=1;i<=n;i++){
                  for(int j=1;j<=n;j++){
                    if((i+j)%2==1){
                      a[i][j]^=1;
                    }
                  }
                }
              }
            }
            pz++;
          }
        }
      }
    }
  }
  assert(deja);


  cout<<"!"<<endl;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(a[i][j]==-1) {
        cout<<"0";
        continue;
      }
      cout<<a[i][j];
    }
    cout<<endl;
  }

  return 0;
}