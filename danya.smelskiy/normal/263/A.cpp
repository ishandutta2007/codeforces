#include <bits/stdc++.h>
using namespace std;
int a[6][6];
int x,y;
 int main(){
    for (int i=1;i<=5;++i){
        for (int j=1;j<=5;++j){
            cin>>a[i][j];
            if (a[i][j]==1) { x=i; y=j;}
        }
    }
   /* for (int i=1;i<=5;++i){
        for (int j=1;j<=5;++j)cout<<a[i][j]<<" ";
        cout<<endl;
    }*/
  //  cout<<x<<" "<<y<<endl;
    cout<<abs(3-x)+abs(3-y);
 }