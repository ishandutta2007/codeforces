#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cal(int plus,int mius,int a,int b,int c,int d,int e)
{
  int ans = plus*100-mius*50+a+b+c+d+e;
  // std::cout << "ans=" << ans << '\n';
  return ans;
}
int main(int argc, char const *argv[]) {

  string s,s1;
  int plus,mius;
  int a,b,c,d,e;
  int n;
  int plus1,mius1;
  int a1,b1,c1,d1,e1;
  std::cin >> n;
  string ans;
  std::cin >> s1 >> plus1 >> mius1 >> a1 >> b1 >> c1 >> d1 >> e1;
  int res = plus1*100-mius1*50+a1+b1+c1+d1+e1;
  ans = s1;
  for(int i=1;i<n;i++) {
    std::cin >> s >> plus >> mius >> a >> b >> c >> d >> e;
    if(cal(plus,mius,a,b,c,d,e) > res) {
       ans = s;
       res = cal(plus,mius,a,b,c,d,e);
    }
  }
  std::cout << ans << '\n';
  return 0;
}