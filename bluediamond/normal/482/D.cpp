#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll

typedef long long ll;
typedef long double ld;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a,int b){
  a=add(a,b);
}

void mulup(int &a,int b){
  a=mul(a,b);
}

const int N=(int)1e5+7;
int n,dp[N][2];
vector<int>g[N];
int cur[2][4],nw[2][4];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ///
  }

  cin>>n;
  for (int i=2;i<=n;i++){
    int p;
    cin>>p;
    g[p].push_back(i);
  }

  for (int a=n;a>=1;a--){
    for (int t=0;t<2;t++) for (int m=0;m<4;m++) cur[t][m]=nw[t][m]=0;
    cur[1][0]=1;

    for (auto &b:g[a]){
      for (int t=0;t<2;t++) for (int m=0;m<4;m++) nw[t][m]=cur[t][m]; /// dau skip la asta curent
      for (int t=0;t<2;t++){
        for (int m=0;m<4;m++){
          for (int fr=0;fr<2;fr++){
            addup(nw[t^fr][m|(1<<fr)],mul(cur[t][m],dp[b][fr])); /// sau il iau pe asta curent
          }
        }
      }
      for (int t=0;t<2;t++) for (int m=0;m<4;m++) cur[t][m]=nw[t][m];
    }

    for (int t=0;t<2;t++){
      for (int m=0;m<4;m++){
        addup(dp[a][t],cur[t][m]);
        if(m==3||(t==1&&m==2)){
          addup(dp[a][t],cur[t][m]);
        }
      }
    }
  }

  cout<<add(dp[1][0],dp[1][1])<<"\n";



  return 0;
}