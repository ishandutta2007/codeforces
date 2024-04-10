//*in the name of GOD*\\

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// cout << fixed << setprecision(6);
int main(){
  int n , k;
  cin >> n >> k;
  int ans = ceil((double)(n * 8) / k) + ceil((double)(n * 5) / k) + ceil((double)(n * 2) / k);
  cout << fixed << setprecision(0);
  cout << ans;
}