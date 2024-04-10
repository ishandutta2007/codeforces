#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

const int N=10;
const int M=52;

int code(char c){
  if('a'<=c&&c<='z')return c-'a';
  assert('A'<=c&&c<='Z');
  return 26+c-'A';
}

int n;
vector<int> pos[N][M];
int dp[M][1<<N];

struct oferta{
  int cine;
  int mask;
};

bool operator < (oferta a, oferta b){
  return pos[0][a.cine][a.mask%2]<pos[0][b.cine][b.mask%2];
}

int memo[M][1<<N],cc[M][1<<N];

signed main() {
  //ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int tt;
  cin>>tt;

  while (tt--){
    for (int i=0;i<M;i++)for (int j=0;j<(1<<N);j++)memo[i][j]=cc[i][j]=-1;
    cin>>n;
    for (int i=0;i<n;i++){
      string s;
      cin>>s;
      for (int j=0;j<M;j++)pos[i][j].clear();
      for (int j=0;j<s.size();j++){
        pos[i][code(s[j])].push_back(j);
      }
    }
    vector<oferta> oferte;
    for (int x=0;x<M;x++){
      for (int mask=0;mask<(1<<n);mask++){
        vector<int> bits;
        for (int i=0;i<n;i++)bits.push_back(!!(mask&(1<<i)));
        bool bad=0;
        for (int i=0;i<n;i++){
          if (bits[i] && pos[i][x].size()==1) {bad=1; break;}
          if (pos[i][x].empty()) {bad=1; break;}
        }
        if (bad)continue;
        oferte.push_back({x,mask});
      }
    }
    sort(oferte.begin(),oferte.end());
    for (int i=0;i<oferte.size();i++){
      cc[oferte[i].cine][oferte[i].mask]=i;
    }
    vector<int> dp(oferte.size(),0),par(dp.size(),-1);


    for (int i=0;i<dp.size();i++){
      auto of=oferte[i];

      for (int x=0;x<M;x++){
        int themask=0;
        bool valid=1;
        for (int i=0;i<n;i++){
          int current=pos[i][of.cine][!!(of.mask&(1<<i))];
          int j=0;

          while (j+1<pos[i][x].size()&&pos[i][x][j+1]<current)j++;

          if (j<pos[i][x].size()&&pos[i][x][j]<current){
            assert(j==0||j==1);
            themask+=(1<<i)*j;
          }else{
            valid=0;
          }
        }
        if (!valid) continue;
        dp[i]=max(dp[i],memo[x][themask]);
        if (dp[i]==memo[x][themask]) par[i]=cc[x][themask];
      }

      dp[i]++;
      memo[of.cine][of.mask]=dp[i];
    }

    int sol=0;
    for (auto &x:dp)sol=max(sol,x);
    if(sol==0){
      cout<<sol<<"\n\n";
      continue;
    }
    int i=0;
    while (dp[i]!=sol)i++;
    vector<int> inv;
    while (par[i]!=-1){
      inv.push_back(oferte[i].cine);
      i=par[i];
    }
    inv.push_back(oferte[i].cine);
    cout<<sol<<"\n";
    reverse(inv.begin(),inv.end());
    for (auto &c:inv){
      if(c<26){
        cout<<(char)('a'+c);
      }else{
        cout<<(char)('A'+c-26);
      }
    }
    cout<<"\n";
  }

  return 0;
}