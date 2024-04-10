#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int long long

const int N=(int)5e4+7;
vector<pair<int,int>> sol;
multiset<int> s;

void op(int x,int y) {
  int a=x+y;
  int b=abs(x-y);
  assert(s.find(x)!=s.end());
  s.erase(s.find(x));
  assert(s.find(y)!=s.end());
  s.erase(s.find(y));
  s.insert(a);
  s.insert(b);
  sol.push_back({x, y});
}

void rec(int n,int coef){
  if(n<=2){
    return;
  }
  int p=1;
  while(p*2<=n)p*=2;
  if(p==n){
    rec(n-1,coef);
    return;
  }
  /**

  p<n

  **/
  for(int d=1;d<=n-p;d++){
    op((p-d)*coef,(p+d)*coef);
  }
  rec(p-(n-p)-1,coef);
  rec(n-p,2*coef);
}

void solve(int n){
  sol.clear();
  s.clear();
  for(int i=1;i<=n;i++){
    s.insert(i);
  }
  rec(n,1);
  if(1){
    int x=1;
    while(x<n){
      auto it=s.find(x);
      if(it!=s.end()){
        s.erase(it);
        it=s.find(x);
        if(it!=s.end()){
          s.insert(x);
          op(x,x);
        }else{
          s.insert(x);
          x*=2;
        }
      }else{
        x*=2;

      }
    }
  }


  for(int x=1;x<n;x*=2){
    while(s.find(x)!=s.end()){
      assert(s.find(0)!=s.end());
      op(x,0);
      op(x,x);

    }
  }

  auto it=s.end();
  it--;
  int x=*it;



  while(s.count(0)){
    assert(s.find(x)!=s.end());
    op(x,0);
  }


 /** if(s.find(0)==s.end()){
    cout<<n<<" : ";
    for(auto&x:s){
      cout<<x<<" ";
    }
    cout<<"\n";
  }**/

  cout<<(int)sol.size()<<"\n";
  for(auto&x:sol){
    cout<<x.first<<" "<<x.second<<"\n";
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen("iron_man.txt","r",stdin);


  if(0){
    for(int i=3;i<=(int)1e5+7;i++){
     //// cout<<"\t\t\t\t\ti = "<<i<<" : "<<"\n";
      solve(i);
    }
    exit(0);
  }

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    if(n==2){
      cout<<"-1\n";
      continue;
    }
    solve(n);
  }

  return 0;
}