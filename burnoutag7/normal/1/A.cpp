#include<iostream>
using namespace std;
long long n,m,a;
int main(){
  cin>>n>>m>>a;
  cout<<(n+a-1)/a*((m+a-1)/a)<<endl; 
  return 0;
}