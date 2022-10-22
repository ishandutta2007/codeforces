//*in the name of GOD*\\

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
  int n,sum = 0;
  string s, t;
  cin >> n >> s >> t;
  for(int i = 0; i < n; i++){
    sum += min({abs(s[i] - t[i] -10),abs(s[i] - t[i]),s[i] - t[i] + 10});
  }
  cout << sum;
}