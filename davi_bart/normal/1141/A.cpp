#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N,M;
    cin>>N>>M;
    if(M%N!=0){cout<<-1;
    return 0;
}
    int d=M/N;
    int f=0;
    while(1){
      if(d%3==0){
            d/=3;
        f++;
      }else break;
    }
    while(1){
      if(d%2==0){
        f++;
        d/=2;
      }else break;
    }
    if(d==1)cout<<f;
    else cout<<-1;
    return 0;
}