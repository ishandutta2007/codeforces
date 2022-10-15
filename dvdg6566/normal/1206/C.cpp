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
#define MAXN 200100
#define INF 1e9
vi L,R;
int N;
int main(){
  cin>>N;
  if (N%2==0){
    cout<<"NO";
    return 0;
  }
  cout<<"YES\n";
  for (int i=0;i<N;++i){
    int a = 2*i+1;
    int b = 2*i+2;
    if (i%2){L.pb(a);R.pb(b);}
    else {L.pb(b);R.pb(a);}
  }
  for (auto i : L)cout<<i<<' ';
  for (auto i : R)cout<<i<<' ';
}