#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;
  if(((a * b) + d + d) < ((a * c) + e + e)){
    cout <<"First";
  }else if(((a * b) + d + d) > ((a * c) + e + e)){
    cout << "Second";
  }else{
    cout << "Friendship";
  }
}