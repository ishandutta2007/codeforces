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

int N,M,a;
int A[100100];
multiset<int> S;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i=0;i<N;++i)S.insert(0);
  for (int i=0;i<M;++i){
    cin >> a;
    int x = A[a];
    S.erase(S.find(A[a]));
    S.insert(A[a] + 1);
    ++A[a];
    if (A[a] == *(S.begin()))cout << 1;
    else cout << 0;
  }
}