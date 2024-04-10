#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

const int N=(int)2e5+7;
const ll INF=(ll)1e18+7;
int n;
int m;
int value[N];
bool vis[N],act[N];
ll best[N];
ll k;
vector<int> g[N];

void calculeaza(int a) {
  best[a]=1;
  vis[a]=act[a]=1;
  for (auto &b:g[a]) {
    if (vis[b]==0) {
      calculeaza(b);
      best[a]=max(best[a],1+best[b]);
    }else{
      if (act[b]) {
        best[a]=max(best[a],INF);
      }
      best[a]=max(best[a],1+best[b]);
    }
  }
  act[a]=0;
}

bool is_ok(int limit) {
  for (int i=1;i<=n;i++) vis[i]=act[i]=best[i]=0;
  for (int i=1;i<=n;i++) if (value[i]>limit) vis[i]=1;
  for (int i=1;i<=n;i++) if (vis[i]==0) {
    calculeaza(i);
  }
  return *max_element(best+1,best+n+1)>=k;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif


  /**
  vrem max <= smth => all <= smth
  **/

  cin>>n>>m>>k;
  for (int i=1;i<=n;i++) cin>>value[i];
  for (int i=1;i<=m;i++) {int foo,bar;cin>>foo>>bar;g[foo].push_back(bar);}


  int low=0,high=(int)1e18+7,sol=-1;
  while (low<=high) {
    int smth=(low+high)/2;
    if (is_ok(smth)) {
      sol=smth;
      high=smth-1;
    }else{
      low=smth+1;
    }
  }
  cout<<sol<<"\n";


  return 0;
}