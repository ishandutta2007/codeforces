#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 210000
#define MAXL 18

vector<pi> V;
int N,a,b;
int P[MAXN];
int blk[MAXN];

int main(){
  cin>>N;
  for (int i=1;i<=N;++i){
    cin>>a;
    V.pb(a,i);
  }
  memset(P,-1,sizeof(P));
  sort(ALL(V));
  reverse(ALL(V));
  blk[0] = V[0].s * 2-1;
  for (int i=1;i<SZ(V);++i){
    int a = V[i].s * 2-1;
    int b = V[i-1].s * 2-1;
    P[a] = b; 
    blk[i] = a;
  }

  for (int i=0;i<N;++i){
    int t = V[i].f;
    int a = V[i].s * 2;
    t += i;
    t--;
    P[a] = blk[t];
    ++t;
    if (blk[t] == 0)blk[t] = a;
  }

  for (int i=1;i<=2*N;++i)if(P[i]!=-1){
    cout<<i<<' '<<P[i]<<'\n'; 
  }
}