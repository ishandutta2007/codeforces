#include<iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int mi = 1000,mip = 0,ma = 0,map = n-1;
  for(int i = 0;i < n;++i){
    int k;
    cin>>k;
    if(k > ma){
      ma = k;
      map = i;
    }
    if(k <= mi){
      mi = k;
      mip = i;
    }
    
    
  }
  int res = map+n-mip-1;
    if(map+n-mip > n) --res;
    //cout<<mip<<" "<<map<<endl;
    cout<<res<<endl;
}