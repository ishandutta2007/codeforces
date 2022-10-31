#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if(a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  long long a, b;
  cin >> a >> b;
  long long dif = abs(a-b);
  pair<long long, long long> cur;
  long long c = a, d = b;
  cur.first = a*b/gcd(a, b);
  cur.second = 0;
  for(long long i = sqrt(dif); i>=1; i--){
    if(dif % i != 0) continue;
    long long temp = dif / i;
    if((c+temp-c%temp)*(d+temp-d%temp)/(gcd((c+temp-c%temp), d+temp-d%temp))<=cur.first){
      cur.first = (c+temp-c%temp)*(d+temp-d%temp)/(gcd((c+temp-c%temp), d+temp-d%temp));
      cur.second = temp - c%temp;
    }
    temp = i;
    if((c+temp-c%temp)*(d+temp-d%temp)/(gcd((c+temp-c%temp), d+temp-d%temp))<=cur.first){
      cur.first = (c+temp-c%temp)*(d+temp-d%temp)/(gcd((c+temp-c%temp), d+temp-d%temp));
      cur.second = temp - c%temp;
    }
  }
  cout << cur.second << endl;
}