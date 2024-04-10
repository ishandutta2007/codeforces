#include <bits/stdc++.h>

using namespace std;

bool home = 1;
bool ok;

#define int ll

typedef long long ll;
typedef long double ld;

struct F{
  int id;
  int x;
  int t;
  int eat;
};

bool cx(F a, F b) {return a.x<b.x;}
bool cid(F a, F b) {return a.id<b.id;}

const int N=(int)2e5+7;
int n,m;
F f[N];

int t[4*N];

void upd(int v,int tl,int tr,int i){
  if(tr<i||i<tl)return;
  if(tl==tr){t[v]=f[i].x+f[i].t;return;}
  int tm=(tl+tr)/2;
  upd(2*v,tl,tm,i);
  upd(2*v+1,tm+1,tr,i);
  t[v]=max(t[2*v],t[2*v+1]);
}

int mx(int v,int tl,int tr,int l,int r){
  if(tr<l||r<tl)return -(int)1e18;
  if(l<=tl&&tr<=r)return t[v];
  int tm=(tl+tr)/2;
  return max(mx(2*v,tl,tm,l,r),mx(2*v+1,tm+1,tr,l,r));
}

int want,ff;

void cox(int v,int tl,int tr){
  if(t[v]<want)return;
  if(tl==tr){ff=tl;return;}
  int tm=(tl+tr)/2;
  if(t[2*v]>=want){
    cox(2*v,tl,tm);
  }else cox(2*v+1,tm+1,tr);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>m;
  for (int i=1;i<=n;i++){
    cin>>f[i].x>>f[i].t;
    f[i].id=i;
  }
  sort(f+1,f+n+1,cx);
  for (int i=1;i<=n;i++)upd(1,1,n,i);
  multiset<pair<int,int>>mosquitoes;

  while(m--){
    int p,juice;
    cin>>p>>juice;
    bool someone=0;

    int l=1,r=n,last=0;
    while (l<=r){
      int m=(l+r)/2;
      if (f[m].x<=p){
        last=m;
        l=m+1;
      }else r=m-1;
    }

    want=p;
    ff=-1;

    cox(1,1,n);

    if(ff!=-1&&ff<=last) {
      int i=ff;
      if(f[i].x+f[i].t>=p){
        someone=1;
        f[i].eat++;
        f[i].t+=juice;
        while (!mosquitoes.empty()){
          auto it=mosquitoes.lower_bound({f[i].x,-1});
          if(it==mosquitoes.end())break;
          if(f[i].x+f[i].t<it->first)break;
          f[i].eat++;
          f[i].t+=it->second;
          mosquitoes.erase(it);
        }
        upd(1,1,n,i);
      //  break;
      }
    }
    if(!someone){
      mosquitoes.insert({p,juice});
    }
  }

  sort(f+1,f+n+1,cid);
  for (int i=1;i<=n;i++){
    cout<<f[i].eat<<" "<<f[i].t<<"\n";
  }

  return 0;
}