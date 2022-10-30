#include <bits/stdc++.h>
using namespace std;
string s;
int n;

bool work(int m){
  for(int i = 0; i<m; i++){
    int num = s[i] == '1';
    for(int k = i+m; k != i; k = (k+m)%n) if(s[k] == '1') num++;
    if(num % 2 == 1) return false;
  }
  return true;
}

int main() {
  cin >> n;
  cin >> s;
  bool special = true;
  for(int i = 0; i<n; i++) if(s[i] != '0') special = false;
  if(special){
    cout << n << endl;
    return 0;
  }
  set<int> st;
  for(int i = 1; i<n; i++){
    if(n%i != 0) continue;
    if(work(i)) st.insert(i);
  }
  int ans = 0;
  for(int i = 1; i<n; i++){
    if(st.find(__gcd(i, n)) != st.end()) ans++;
  }
  cout << ans << endl;
}