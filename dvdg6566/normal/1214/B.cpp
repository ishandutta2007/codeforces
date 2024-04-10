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

int A,B,C;

int main(){
  cin>>A>>B>>C;
  if (A >= C)cout<<min(B,C)+1;
  else if (B >= C)cout<<min(A,C)+1;
  else{
    cout<<A - (C-B) + 1;
  }
}