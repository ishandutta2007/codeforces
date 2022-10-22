#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
int a[1009];
int sol[2000000];
int main(){
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      sol[a[i]+a[j]]++;
    }
  }
  int ma=0;
  for(int i=0;i<2000000;i++){
    if(sol[i]>ma)ma=sol[i];
  }
  cout<<ma;
  return 0;
}