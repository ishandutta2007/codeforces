#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
char a[55][55];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        cin>>a[i][j];
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(a[i][j]=='#')continue;
        if(j==0 || j==N-1 || i>N-3){
          cout<<"NO";
          return 0;
        }
        if(a[i+1][j-1]=='.' && a[i+1][j]=='.' && a[i+1][j+1]=='.' && a[i+2][j]=='.'){
          a[i][j]='#';
          a[i+1][j-1]='#';
          a[i+1][j]='#';
          a[i+1][j+1]='#';
          a[i+2][j]='#';
        }else{
            cout<<"NO";
          return 0;
        }
      }
    }
    cout<<"YES";
    return 0;
}