#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  vector<int> p;
  vector<int> ok;
  int n,k;
  cin >> n >> k;
  for(int i = 2; i <= k; ++i) {
    if(k%i == 0) {
      int pp = 1;
      while(k%i==0) {
        k/=i;
        pp*=i;
      }
      p.push_back(pp);
      ok.push_back(0);
    }
  }
  for(int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    for(int j = 0; j < p.size(); ++j)
      if(c%p[j]==0) ok[j]=1;
  }
  for(int i = 0; i < p.size(); ++i) {
    if(!ok[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}