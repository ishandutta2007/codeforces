#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000

int D[30100];
int N,T;

int main(){
  cin >> N >> T;
  D[N] = -1;
  for(int i = 1; i < N; ++i){
    cin >> D[i];
    D[i] += i;
  }
  int c = 1;
  while (c < N){
    c = D[c];
    if (c == T){cout << "YES";return 0;}
  }
  cout << "NO";
}