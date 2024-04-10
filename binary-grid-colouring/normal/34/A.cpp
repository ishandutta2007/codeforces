#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;std::vector<int> a(n+1);
  for (size_t i = 0; i < n; i++) {
    /* code */
    cin>>a[i];
  }
  a[n] = a[0];
  int min = 1e9,flag = 0;
  for (size_t i = 0; i < n; i++) {
    /* code */
    if(abs(a[i]-a[i+1])<min){
      min = abs(a[i]-a[i+1]);
      flag = i;
    }
  }
  std::cout << flag%n+1 <<" "<<(flag+1)%n+1 << '\n';
  return 0;
}