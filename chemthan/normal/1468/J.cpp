#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;

typedef long long ll;

int T,n,m,k,t[N],cnt,p[N];
ll res;

int findRoot(int u){
  return u==p[u]?u:p[u]=findRoot(p[u]);
}

void join(int u,int v){
  u=findRoot(u);
  v=findRoot(v);
  if(u==v)return;
  p[u]=v;
  --cnt;
}

struct Edge {
  int u,v,c;
} e[N];

bool comp(const Edge &a, const Edge &b){
  return a.c < b.c;
}

int main() {
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&m,&k);
    res=0;
    for(int i=0;i<m;++i){
      int a,b,s;
      scanf("%d%d%d",&a,&b,&s);
      e[i].u=a;
      e[i].v=b;
      e[i].c=s;
    }
    sort(e,e+m,comp);
    //cout << "\nk = " << k << endl << "Edge:\n";for(int i=0;i<m;++i)cout << i << ": " <<e[i].u<<" -> " <<  e[i].v <<": "<<e[i].c << endl;
    ll res1=1e18;
    cnt=n;
    for(int i=1;i<=n;++i)p[i]=i;
    int h=m;
    e[m].c=(int)1e9+3;
    for(int i=0;i<m;++i){
      if(e[i].c>k){
        h=i;
        break;
      }
      join(e[i].u,e[i].v);
      res1=min(res1,1LL*k-e[i].c);
    }
    //cout << "h = " << h << " cnt = " << cnt << endl;
    if(cnt==1){
      if(h<m)
        res=min(res1,1LL*e[h].c-k);
      else res=res1;
      //cout << "res1 = " << res1 << ' ' << "res = " << res << " other = " << e[h].c -k << endl;
    }else{
      for(int i=h;i<m;++i){
        if(findRoot(e[i].u)==findRoot(e[i].v))continue;
        res+=e[i].c-k;
        join(e[i].u,e[i].v);
        if(cnt==1)break;
      }
    }
    printf("%lld\n",res);
  }
}