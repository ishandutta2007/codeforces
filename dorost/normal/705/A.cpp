#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  for(int i=0;i < a; ++i){
    if(i % 2){
      cout << "I love ";
    }else{
      cout << "I hate ";
    }
    if(i==a-1){
      cout << "it ";
    }else{
      cout << "that ";
    }
  }
}