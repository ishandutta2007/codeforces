#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=210000;
const int MAXK=19;
const int INF = 1e9;
const ll MOD = 998244353;

ll N,K,a,b,c,d,e,f;
ll A[MAXN];
ll B[MAXN];

int ask(int V){
  int ODDS=(K+1)/2;
  int EVENS=K/2;
  for (int i=1;i<=N;++i){
    if(A[i]>V){
      B[i] = 0;
    }else{
      B[i]=1;
    }
  }
  // for(int i=1;i<=N;++i)cout<<B[i]<<' ';cout<<'\n';

  // try to fill up all odd places
  int odds=0;
  int evens = 0;
  int cur = 1;
  for (int j=1;j<=N;++j){
    if(cur==1 && B[j]){
      ++odds;
      cur ^= 1;
    }else if(cur == 0){
      ++evens;
      cur ^= 1;
    }
  }
  if(odds >= ODDS && evens >= EVENS)return 1;
   odds=0;
   evens = 0;
   cur = 1;
  for (int j=1;j<=N;++j){
    if(cur==1){
      ++odds;
      cur ^= 1;
    }else if(cur == 0&&B[j]){
      ++evens;
      cur ^= 1;
    }
  }
  if(odds >= ODDS && evens >= EVENS)return 1;
  return 0;
}

int main(){
  cin>>N>>K;
  for(int i=1;i<=N;++i)cin>>A[i];
  
  // cout<<ask(1)<<'\n';
  // return 0;
  int lb=0;
  int ub=1e9;
  while(ub>lb){
    int m=(lb+ub)/2;
    // cerr<<m<<' '<<ask(m)<<'\n';
    if(ask(m))ub=m;
    else lb=m+1;
  }
  cout<<lb<<'\n';
}