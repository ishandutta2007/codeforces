#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second

int main(){
  ll MD = 128;

ll A,B;
  cout<<'?'<<' ';
  for (int i=0;i<100;++i)cout<<i*MD<<' ';
  cout<<'\n';
  fflush(stdout);
  cin >> A;
  cout<<'?'<<' ';
  for (int i=1;i<101;++i)cout<<i<<' ';
  cout<<'\n';
  fflush(stdout);
  cin >> B;

  cout<<'!'<<' '<<A%MD+(B/MD)*MD;
}