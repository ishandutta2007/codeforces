#include<bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;


int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  vector<int>a(n+1,0);
  for(int i=1;i<=n;i++) {
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  std::vector<int> s(n+1);
  s[0] = 10;

  for(int i=1;i<=n;i++) {
    s[i] = s[i-1] + a[i];
  }
  int ans = 0;
  for(int i=1;i<=n;i++) {
    if(s[i] > 720) break;
    ans = i;
  }
  int sum = 0;
  for(int i=1;i<=ans;i++) {
    sum += max(0,s[i]-360);
  }
  std::cout << ans << " " << sum << '\n';
}