#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
string s;

int nm(char c) {
  if(c >= '0' && c <= '9') return c-'0';
  if(c >= 'A' && c <= 'Z') return c-'A'+10;
  if(c >= 'a' && c <= 'z') return c-'a'+36;
  if(c == '-') return 62;
  return 63;
}

int zero(int c) {
  int bc = 0;
  while(c) {
    bc += c&1;
    c/=2;
  }
  return 6-bc;
}

ll pw(ll a, ll b) {
  if(!b) return 1;
  if(b&1) return (a*pw(a,b-1))%MOD;
  ll t = pw(a,b/2);
  return (t*t)%MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> s;
  int z = 0;
  for(int i = 0; i < s.size(); ++i)
    z += zero(nm(s[i]));
  cout << pw(3,z) << "\n";
}