#include <iostream>
#include <queue>


using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;
  bool flag = false;
  for(int i=0;i<a.size();++i){
    if(a[i] == b[i]) continue;
    if(flag) a[i] = b[i];
    flag=!flag;
  }
  if(flag) cout << "impossible";
  else cout << a;


  return 0;
}