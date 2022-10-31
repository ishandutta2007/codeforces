#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if(a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  long long n, k;
  cin >> n >> k;
  long long a, b;
  cin >> a >> b;
  long long start = a+1;
  long long end;
  bool side;
  if(b > a){
    end = b+1;
    side = false;
  }
  else{
    end = k-b+1;
    side = true;
  }
  long long t = n*k;
  long long mi = LONG_LONG_MAX, ma = LONG_LONG_MIN;
  while(end - start <= t){
    long long te = end - start;
    long long cycle = t/gcd(te, t);
    if(cycle < mi) mi = cycle;
    if(cycle > ma) ma = cycle;
    if(side) end += 2*b;
    else end+= k-2*b; 
    side = !side;
  }
  cout << mi << " " << ma << endl;
}