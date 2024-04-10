#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  if(((3 * f) + (((abs(a - b)) + abs(c - a)) * e)) > (d * (abs(a - b)))){
    cout << "NO";
  }else{
    cout << "YES";
  }
}