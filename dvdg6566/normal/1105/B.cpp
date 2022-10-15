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
#define INF 10000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int N,K,ans;
int A[30];
string S;

int main(){
  cin>>N>>K>>S;
  for (int i=0;i<N;++i){
    int x = i;
    while(i<N){
      ++i;
      if (i == N)break;
      if (S[i] != S[x])break;
    }
    x = i - x;
    --i;
    A[S[i] - 'a'] += max(0, x/K);
  }  
  cout<<*max_element(A,A+27);
}