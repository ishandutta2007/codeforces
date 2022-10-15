#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef pair<int,pi> pii;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(X) X.begin(),X.end()
#define SZ(X) (int)X.size()
#define MAXN 100010
#define MAXL 18

int N;
int curlen;
int out[MAXN];
int occ[MAXN];
vi V[MAXL];

inline int msb(unsigned int x){return 32-__builtin_clz(x);}

int main(){
  cin>>N;
  if (N%2==1)cout<<"NO\n";
  else {
    int curlen = N;
    vpi V;
    while (curlen){
      int l = (1<<(msb(curlen)-1));
      int excess = curlen - l + 1;
      int st = l - excess - 1;
      for (int x = 0; x < excess;++x){
        int l = x + st + 1;
        int r = curlen - x;
        V.pb(l,r);
      }
      curlen = st;
    }
    for (auto x : V){
      out[x.f] = x.s;
      out[x.s] = x.f;
    }
    cout<<"YES\n";
    for (int i=1;i<=N;++i)cout<<out[i]<<' ';cout<<'\n';
  }
  if (N <= 5)cout<<"NO\n";
  else{
    for (int i=0;i<MAXL;++i)if((1<<i) == N){cout<<"NO\n";return 0;}
    V[0].pb(1);
    V[0].pb(5);
    V[1].pb(2);
    V[1].pb(3);
    V[2].pb(4);
    for (int i=6;i<=N;++i){
      int t = msb(i);
      V[t-1].pb(i);
    }
    int out[MAXN];
    for (int i=0;i<MAXL;++i)if(SZ(V[i])){
      if (SZ(V[i]) == 1)assert(0);
      for (int j=0;j<SZ(V[i]) - 1;++j){
        int a = V[i][j];
        int b = V[i][j+1];
        out[a] = b;
      }
      int a = V[i].back();
      int b = V[i][0];
      out[a] = b;
    }
    cout<<"YES\n";
    for (int i=1;i<=N;++i)cout<<out[i]<<' ';cout<<'\n';
  }
}