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
    int N;
    cin>>N;
    int ini=0;
    int mi=0;
    int val=0;
    bool p=0;
    for(int i=0;i<N;i++){
      bool a;
      cin>>a;
      if(a==0)p=1;
      if(p==0)ini++;
      if(a)val++;
      else val=0;
      if(val>mi)mi=val;
    }
    if(ini+val>mi)mi=ini+val;
    cout<<mi;
    return 0;
}