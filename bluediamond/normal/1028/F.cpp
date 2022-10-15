#include <bits/stdc++.h>

using namespace std;

#define int long long

bool home = 1;

struct ve{
  int x;
  int y;
};

bool operator == (ve a,ve b){
  return a.x==b.x&&a.y==b.y;
}

bool operator < (ve a,ve b){
  if(a.x!=b.x)return a.x<b.x;
  return a.y<b.y;
}

ve operator + (ve a, ve b){
  return {a.x+b.x,a.y+b.y};
}


ve operator - (ve a, ve b){
  return {a.x-b.x,a.y-b.y};
}

int dot(ve a,ve b){
  return a.x*b.x+a.y*b.y;
}

ve normgcd(ve v){
  int g=__gcd(v.x,v.y);
  if(g){
    v.x/=g;
    v.y/=g;
  }
  return v;
}

map<int,int> active;

ve wheresim(ve a,ve b){
  a=a+b;
  a=normgcd(a);
  return a;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int act=0;
  int q;
  cin>>q;

  map<ve,int> cnt;
  map<ve,int> acum;

  vector<vector<ve>> vecs;

  while(q--){
    int type,x,y;
    cin>>type>>x>>y;
    assert(1<=type&&type<=3);
    ve v={x,y};
    if(type==1){
      act++;
      int sim=dot(v,v);
      if(!active.count(sim)){
        int sz=(int)active.size();
        active[sim]=sz;
        vecs.push_back({});
      }
      vector<ve>& all=vecs[active[sim]];

      acum[normgcd(v)]++;

      for(auto&v2:all){
        cnt[wheresim(v,v2)]++;
      }

      all.push_back(v);

    }
    if(type==2){
      act--;
      int sim=dot(v,v);
      assert(active.count(sim));
      vector<ve>& all=vecs[active[sim]];


      for(int i=0;i<(int)all.size();i++){
        if(all[i]==v){
          swap(all[i],all.back());
          break;
        }
      }
      assert(!all.empty());
      assert(all.back()==v);
      all.pop_back();

      for(auto&v2:all){
        cnt[wheresim(v,v2)]--;
      }

      acum[normgcd(v)]--;

    }
    if(type==3){
      int sol=0;
      v=normgcd(v);
      if(cnt.count(v)){
        sol=cnt[v];
      }
      int actnow=act;
      if(acum.count(v)){
        actnow-=acum[v];
      }
      cout<<actnow-2*sol<<"\n";
    }
  }

  return 0;
}