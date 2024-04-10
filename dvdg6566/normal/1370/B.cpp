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
const int MAXN=2100;
const int MAXK=19;
const int INF = 1e9;
const ll MOD = 998244353;

ll N,a,b,c,d,e,f;
ll A[MAXN];
ll B[MAXN];
vi H[MAXN];

void solve(){
  cin>>N;
  N*=2;
  for(int i=1;i<=N;++i)cin>>A[i];
  int le = -1;
  int lo = -1;
  vpi res;
  for (int i=1;i<=N;++i){
    if(A[i]%2==1){
      if(lo==-1)lo=i;
      else{
        res.pb(i,lo);
        lo=-1;
      }
    }else{
      if(le==-1)le=i;
      else{
        res.pb(i,le);
        le=-1;
      }
    }
  }
  if(SZ(res)==N/2)res.pop_back();
  for (auto i:res)cout<<i.f<<' '<<i.s<<'\n';
}

int main(){
  cin>>a;
  while(a--){
    solve();
  }
}