#include <bits/stdc++.h>

bool home=1;

using namespace std;

typedef long long ll;

void print(int n,vector<pair<int, int>> sol){
  cout<<n<<" : "<<(int)sol.size()<<"\n";
  for (int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      bool is=0;
      pair<int, int> pr={i, j};
      for (auto &lol : sol){
        if (lol==pr) {
          is=1;
        }
      }
      if(is){
        cout<<"X";
      }else{
        cout<<".";
      }
    }
    cout<<"\n";
  }
  cout<<"########################\n";
}

const int N=(int)1e5+7;
int kol[N];

#define retsol {assert((int)sol.size()==kol[n]); return sol;}

vector<pair<int, int>> solve(int n){
  vector<pair<int, int>> sol;
  if(n==1){
    sol.push_back({1, 1});
    retsol;
  }

  int r=n-1,c=1;

  while(r>=2){
    assert(c+2<=n);
    sol.push_back({r, c});
    sol.push_back({r-1,c+2});

    r-=3;
    c+=3;
  }


  if((int)sol.size()<kol[n]){
    if(n%3==2){
      sol.push_back({1, n-1});
    }else{
      assert(n%3==1);
      sol.push_back({1,n});
    }
  }
  assert((int)sol.size()==kol[n]);
  sol.resize(kol[n]);

  retsol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif
home=0;

  kol[0]=0;
  kol[1]=1;
  kol[2]=1;
  for (int i=3;i<N;i++) kol[i]=kol[i-3]+2;

  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

int n;
cin>>n;
auto sol=solve(n);
cout<<(int)sol.size()<<"\n";
for(auto&it:sol)cout<<it.first<<" "<<it.second<<"\n";


}