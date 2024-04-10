#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

string s;
ll memo[100100][5];
ll N;
ll A[100100];
string HARD = "hard";

int main(){
  cin>>N>>s;
  for (int i=0;i<N;++i)cin>>A[i];
  if (s[0] == 'h')memo[0][0] = A[0];
  for (int i=1;i<N;++i){
    for (int j=0;j<4;++j){
      memo[i][j] = memo[i-1][j];
      if (HARD[j] == s[i])memo[i][j] += A[i]; 
      if (j != 0)memo[i][j] = min(memo[i][j], memo[i][j-1]);
      // cout << memo[i][j]<<' ';
    }
    // cout<<'\n';
  }
  cout << min({memo[N-1][0], memo[N-1][1], memo[N-1][2], memo[N-1][3]});
}