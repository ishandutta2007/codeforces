#include<iostream>
#include<algorithm>
using namespace std;
int n,a[10000000];
int main(){
  cin>>n;for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  for(int i=0;i<n;i++){
    if(i)cout<<' ';
    cout<<a[i];
  }
  cout<<endl;
  return 0;
}