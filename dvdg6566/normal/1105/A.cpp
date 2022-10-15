#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 10000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()
int N, best, ans, cur;
int A[1100];

int main(){
  cin>>N;
  for (int i=0;i<N;++i)cin>>A[i];
  best = INF;
  for (int i=1;i<=100;++i){
    cur = 0;
    for (int j=0;j<N;++j){
      cur += max(0,abs(A[j] - i) - 1);
    }
    if (cur < best){
      best = cur;
      ans = i;
    }
  }
  cout<<ans<<' '<<best;
}