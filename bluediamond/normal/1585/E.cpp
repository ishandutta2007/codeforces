#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=(int)1e6+7;
int n,q,val[N],par[N],f[N],cnt[N];
vector<int> g[N];
int _v[N],_l[N],_k[N],sol[N];
vector<int> inds[N];
set<int> rep[N];

int aib[N];

void clr() {
  for (int i=1;i<=n+2;i++) aib[i]=0;
}

void add(int i,int x){
  i++;
  while(i<=n+2){
    aib[i]+=x;
    i+=i&(-i);
  }
}

int get(int i){
  i++;
  int sol=0;
  while (i){
    sol+=aib[i];
    i-=i&(-i);
  }
  return sol;
}

void change(int a,int by) {
  assert(rep[f[a]].count(a));
  rep[f[a]].erase(a);
  add(f[a],-1);
  cnt[f[a]]--;
  f[a]+=by;
  add(f[a],+1);
  cnt[f[a]]++;
  rep[f[a]].insert(a);
}

void dfs(int a) {
  change(val[a],+1);
  for (auto &ind:inds[a]){
    int l=_l[ind],k=_k[ind];
    k+=get(l-1);
    sol[ind]=-1;
    int r=0,cop=k;
    for(int s=(1<<30);s;s/=2){
      if(r+s<=n+2&&aib[r+s]<k){
        r+=s;
        k-=aib[r];
      }
    }
    k=cop;
    if(r<=n){
      sol[ind]=*rep[r].begin();
    }
  }
  for (auto &b : g[a]) {
    dfs(b);
  }
  change(val[a],-1);

}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin>>tests;

  for (int tc=1;tc<=tests;tc++) {
    cin>>n>>q;
    clr();
    for (int i=1;i<=n;i++) {
      cin>>val[i];
    }
    for (int i=0;i<=n;i++){
      rep[i].clear();
      f[i]=0;
      cnt[i]=0;
      g[i].clear();
      inds[i].clear();
    }
    for (int i=1;i<=n;i++) {
      cnt[f[i]]++;
    }
    for(int i=0;i<=n;i++) {
      add(i,cnt[i]);
    }
    for (int i=0;i<=n;i++) rep[i].clear();
    for (int i=0;i<=n;i++) rep[f[i]].insert(i);
    for (int i=2;i<=n;i++) {
      cin>>par[i];
      g[par[i]].push_back(i);
    }
    for (int iq=1;iq<=q;iq++) {
      cin>>_v[iq]>>_l[iq]>>_k[iq];
      inds[_v[iq]].push_back(iq);
      sol[iq]=-2;
    }
    dfs(1);
    for (int iq=1;iq<=q;iq++){
      cout<<sol[iq]<<" ";
    }
    cout<<"\n";
  }
}