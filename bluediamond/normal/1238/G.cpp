#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;

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


  int tests;
  cin>>tests;
  while(tests--){
    int n,m,c,c0;
    cin>>n>>m>>c>>c0;
    vector<pair<int,pair<int,int>>> a(n);
    for(auto&x:a){
      cin>>x.first>>x.second.first>>x.second.second;
    }
    function<ll()>solve=[&](){
      ll Cost=0;
      int active=0;
      a.push_back({m,{0,0}});
      multiset<pair<int,int>>offs;
      offs.insert({0,c0});
      active+=c0;
      sort(a.begin(),a.end());

      function<ll()>getsum=[&](){
        ll sum=0;
        for(auto&it:offs){
          sum+=it.second;
        }
        return sum;
      };

      for (int iter=0;iter<(int)a.size();iter++){
        int events=a[iter].first-((iter==0)?0:a[iter-1].first);
        int init=events;
        while(events>0&&!offs.empty()){
          auto IT=*offs.begin();
          offs.erase(offs.begin());
          int Take=min(IT.second,events);
          events-=Take;
          IT.second-=Take;
          active-=Take;
          Cost+=(ll)IT.first*Take;
          if(IT.second>0){
            offs.insert(IT);
          }
        }

        if(events>0){
          return -1LL;
        }
        offs.insert({a[iter].second.second,a[iter].second.first});
        active+=a[iter].second.first;

        int needToDelete=max(0,active-c);



        while(needToDelete>0){
          assert(!offs.empty());
          auto IT=offs.end();
          IT--;
          pair<int, int> Value=*IT;
          offs.erase(IT);
          int take=min(Value.second,needToDelete);
          needToDelete-=take;
          Value.second-=take;
          active-=take;
          if(Value.second>0){
            offs.insert(Value);
          }
        }
        assert(needToDelete==0);
      }
      return Cost;
    };

    cout<<solve()<<"\n";
  }

  return 0;
}