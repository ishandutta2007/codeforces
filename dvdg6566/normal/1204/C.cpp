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

ll N,P;
ll M[120][120];
vi V;
ll a;
string S;

int main(){
  cin>>N;
  memset(M,-1,sizeof(M));
  for (int i=1;i<=N;++i)M[i][i]=0;
  for (int i=1;i<=N;++i){
    cin>>S;
    for (int j=1;j<=N;++j)if(S[j-1]-'0' == 1)M[i][j] = 1; 
  }
  cin>>P;
  for (int i=0;i<P;++i){cin>>a;V.pb(a);}
  for (int k=1;k<=N;++k){
    for (int i=1;i<=N;++i){
      for (int j=1;j<=N;++j){
        if (M[i][k] == -1 || M[k][j] == -1)continue;
        if (M[i][j] == -1 || M[i][j] > M[i][k] + M[k][j])M[i][j] = M[i][k] + M[k][j];
      }
    }
  }
  int curind = 0;
  int curback = 0;
  vi out;
  out.pb(V[0]);
  while (curind+1 < P){
    while (curind + 1 < P && curind+1 - curback == M[V[curback]][V[curind+1]]){
      ++curind;
      // cout<<V[curback]<<' '<<V[curind+1]<<' '<<M[V[curback]][V[curind+1]]<<' '<<curind+1-curback<<'\n';
    }
    out.pb(V[curind]);
    curind = curback = curind;
  }
  cout<<SZ(out)<<'\n';
  for (auto v:out)cout<<v<<' ';
}