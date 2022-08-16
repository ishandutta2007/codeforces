#include <bits/stdc++.h>

using namespace std;

bool isp(int a){
  if(a<2) return false;
  for(int i=2;i*i<=a;++i){
    if(a%i==0) return false;
  }
  return true;
}
bool isDiv(int d){
  cout << d << endl;
  string s;
  cin >>s;
  return s[0] == 'y';
}

int main()
{
  int cnt=0;
  for(int i=1;i<=50;++i){
    if(!isp(i))continue;
    if(isDiv(i)){
      ++cnt;
      if(i*i<=100){
        if(isDiv(i*i)){
          cout << "composite" << endl;
          return 0;
        }
      }
    }
  }
  cout << (cnt<2 ? "prime\n" : "composite\n");

  return 0;
}