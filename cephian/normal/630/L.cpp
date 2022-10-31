#include <iostream>
#include <iomanip>

using namespace std;
typedef long long ll;

int main() {
  string a;
  cin >> a;
  ll n = 10000*(a[0]-'0')+1000*(a[2]-'0')+100*(a[4]-'0')+10*(a[3]-'0')+1*(a[1]-'0');
  ll k = n*n;
  k %= 100000;
  k*=n;
  k %= 100000;
  k*=n;
  k %= 100000;
  k*=n;
  k %= 100000;
  cout << setfill('0') << setw(5);
  cout << k << "\n";
}