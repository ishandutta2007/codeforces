#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distancer
#define INF 1000000000

int N,M,Q;
int A[100100], B[100100];

int main(){
  cin >> N >> Q;
  for (int i = 0; i < N; ++i){cin >> A[i];B[i] = A[i];}
  sort(B,B+N);
  for (int i = 0; i < Q; ++i){
    if (M >= B[N-1]){cout << 0 << '\n';continue;}
    int it = *ub(B,B+N,M);
    cout << it-M << '\n';
    M = it;
  }
}