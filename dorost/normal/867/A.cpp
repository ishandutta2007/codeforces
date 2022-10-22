#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,s=0,f=0;
  string fs;
  cin>>n>>fs;
  for(int i = 1; i <= n; i++){
    if((fs[i]=='S') && (fs[i-1]=='F')){
      f++;
    }if((fs[i]=='F') && (fs[i-1]=='S')){s++;}
  }
  if(s > f){
    cout << "Yes";
  }else{
    cout << "No";
  }
}