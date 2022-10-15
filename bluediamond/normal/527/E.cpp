#include <bits/stdc++.h>

using namespace std;

const int N=(int)5e5+7;
int n,m,te,sm[N],xx[N],yy[N],f[N],s[N];
bool vis[N];
vector<int> g[N],ord;

void adde(int a, int b) {
  te++;
  f[te]=a;
  s[te]=b;
  g[a].push_back(te);
  g[b].push_back(te);
  sm[te]=a+b;
}

void expleuler(int a,int ant=0) {
  while(!g[a].empty()) {
    int i=g[a].back();
    g[a].pop_back();
    if(vis[i])continue;
    vis[i]=1;
    int b=sm[i]-a;
   /// cout<<" = "<<a<<" "<<b<<"\n";
    expleuler(b,a);
    ord.push_back(i);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  cin>>n>>m;
  for (int i=1;i<=m;i++) {
    int a,b;
    cin>>a>>b;
    adde(a, b);
  }
  vector<int> odds;
  for (int i=1;i<=n;i++) {
    if((int)g[i].size()%2==1){
      odds.push_back(i);
    }
  }
  assert((int)odds.size()%2==0);
  for (int i=1;i<(int)odds.size();i+=2){
    adde(odds[i-1], odds[i]);
  }
  if(te%2==1) {
    adde(1,1);
  }
  assert(te%2==0);
  for (int i=1;i<=n;i++) {
    assert((int)g[i].size()%2==0);
  }
  expleuler(1);
  assert((int)ord.size()==te);

  int cur=1,stp=0;
  for (auto &i : ord){
    stp++;
    int X=cur,Y=sm[i]-cur;
    cur=sm[i]-cur;
    if(stp%2==1)swap(X,Y);
    xx[i]=X;
    yy[i]=Y;

  }

  cout<<te<<"\n";
  for (int i=1;i<=te;i++) {
    cout<<xx[i]<<" "<<yy[i]<<"\n";
  }

}