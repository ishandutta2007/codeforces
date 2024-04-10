#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 101000
#define MAXL 18

string S;
int A,N;

int main(){
  cin>>N;
  cin>>S;
  for (auto i : S){
    if (i == '(')++A;
    else --A;
  }
  if (A != 0){cout<<"No";return 0;}
  int first = 1;
  A = 0;
  for (auto i : S){
    if (i == '(')++A;
    else --A;
    if (A == -1 && first){
      first = 0;
      A = 0;
    }else if (A == -1){
      cout<<"No";
      return 0;
    }
  }
  cout<<"Yes";
}