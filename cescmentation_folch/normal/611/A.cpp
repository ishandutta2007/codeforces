#include<bits/stdc++.h>

using namespace std;

int m[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ini = 4;

int main(){
  int x;
  cin >> x;
  string a;
  cin >> a >> a;
  int res = 0;
  if(a == "week") {
    for(int i = 1; i <= 366; ++i){
      if((i + ini)%7 == x%7) ++res;
    }
  }
  else {
    for(int i = 0; i < 12; ++i){
      if(x <= m[i]) ++res;
    }
  }
  cout << res << endl;
}