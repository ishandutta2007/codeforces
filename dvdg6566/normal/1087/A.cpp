#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

string st,res;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>st;
    int lb = 0;
    int ub = st.size() - 1;
  if (st.size()%2 == 0){
    while (lb != ub){
      res += st[ub];
      --ub;
      if (lb == ub)break;
      res += st[lb];
      ++lb;
    }
  }
  else{
    while (lb != ub){
      res += st[lb];
      ++lb;
      if (lb == ub)break;
      res += st[ub];
      --ub;
    }
  }
  res += st[lb];
  reverse(ALL(res));
  cout<<res;
}