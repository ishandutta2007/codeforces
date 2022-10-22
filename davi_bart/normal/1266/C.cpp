#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[505][505];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        a[i][j]=(N+1)*(i+1)+(i+1)*j;
      }
    }
    if(N*M==1){
      cout<<0;
      return 0;
    }
    if(M==1){
      for(int i=0;i<N;i++)cout<<i+2<<endl;
      return 0;
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}