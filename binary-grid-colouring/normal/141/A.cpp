#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  string s,ss,sss;
  std::cin >> s;
  std::cin >> ss;
  string news;
  news = s+ss;
  sort(news.begin(),news.end());
  std::cin >> sss;
  sort(sss.begin(),sss.end());
  if(news == sss){
    std::cout << "YES" << '\n';
  }
  else
  {
    std::cout << "NO" << '\n';
  }
  return 0;
}