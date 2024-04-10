#include <bits/stdc++.h>

using namespace std;

void maxup(int &a, int b) {
  a = max(a, b);
}

const int N=2500+7;
const int INF=(int) 1e9+7;

int n, m;
vector<int> g[N];
bool vis[N];
int daroot[N];
int sub[N];
int dp[N][N][3][3], ndp[N][3][3];

void dfs(int a,int p=-1) {
  assert(vis[a]==0);
  vis[a]=1;

  vector<int> kids;

  bool hbe=0;

  for (auto &b : g[a]) {
    if (b==p) continue;
    if (daroot[b]==a) continue;
    if (vis[b]) {
      daroot[a]=b;
      hbe=1;
      continue;
    }
    dfs(b, a);
    if (daroot[b]&&daroot[b]!=a) {
      daroot[a]=daroot[b];
    }
    kids.push_back(b);
  }

  sub[a]=1;
  for (int i=0;i<=sub[a];i++) for (int x=0;x<3;x++) for (int y=0;y<3;y++) dp[a][i][x][y]=-INF;

  for (int y=0;y<3;y++) {
    dp[a][1][1][y]=0;
    dp[a][0][2][y]=1;
    dp[a][0][0][y]=0;
  }

  for(int x=0;x<3;x++) {
    for (int y=0;y<3;y++) {
      if(hbe&&x!=y){
        dp[a][0][x][y]=-INF;
        dp[a][1][x][y]=-INF;
      }
    }
  }



  for (auto &b : kids) {
    for (int i=0;i<=sub[a]+sub[b];i++) for (int x=0;x<3;x++) for (int y=0;y<3;y++) ndp[i][x][y]=-INF;

    for (int xa=0;xa<3;xa++) {
      for (int xb=0;xb<3;xb++) {
        if(xa+xb==3) continue;


        for (int ya=0;ya<3;ya++) {
          for (int yb=0;yb<3;yb++) {

            if(daroot[b]==daroot[a]&&ya!=yb){
              continue;
            }

            if (daroot[b]==a&&xa+yb==3) {
              continue;
            }

            for (int ia=0;ia<=sub[a];ia++) {
              for (int ib=0;ib<=sub[b];ib++) {
                maxup(ndp[ia+ib][xa][ya], dp[a][ia][xa][ya]+dp[b][ib][xb][yb]);


              }
            }

          }
        }
      }
    }

    if (0) {
      if (daroot[a]==0) {
        for (int xa=0;xa<3;xa++) {
          for (int xb=0;xb<3;xb++) {
            if (xa+xb==3) continue;
            for (int yb=0;yb<3;yb++) {
              for (int ia=0;ia<=sub[a];ia++) {
                for (int ib=0;ib<=sub[b];ib++) {
                  maxup(ndp[ia+ib][xa][0], dp[a][ia][xa][0]+dp[b][ib][xb][yb]);
                }
              }
            }
          }
        }
      } else {
        assert(daroot[a]>0);
        if(daroot[b]==0){
          for (int xa=0;xa<3;xa++) {
            for (int xb=0;xb<3;xb++) {
              if (xa+xb==3) continue;
              for (int yb=0;yb<3;yb++) {
                for (int ia=0;ia<=sub[a];ia++) {
                  for (int ib=0;ib<=sub[b];ib++) {
                    maxup(ndp[ia+ib][xa][0], dp[a][ia][xa][0]+dp[b][ib][xb][yb]);
                  }
                }
              }
            }
          }
        }
      }
    }

    for (int i=0;i<=sub[a]+sub[b];i++) for (int x=0;x<3;x++) for (int y=0;y<3;y++) dp[a][i][x][y]=ndp[i][x][y];

    sub[a]+=sub[b];
  }


  ///cout<<a<<" -> "<<daroot[a]<<"\n";

}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  cin>>n>>m;
  for (int i=1;i<=m;i++) {
    int a, b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1);

  for (int i=0;i<=n;i++) {
    int sol=0;
    for (int x=0;x<3;x++) {
      for (int y=0;y<3;y++) {
        sol=max(sol,dp[1][i][x][y]);
      }
    }
    cout<<sol<<" ";
  }
  cout<<"\n";
}