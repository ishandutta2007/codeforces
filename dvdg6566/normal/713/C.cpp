#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

priority_queue<ll> pq;
ll N,S[200100],K,ans;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>S[i];
    S[i] -= i;
  }
  pq.push(S[0]);
  pq.push(S[0]);
  for (int i=1;i<N;++i){
    ll t = pq.top();
    pq.pop();
    pq.push(S[i]);
    pq.push(S[i]);
    ans += abs(S[i] - pq.top());
    // cout<<t<<' '<<ans<<'\n';
  }
  cout<<ans;
}