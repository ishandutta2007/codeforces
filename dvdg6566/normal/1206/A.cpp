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
int N,M,a;
set<int> A,B;
int main(){
  cin>>N;
  for (int i=0;i<N;++i){cin>>a;A.insert(a);}
  cin>>M;
  for (int i=0;i<M;++i){cin>>a;B.insert(a);}
  for (auto i : A){
    for (auto j : B){
      int k = i+j;
      if (A.lb(k) == A.ub(k) && B.lb(k) == B.ub(k)){
        cout<<i<<' '<<j;
        return 0;
      }
    }
  }
}