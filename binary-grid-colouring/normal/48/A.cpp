#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<string>se;

bool gao(string st1,string st2)
{
    if (st1[0]=='p'&&st2[0]=='r')return true;
    if (st1[0]=='s'&&st2[0]=='p')return true;
    if (st1[0]=='r'&&st2[0]=='s')return true;
    return false;
}
int main(int argc, char const *argv[]) {
  string s,ss,sss;
  std::cin >> s >> ss >> sss;
  se.insert(s);
  se.insert(ss);
  se.insert(sss);
  if(se.size()==1) {
    std::cout << "?" << '\n';
    return 0;
  }
  if (gao(s,ss)&&ss==sss)cout<<"F"<<endl;
  else if (gao(ss,sss)&&s==sss)cout<<"M"<<endl;
  else if (gao(sss,s)&&s==ss)cout<<"S"<<endl;
  else cout<<"?"<<endl;
  return 0;
}