#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 998244353;
const ll INF = 1e9;
const ll MAXN = 200100;

ll T,a,b,N,c,d,e,f,sum,ans,K;
ll A[MAXN];
vpi V;
vi t;
string S;
deque<char> dq;

bool ask(int a, int b){
  if (a >= b)return 1;
  if (dq[a] == dq[b])return ask(a+1,b-1);
  return 0;
}

int main(){
  cin>>T;
  for (int x=0;x<T;++x){
    string O = "";
    dq.clear();
    ans = 0;
    sum = 0;
    cin>>S;
    for (auto i : S)dq.pb(i);
    while (SZ(dq) >= 2 && dq[0] == dq.back()){
      O+=(dq[0]);
      dq.pop_back();
      dq.pop_front();
      ans += 2;
    }
    N = SZ(dq);
    pi tt=mp(0,-1);
    for (ll i=0;i<N;++i){
      if (ask(0,i) && i+1>sum){
        sum = max(sum, i+1);
        tt = mp(0,i);
      }
      if (ask(i, N-1) && N-i > sum){
        sum = max(sum, N-i);
        tt = mp(i,N-1);
      }
    }
    // cout<<tt.f<<' '<<tt.s<<'\n';
    for (auto i : O)cout<<i;
    reverse(ALL(O));
    for (int i=tt.f;i<=tt.s;++i)cout<<dq[i];
    for (auto i : O)cout<<i;
    cout<<'\n';
  }
}