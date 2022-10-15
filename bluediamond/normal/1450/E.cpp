#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N=200+7;
const int INF=(int)1e18+7;
int n,m,d[N][N],col[N],cl[N],s[N][N];
vector<int> g[N];
vector<pair<int,int>> lol;

void adde(int a,int b,int c){
  d[a][b]=min(d[a][b],c);
}

void dfs(int a){
  for (auto &b:g[a]){
    if(cl[b]==-1){
      cl[b]=cl[a]^1;
      dfs(b);
    }else{
      if(cl[b]!=(cl[a]^1)){
        cout<<"NO\n";
        exit(0);
      }
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE



  cin>>n>>m;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      d[i][j]=INF;
    }
    d[i][i]=0;
  }
  for (int i=1;i<=m;i++) {
    int a,b,c;
    cin>>a>>b>>c;
      g[a].push_back(b);
      g[b].push_back(a);
    if(c){
      /// a env on b
      /// d(a)=d(b)-1
      adde(a,b,+1);
      adde(b,a,-1);
    } else {
      /// (d(a)-d(b)<=1)
      adde(a,b,+1);
      adde(b,a,+1);
    }
  }
  for (int i=1;i<=n;i++)cl[i]=-1;
  for (int i=1;i<=n;i++){
    if(cl[i]==-1){
      cl[i]=0;
      dfs(i);
    }
  }
  for (int k=1;k<=n;k++) {
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=n;j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        if(d[i][j]<-1e10){
          cout<<"NO\n";
          exit(0);
        }
      }
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      s[i][j]=d[i][j];
    }
  }
  for (int k=1;k<=n;k++) {
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=n;j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        if(d[i][j]<-1e10){
          cout<<"NO\n";
          exit(0);
        }
      }
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      if(s[i][j]!=d[i][j]){
          cout<<"NO\n";
          exit(0);
        }
    }
  }
  for(int k=1;k<=n;k++) {
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=n;j++) {
        if (d[i][k]+d[k][j]<d[i][j]){
          cout<<"NO\n";
          exit(0);
        }
      }
    }
  }
  int dd=-INF,w=-1;
  for (int i=1;i<=n;i++) {
    int now=0;
    for(int j=1;j<=n;j++) {
      now=max(now,d[i][j]);
    }
    dd=max(dd,now);
    if(dd==now)w=i;
  }
  cout<<"YES\n";
  cout<<dd<<"\n";
  for (int i=1;i<=n;i++) {
    cout<<d[w][i]<<" ";
  }
  cout<<"\n";
}