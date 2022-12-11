#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define For(i,a,f) for(int i = a; i < f; ++i)
#define foR(i,a,f) for(int i = a; i > f; --i)


bool prim(int n){
  for(int i = 2;i*i <= n; ++i){
    if(n%i == 0) return false;
  }
  return true;
}

int main(){
  int n;
  cin>>n;
  if(prim(n)) cout<<1<<endl<<n<<endl;
  else {
    cout<<3<<endl<<3<<' ';
    int i = 3;
    while(1){
      if(prim(i) and prim(n-3-i)) {
	cout<<i<<' '<<n-3-i<<endl;
	break;
      }
      i += 2;
    }
  }
}