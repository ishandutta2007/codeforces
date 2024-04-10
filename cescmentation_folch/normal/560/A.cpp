#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  int r = 1;
  for(int i =0;i < n;++i){
    int k;
    cin>>k;
    if(k == 1) r = -1;
  }
  cout<<r<<endl;
}