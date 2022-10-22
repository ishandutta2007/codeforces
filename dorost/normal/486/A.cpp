//***In the name of GOD***\\

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(s) s.size()
long long cf(long long x){
  if(x % 2){
    return ((x - 1) / 2) - x;
  }
  return x / 2;
}
int main(){
  long long a;
  cin >> a;
  cout << cf(a);
}