#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b=0;
  cin>>a;
  for(int i=0; i < a; i++){
    if(a % (i+1)==0){
      b++;
    }
  }
  cout << b - 1; 
}