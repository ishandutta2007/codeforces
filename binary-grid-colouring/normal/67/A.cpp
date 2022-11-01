#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const ll INF =2e15;
int n;
int ans[1234];
string s;
int main(int argc, char const *argv[]) {
  std::cin >> n;
  std::cin >> s;
  while(true) {
    int flag = 0;
    for(int i=0;i<n-1;i++) {
        if(s[i]=='L') {
          if(ans[i] < ans[i+1]+1) {
            ans[i] = ans[i+1]+1;
            flag++;
          }
        }
        if(s[i]=='R') {
          if(ans[i+1] < ans[i]+1) {
            ans[i+1] = ans[i] +1;
            flag++;
          }
        }
        if(s[i]=='=') {
          if(ans[i]>ans[i+1]) {
            ans[i+1] = ans[i];
            flag++;
          }
          if(ans[i]<ans[i+1]) {
            ans[i] = ans[i+1];
            flag++;
          }
        }
    }
    if(flag==0)break;
  }
  for(int i=0;i<n-1;i++) {
    std::cout << ans[i]+1 << " ";
  }
  std::cout << ans[n-1]+1 << '\n';
  return 0;
}