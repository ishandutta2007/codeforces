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
const int MOD = 1e9+7;
const int INF = 1e9;
const int MAXN = 3100100;

ll N,a,b,c,d,e,f,g,T,M,k,ans;
int A[MAXN];
stack<pi> rev;
stack<pi> rev2;
vi outs;
int indexof[MAXN];
int PP;
vi des;

int procedure(int x){
  assert(x<=N && x>=-1);
  // t<<"procedure "<<x<<' '<<A[x]<<'\n';
  int l = 2*x;
  int r = 2*x+1;
  rev.push(mp(x,A[x]));
  if (x > N || (A[l] == 0 && A[r] == 0)){
    A[x]=0;
    if (x<=M)return 0; // invalid
    return 1;
  }
  if (A[l] > A[r]){
    A[x] = A[l];
    indexof[A[x]] = x;
    // cout<<"Change index "<<A[x]<<' '<<x<<'\n';
    rev2.push(mp(A[x],l));
    return procedure(l);
  }else{
    A[x] = A[r];
    indexof[A[x]] = x;
    // cout<<"Change index "<<A[x]<<' '<<x<<'\n';
    rev2.push(mp(A[x],r));
    return procedure(r);
  }
}

int run(int val){
  int ind = indexof[val];
  outs.pb(ind);
  while (SZ(rev))rev.pop();
  while (SZ(rev2))rev2.pop();
  int x = procedure(ind);
  // assert(SZ(rev) <= 20);
  // assert(SZ(rev2) <= 20);
  if (x == 0){
    // invalid
    while (SZ(rev)){
      A[rev.top().f] = rev.top().s;
      rev.pop();
    }
    while (SZ(rev2)){
      indexof[rev2.top().f] = rev2.top().s;
      // cout<<"Rev index "<<rev2.top().f<<' '<<rev2.top().s<<'\n';
      rev2.pop();
    }
    outs.pop_back();
    return 0;
  }else{
    // cout<<val<<'\n';
    ans -= des[val-1];
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>T;
  while(T--){
    cin>>N>>M;
    while (SZ(rev))rev.pop();
    while (SZ(rev2))rev2.pop();
    outs.clear();

    N = (1<<N)-1;
    M=(1<<M)-1;
    for (int i=1;i<=2*N+10;++i)A[i]=indexof[i]=0;
    ans=0;

    des.clear();
    for (int i=1;i<=N;++i){
      cin>>A[i];
      des.pb(A[i]);
      ans += A[i];
    }

    sort(ALL(des));

    for (int i=1;i<=N;++i){
      A[i] = lb(ALL(des), A[i]) - des.begin()+1;
      // cout<<A[i]<<'\n';
      indexof[A[i]] = i;
    }

    for (int i=N;i>=1;--i){
      if (SZ(outs) < N-M)run(i);
    }
    cout<<ans<<'\n';
    for (auto i : outs)cout<<i<<' ';cout<<'\n';
  }
}