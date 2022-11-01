#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bitset< N > bs;
vector< int > prime;

bool isPrime(int n) {
  if(n < 2)
    return false;
  if(n < N)
    return bs[n];
  int m = sqrt(n) + 1;
  for(int i = 0; prime[i] <= m; i++)
    if(n % prime[i] == 0)
      return false;
  return true;
}

bool cektwo(int n, pair<int, int > &p) {
  p = make_pair(-1, -1);
  int r = (n % 6);
  if(isPrime(n-2)) {
    p = make_pair(2, n-2);
    return true;
  }
  if(isPrime(n-3)) {
    p = make_pair(3, n-3);
    return true;
  }
  if(r == 1 || r == 3 || r == 5)
    return false;
  int x = n/2 + 2;
  for(int i = 6; i<= x; i+= 6) {
    if(isPrime(i-1) && isPrime(n-i+1)) {
      p = make_pair(i-1, n-i+1);
      return true;
    }
    if(isPrime(i+1) && isPrime(n-i-1)) {
      p = make_pair(i+1, n-i-1);
      return true;
    }
  }
  return false;
}

int  main() {
  int n;
  bs[0] = bs[1] = 0;
  bs.set();
  for(int i = 2; i<N; i++) if(bs[i]) {
    prime.push_back(i);
    for(long long j = 1LL*i*i; j< N; j+=i)
      bs[j] = false;
  }
  cin >> n;
  if(isPrime(n)) {
    cout << 1 << "\n" << n << "\n";
  }
  else if(isPrime(n-2)){
    cout << 2 << "\n" << 2 << " " <<  n-2 << "\n";
  }
  else {
    cout << 3 << "\n";
    pair<int , int >  ans;
    if(cektwo(n-3, ans)) { 
      cout << 3 << " " << ans.first << " " << ans.second << "\n";
      return 0;
    }
    else {
      int x = n/2 + 2;
      for(int i = 6; i<= x; i+= 6) {
        if(isPrime(i-1) && cektwo(n-i+1, ans)) {
          cout << i-1 << " " << ans.first << " " << ans.second << "\n";
          return 0;
        }
        if(isPrime(i+1) && cektwo(n-i-1, ans)) {
          cout << i+1 << " " << ans.first << " " << ans.second << "\n";
          return 0;
        }
      }
    }
  }
  return 0;
}