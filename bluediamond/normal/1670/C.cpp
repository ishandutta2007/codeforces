#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;

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


const int N=(int)1e5+7;
int n;
int a[N];
int b[N];
int c[N];
int pa[N];
int pb[N];
bool vis[N];
int t[N];
int act[N];

int root(int a) {
  if (t[a]==a) return a;
  return t[a]=root(t[a]);
}

void join(int a, int b) {
  t[root(a)]=root(b);
}

void dfs(int i) {

  if(vis[i]) return;
  if(c[i]==0) return;

  vis[i]=1;

  int x=a[i];
  int y=b[i];
  if(c[i]!=x) swap(x,y);

  assert(c[i]==x);

  if (a[i]==x) {
    assert(c[pb[x]]==0||c[pb[x]]==a[pb[x]]);
    c[pb[x]]=a[pb[x]];
    dfs(pb[x]);
  } else {
    assert(c[pa[x]]==0||c[pa[x]]==b[pa[x]]);
    c[pa[x]]=b[pa[x]];
    dfs(pa[x]);
  }

}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  //home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int tt;
  cin>>tt;
  while (tt--){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) pa[a[i]]=i;
    for (int i=1;i<=n;i++) pb[b[i]]=i;
    for (int i=1;i<=n;i++) vis[i]=0;
    for (int i=1;i<=n;i++) {
      dfs(i);
      t[i]=i;
      act[i]=0;
    }
    for (int i=1;i<=n;i++) {
      if(c[i]!=0) continue;

      if(a[i]==b[i]) continue;
      join(a[i],b[i]);
      act[a[i]]=1;
      act[b[i]]=1;
    }
    int sol=1;
    for (int i=1;i<=n;i++) {
      if(act[i]){
        if(root(i)==i){
          sol=mul(sol,2);
        }
      }
    }
    cout<<sol<<"\n"; continue;
    for (int i=1;i<=n;i++) cout<<c[i]<<" ";
    cout<<"\n";
  }

}