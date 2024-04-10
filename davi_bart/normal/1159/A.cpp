#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
char a[101];
int main(){
  int N;
  cin>>N;
  int p=0;
  int mi=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    if(a[i]=='-')p--;
    else p++;
    if(p<mi)mi=p;
  }
  p=-mi;
  for(int i=0;i<N;i++){
    if(a[i]=='-')p--;
    else p++;
  }
  cout<<p;
  return 0;
}