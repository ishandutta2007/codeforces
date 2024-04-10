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
int A,B;

int query(int a, int b){
  cout << '?' << ' ' << a << ' ' << b << '\n';
  fflush(stdout);
  int x;
  cin >> x;
  return x;
}

int main(){
  int big = query(0,0);
  if (big == 0){
    for (int i = 29; i >= 0; --i){
      int x = (1<<i);
      int r = query(A+x,A);
      if (r == -1){
        A += x;
        B += x;
      }
    }
    cout << "! " << A << ' ' << B << '\n';
     fflush(stdout);
    return 0;
  }
  for (int i = 29; i >= 0; --i){
    int x = (1<<i);
    int r = query(A+x,B+x);
    if (r == 0){
      for (int j = i; j >= 0; --j){
        int x = (1 << j);
        r = query(A+x,B);
        if (r == -1){
          A += x;
          B += x;
        }
      }
      cout << "! " << A << ' ' << B << '\n';
      fflush(stdout);
      return 0;
    }
    if (r != big){
      // Means the bigger one got bits
      if (big == 1){
        A += x;
      }else{
        B += x;
      }
      big = query(A,B);
      continue;
    }
    if (big == 1)r = query(A,B+x);
    else r = query(A+x,B);
    if (r == big){
      // Means both have bits
      A += x;
      B += x;
    }
  }
  cout << "! " << A << ' ' << B << '\n';
  fflush(stdout);
}