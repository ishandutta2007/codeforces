#include<bits/stdc++.h>
using namespace std;
std::map<int, int> mp;
int a[2000010];
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }

  int cnt = 1;
  int now = 0;
  mp[0] = 1;
  for(int i=1;i<=n;i++){
    now ++;
  //  std::cout << cnt << '\n';
    if(mp[a[i]] > 0){
      mp[a[i]]--;
      mp[now]++;
    }
    else
    {
      mp[now]++;
      cnt++;
    }
  }
  std::cout << cnt << '\n';
  return 0;
}