#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second

ll M[100][100];
vpi res;
ll R,C;

bool valid(int x, int y){
  if (x<0||y<0)return 0;
  if (M[x][y] == 1 && M[x+1][y] == 1 && M[x][y+1] == 1 && M[x+1][y+1] == 1)return 1;
  return 0;
}

int main(){
  cin>>R>>C;
  for (int i=0;i<R;++i){
    for (int j=0;j<C;++j)cin>>M[i][j];
  }
  for (int i=0;i<R;++i){
    for (int j=0;j<C;++j){
      if (M[i][j] == 0)continue;
      if (valid(i,j))res.pb(i,j);
      else if (valid(i-1,j))res.pb(i-1,j);
      else if (valid(i,j-1))res.pb(i,j-1);
      else if(valid(i-1,j-1))res.pb(i-1,j-1);
      else{
        cout<<-1;
        return 0;
      }
    }
  }
  sort(ALL(res));
  res.resize(unique(ALL(res)) - res.begin());
  cout<<SZ(res)<<'\n';
  for (auto i : res)cout<<i.f+1<<' '<<i.s+1<<'\n';
}