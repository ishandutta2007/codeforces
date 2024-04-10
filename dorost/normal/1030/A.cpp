#include <bits/stdc++.h>
using namespace std;

int main(){
  int koft = 1000000;
  int n,a[koft],sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum=sum+a[i];
  }
  if(sum){
    cout<<"hard";//
  }else{
    cout<<"easy";
  }
}