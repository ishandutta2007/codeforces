#include<bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;

int solve(set<int>&se, vector<int> &w)  {

  for(int i=0;i<(int)w.size();i++) {
    int x = w[i];
    if(se.find(x) != se.end()) {
      return x;
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<vector<int> > v (n,std::vector<int> (n));
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin>>v[i][j];
    }
  }
  std::vector<int> w(n);
  for(int i=0;i<n;i++) {
    std::cin >> w[i];
  }
  for(int i=0;i<n;i++) {
    set<int>s,se;
    for(int j=0;j<n;j++) {
      if(i!=j){
        se.insert(j+1);
        s.insert(solve(se,w));
        //cout<<endl<<"insert :" << solve(se,w)<<endl;
      }
    }
    if(i>0) cout<<" ";
    std::cout << solve(s,v[i]);
  }
  std::cout  << '\n';
  return 0;
}