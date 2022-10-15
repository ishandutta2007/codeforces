#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool home = 1;
bool wannap = 0;

template<typename T> T smallestLengthVector(T a,T b){
  if((int)a.size()<(int)b.size()) return a;
  return b;
}


template<typename T> void print(T a){
  cout<<(int)a.size()<<"\n";
  for(auto&x:a){
    cout<<x.first<<" "<<x.second<<"\n";
  }
}

vector<pair<int,int>> solve(string s,string t){
  vector<pair<int,int>>sol;
  vector<int> dif1,dif2;
  for(int i=0;i+1<(int)s.size();i++)if(s[i]!=s[i+1])dif1.push_back(i+1);
  for(int i=0;i+1<(int)t.size();i++)if(t[i]!=t[i+1])dif2.push_back(i+1);

  function<void(int,int)> pop=[&](int b1,int b2){
    assert((b1+b2)%2==0);
    if(dif1.empty()){
      dif1.push_back(0);
    }
    if(dif2.empty()){
      dif2.push_back(0);
    }
    if((int)dif1.size()<b1+1){
      exit(0);
    }
    if((int)dif2.size()<b2+1){
      exit(0);
    }
    assert((int)dif1.size()>=b1+1);
    assert((int)dif2.size()>=b2+1);
    vector<int> f1,f2;
    for(int i=0;i<b1;i++){
      f1.push_back(dif1.back());
      dif1.pop_back();
    }
    for(int i=0;i<b2;i++){
      f2.push_back(dif2.back());
      dif2.pop_back();
    }
    int delta=dif1.back()-dif2.back();
   /// delta*=-1; /// yes or no?
    sol.push_back({dif1.back(),dif2.back()});
    dif1.pop_back();
    dif2.pop_back();

    swap(dif1,dif2);
    while(!f1.empty()){
      dif1.push_back(f1.back()-delta);
      f1.pop_back();
    }
    while(!f2.empty()){
      dif2.push_back(f2.back()+delta);
      f2.pop_back();
    }
  };
  while(!dif1.empty()||!dif2.empty()){
    int sz1=(int)dif1.size(),sz2=(int)dif2.size();
    if(sz1>=2&&sz2>=2){
      pop(0,0);
      continue;
    }
    if(sz1>=3){
      pop(2,0);
      continue;
    }
    if(sz2>=3){
      pop(0,2);
      continue;
    }
    pop(0,0);
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  wannap=1;


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  string s,t;
  cin>>s>>t;

  print(smallestLengthVector(solve(s+"a",t+"b"),solve(s+"b",t+"a")));




  return 0;
}