#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main(){
  int n;
  cin >> n;
  int tot = 0;
  int preu = 10000;
  
  for(int i = 0; i < n; ++i){
    int a,p;
    cin >> a >> p;
    preu = min(preu, p);
    
    tot += preu * a;
  }
  
  cout << tot << endl;
}