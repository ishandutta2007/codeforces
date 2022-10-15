#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef pair<pi,int> pii;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(X) X.begin(),X.end()
#define SZ(X) (int)X.size()
#define MAXN 1000100
#define INF 1e9

ll l,r,N;

int main(){
  cin>>N>>l>>r;
  ll ansl = 0;
  ll p = N;
  for (int i=0;i<r;++i){
    --p;
    ansl += (1<<i);
  }
  ansl += (1<<(r-1)) * p;

  ll ansr = 0;
  p = N;
  for (int i=0;i<l;++i){
    --p;
    ansr += (1<<i);
  }
  ansr += p;
  cout<<ansr<<' '<<ansl<<'\n';
}