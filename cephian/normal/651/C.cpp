#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<int, int> x,y;
map<pii, int> s;


void addp(int a, int b) {
  ++x[a];
  ++y[b];
  ++s[pii(a,b)];
}

ll c2(ll a) {
  return (a*(a-1))/2;
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    int a,b;
    cin >> a >> b;
    addp(a,b);
  }
  ll ans = 0;
  for(map<int,int>::iterator i = x.begin(); i != x.end(); ++i)
    ans += c2(i->second);
  for(map<int,int>::iterator i = y.begin(); i != y.end(); ++i)
    ans += c2(i->second);
  for(map<pii,int>::iterator i = s.begin(); i != s.end(); ++i)
    ans -= c2(i->second);
  cout << ans << "\n";
}