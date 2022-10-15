#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=(int) 2e5+7;
int n,m,d[N],b[N];
vector<int> g[N];

bool cmp(int i,int j) {
  return d[i]>d[j];
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--) {
    cin>>n>>m;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<=n;i++) d[i]=-1;
    for (int i=1;i<=m;i++) {
      int x,y;
      cin>>x>>y;
      g[x].push_back(y);
    }
    d[1]=0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int a=q.front();
      q.pop();
      for (auto &b:g[a]) if (d[b]==-1) {
        d[b]=1+d[a];
        q.push(b);
      }
    }
    for (int i=1;i<=n;i++) {
      b[i]=d[i];
      for (auto &j:g[i]) {
        b[i]=min(b[i],d[j]);
      }
    }
    vector<int> so;
    for (int i=1;i<=n;i++) so.push_back(i);
    sort(so.begin(),so.end(),cmp);
    for (auto &i:so) {
      for (auto &j:g[i]) {
        if (d[j]>d[i]) b[i]=min(b[i],b[j]);
      }
    }
    for (int i=1;i<=n;i++) {
      cout<<b[i]<<" ";
    }
    cout<<"\n";
  }

}