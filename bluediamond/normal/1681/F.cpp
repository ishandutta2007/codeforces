#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)5e5+7;
int n;
int sub[N];
int factive[N];
int total;
bool blocked[N];
vector<pair<int, int>> g[N];

void build(int a,int p=-1) {
  sub[a]=1;
  for (auto &it : g[a]) {
    int b=it.first,val=it.second;
    if (b==p||blocked[b]) continue;
    build(b,a);
    sub[a]+=sub[b];
  }
}

int fcen(int a,int p=-1) {
  int mx=total-sub[a];
  for (auto &it : g[a]) {
    int b=it.first,val=it.second;
    if (b==p||blocked[b]) continue;
    mx=max(mx,sub[b]);
  }
  if (mx<=total/2) return a;
  for (auto &it : g[a]) {
    int b=it.first,val=it.second;
    if (b==p||blocked[b]) continue;
    if (sub[b]==mx) {
      return fcen(b,a);
    }
  }
  assert(0);
}

vector<int> dim;
vector<vector<pair<int, int>>> cnt1, cnt2;

void explore(int a,int p) {
  for (auto &it : g[a]) {
    int b=it.first,val=it.second;
    if (b==p||blocked[b]) continue;
    factive[val]++;
    if (factive[val]==1) {
      cnt1.back().push_back({val, sub[b]});
    }
    if (factive[val]==2) {
      cnt2.back().push_back({val, sub[b]});
    }
    explore(b, a);
    factive[val]--;
  }
}

ll sol=0;
int current[N],ftx[N];

void solve(int a) {
 /** {
    /// delete!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (int i=1;i<=n;i++) {
      assert(factive[i]==0);
    }
  }**/
  build(a);
  total=sub[a];
  a=fcen(a);

  /// solve for a == root
  build(a);

  cnt1.clear();
  cnt2.clear();
  dim.clear();

  for (auto &it : g[a]) {
    int b=it.first,val=it.second;
    if (blocked[b]) continue;
    cnt1.push_back({});
    cnt2.push_back({});
    dim.push_back(sub[b]);

    factive[val]++;
    assert(factive[val]==1);
    cnt1.back().push_back({val, sub[b]});
    explore(b, a);
    factive[val]--;
  }

  int k=(int)cnt1.size();
  assert((int)dim.size()==k);
  assert((int)cnt1.size()==k);
  assert((int)cnt2.size()==k);

  for (int i=0;i<k;i++) {
    /// unu aici, pana la radacina
    for (auto &it:cnt1[i]) {
      int x=it.first, cnt=it.second;
      sol+=cnt;
    }
    for (auto &it:cnt2[i]) {
      int x=it.first, cnt=it.second;
      sol-=cnt;
    }
  }

  for (int i=0;i<k;i++) {
    for (auto &it:cnt1[i]) {
      ftx[it.first]+=it.second;
    }
  }

  for (int i=0;i<k;i++) {
    for (auto &it : cnt1[i]) {
      int x=it.first, cnt=it.second;
      sol-=cnt*(ll)ftx[x];
    }
    for (auto &it : cnt2[i]) {
      int x=it.first, cnt=it.second;
      sol+=cnt*(ll)ftx[x];
    }
  }
  for (int i=0;i<k;i++) {
    for (auto &it:cnt1[i]) {
      ftx[it.first]-=it.second;
    }
  }

  for (int i=0;i<k;i++) {
    for (auto &it : cnt1[i]) {
      current[it.first]+=it.second;
    }

    for (auto &it : cnt1[i]) {
      int x=it.first, cnt=it.second;
      sol-=cnt*(ll)(dim[i]-current[x]);
      sol+=cnt*(ll)(total-1);
    }
    for (auto &it : cnt2[i]) {
      int x=it.first, cnt=it.second;
      sol+=cnt*(ll)(dim[i]-current[x]);
      sol-=cnt*(ll)(total-1);
    }

    for (auto &it : cnt1[i]) {
      current[it.first]-=it.second;
    }
  }

  blocked[a]=1;
  for (auto &it : g[a]) {
    int b=it.first,val=it.second;
    if (blocked[b]) continue;
    solve(b);
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE


  cin>>n;
  for (int i=1;i<n;i++) {
    int a, b, c;
    cin>>a>>b>>c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  solve(1);
  cout<<sol<<"\n";
}