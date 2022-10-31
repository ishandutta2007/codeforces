#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("a.in", "r", stdin);
  int n, m; cin >> n >> m;
  set<string> st;
  for(int i = 0; i<n; i++){
    string s; cin >> s;
    st.insert(s);
  }
  vector<string> v1;
  vector<string> v2;
  int ans = 0;
  string add = "";
  while(!st.empty()){
    string ss = *st.begin();
    string sss = ss;
    reverse(ss.begin(), ss.end());
    st.erase(st.begin());
    if(st.count(ss)){
      v1.push_back(sss);
      v2.push_back(ss);
      ans += m*2;
      st.erase(ss);
    }
    else{
      if(ss == sss){
        if(ss.length() > add.length()) add = ss;
      }
    }
  }
  ans += add.length();
  reverse(v2.begin(), v2.end());
  string fin = "";
  for(auto x : v1) fin += x;
  fin += add;
  for(auto x : v2) fin += x;
  cout << ans << endl;
  cout << fin << endl;
}