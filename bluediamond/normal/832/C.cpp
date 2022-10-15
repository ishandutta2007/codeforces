#include <bits/stdc++.h>


using namespace std;

typedef long double ld;
const ld inf=(ld)1e18;

struct guy{
  ld x;
  ld v;
};

bool home=1;
int stop=(int) 1e6;
const int N=(int) 1e6+7;
int cnt0[N];
int cnt1[N];

signed main() {

#ifdef ONLINE_JUDGE
  home=0;
#endif
if(home)freopen ("iron_man.txt","r",stdin);
if(!home){
  ios::sync_with_stdio(0); cin.tie(0);
}
  int n;
  ld c;
  ld rp=(ld)1e6;
  cin>>n>>c;

  vector<guy> l,r;

  for (int i=1;i<=n;i++){
    int x,v,t;
    cin>>x>>v>>t;
    if(t==1){
      l.push_back({x,v});
    }else{
      r.push_back({x,v});
    }
  }

  ld print=inf;
  ld baset0=inf,baset1=inf;
  for (auto &it:l)baset0=min(baset0,it.x/it.v);
  for (auto &it:r)baset1=min(baset1,(rp-it.x)/it.v);

  if(n<=100){
  for (int w=0;w<=(int)1e6;w++){
    for (int i=0;i<=n;i++) cnt0[i]=cnt1[i]=0;
    ld t0=baset0;
    ld t1=baset1;

    for (auto &it:l){
      if (it.x<=w){
        ld s=1/(c-it.v);
        ld cc=1/(c+it.v);
        ld oth=cc*s*it.v;
        ld coef=s-oth;
        ld tlib=it.x*(cc-s)+oth*it.x;
        t0=min(t0,tlib+w*coef);
        assert(coef>=0);
      }
    }

    /**


    l : it.x<=w and tlib+w*coef<=lim
    l : it.x<=w and w<=(lim-tlib)/coef : floor

    r : w<=it.x and tlib-w*coef<=lim
    r : w<=it.x and tlib-lim<=w*coef : ceil


    **/
    for (auto &it:r){
      if(w<=it.x){
        ld s=-1/(c-it.v);
        ld cc=1/(c+it.v);
        ld oth=s*it.v*cc;
        ld coef=oth-s;
        ld tlib=cc*(rp-it.x)-it.x*s+oth*it.x;
        t1=min(t1,tlib-w*coef);
        assert(coef>=0);
      }
    }
    print=min(print,max(t0,t1));
  }
  cout<<fixed<<setprecision(6)<<print<<"\n";
  exit(0);
  }


  ld low=0,high =(ld) 1e6;

  for (int S=0;S<100;S++){
    for (int i=0;i<=stop;i++)cnt0[i]=cnt1[i]=0;
    ld lim=(low+high)/2;
    if (baset0<=lim) cnt0[0]++;
    if (baset1<=lim) cnt1[0]++;
    for (auto &it:l){
      ld s=1/(c-it.v);
      ld cc=1/(c+it.v);
      ld oth=cc*s*it.v;
      ld coef=s-oth;
      ld tlib=it.x*(cc-s)+oth*it.x;
      int p=it.x,u=floor((lim-tlib)/coef);
      p=max(p,0), u=min(u,stop);
      if (p<=u){
        cnt0[p]++;
        cnt0[u+1]--;
      }
    }
    for (auto &it:r){
      ld s=-1/(c-it.v);
      ld cc=1/(c+it.v);
      ld oth=s*it.v*cc;
      ld coef=oth-s;
      ld tlib=cc*(rp-it.x)-it.x*s+oth*it.x;
      int p=ceil((tlib-lim)/coef),u=it.x;
      p=max(p,0), u=min(u,stop);
      if (p<=u){
        cnt1[p]++;
        cnt1[u+1]--;
      }
    }
    bool ok=(cnt0[0]&&cnt1[0]);
    for (int i=1;i<=stop;i++){
      cnt0[i]+=cnt0[i-1];
      cnt1[i]+=cnt1[i-1];
      if(cnt0[i]&&cnt1[i])ok=1;
    }
    if(ok){
      high=lim;
    }else{
      low=lim;
    }
  }

  cout<<fixed<<setprecision(6)<<low<<"\n";
  exit(0);


}