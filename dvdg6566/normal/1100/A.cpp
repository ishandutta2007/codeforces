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
#define INF 100000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int N,K,tot,t,r;
int a[500];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>K;
  for (int i=0;i<N;++i){
    cin>>a[i];
    tot += a[i];
  }
  for (int i=0; i < K;++i){
    t = 0;
    for (int j=i;j<N;j+=K){
      t += a[j];
    }
    r = max(r, abs(tot-t));
  }
  cout << r;
}