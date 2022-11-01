#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
  int n;
  std::cin>>n;
  std::vector<int> g(255,-1);
  std::vector<int> in(255);
  std::vector<bool> vv(255);
  for(int i=0;i<n;i++){
    std::vector<bool> v(255);
    std::string s;
    std::cin>>s;
    v[s[0]] = vv[s[0]] = true;
    for(int i=1;i<(int)s.size();i++){
      char c = s[i];
      if(v[c] || ((g[s[i-1]] != -1 || in[c]) && g[s[i-1]] != s[i]))
      {
        std::cout << "NO" << '\n';
        exit(0);
      }
      v[c] = true;
      g[s[i-1]]  = s[i];
      vv[c] = true;
      in[c] ++;
    }
  }
  int cnt = 0;
  for(auto x : vv){
    cnt += x;
  }
  std::string s;
  for(int i='a';i<='z';i++){
    if (!in[i] && vv[i]) {
      for(int j=i;j!=-1;j=g[j])
      {
        s += char(j);
      }
    }
  }
  if ((int)s.size()!=cnt) {
    std::cout << "NO" << '\n';
    exit(0);
  }
  std::cout << s << '\n';
  return 0;
}