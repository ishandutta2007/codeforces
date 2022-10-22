#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
int c[1000];
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      int a;
      cin>>a>>c[i];
    }
  int K;
  cin>>K;
  for(int i=0;i<N;i++){
    if(K<=c[i]){
      cout<<N-i;
      return 0;
    }
  }
  cout<<0;
    return 0;
}