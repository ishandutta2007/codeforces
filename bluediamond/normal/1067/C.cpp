#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int long long

int n;
map<pair<int, int>,int> activation;
set<pair<int, int>> active;

pair<int, int> operator + (pair<int, int> a, pair<int, int> b) {
  a.first+=b.first;
  a.second+=b.second;
  return a;
}

void activate(pair<int, int> aa){
  if(active.count(aa)) return;
  vector<pair<int,int>> wait;
  active.insert(aa);
  for (int a=1;a<=2;a++){
    int b=3-a;
    for(int sa=-1;sa<=+1;sa+=2){
      for(int sb=-1;sb<=+1;sb+=2){
        pair<int, int> dir={a*sa,b*sb};
        pair<int, int> b=aa+dir;
        activation[b]++;
        if(activation[b]==4){
          wait.push_back(b);
        }
      }
    }
  }
  for(auto&b:wait){
    activate(b);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen("iron_man.txt","r",stdin);

  int n;
  cin>>n;

  int a=0,b=1;
  vector<pair<int,int>>sol;

  for(int step=0;step<n;step++){
    pair<int, int> it;
    if(step%3==2){
      it={3,b};
      b+=2;
    }else{
      it={0,a};
      a++;
    }
    activate(it);
    sol.push_back(it);
  }
  if(0){
    for(auto&it:active){
      cout<<it.first<<" "<<it.second<<"\n";
    }
    cout<<(int)active.size()<<" vs "<<n*n/10<<"\n";
  }

  assert((int)active.size()>=n*n/10);
  assert((int)sol.size()==n);
  for(auto&it:sol){
    cout<<it.first<<" "<<it.second<<"\n";
  }

  return 0;
}