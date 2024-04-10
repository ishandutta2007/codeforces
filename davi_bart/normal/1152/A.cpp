#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N,M;
    cin>>N>>M;
    int paricassa=0,disparicassa=0,parichiave=0,disparichiave=0;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      if(a%2==0)paricassa++;
      else disparicassa++;
    }
    for(int i=0;i<M;i++){
      int a;
      cin>>a;
      if(a%2==0)parichiave++;
      else disparichiave++;
    }
    cout<<min(parichiave,disparicassa)+min(disparichiave,paricassa);
    return 0;
}