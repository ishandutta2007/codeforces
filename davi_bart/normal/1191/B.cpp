#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    string a[3];
    cin>>a[0]>>a[1]>>a[2];
    if(a[0]==a[1] && a[0]==a[2]){
      cout<<0;
      return 0;
    }
    sort(a,a+3);
    if(a[0][1] == a[1][1] && a[1][1]==a[2][1] && a[0][0]==a[1][0]-1 && a[1][0]==a[2][0]-1){
      cout<<0;
      return 0;
    }
    if(a[0]==a[1] || a[1]==a[2]){
      cout<<1;
      return 0;
    }
    if(a[0][1]==a[1][1] && a[0][0]==a[1][0]-1){
      cout<<1;
      return 0;
    }
    if(a[0][1]==a[2][1] && a[0][0]==a[2][0]-1){
      cout<<1;
      return 0;
    }
    if(a[1][1]==a[2][1] && a[1][0]==a[2][0]-1){
      cout<<1;
      return 0;
    }
    if(a[0][1]==a[1][1] && a[0][0]==a[1][0]-2){
      cout<<1;
      return 0;
    }
    if(a[0][1]==a[2][1] && a[0][0]==a[2][0]-2){
      cout<<1;
      return 0;
    }
    if(a[1][1]==a[2][1] && a[1][0]==a[2][0]-2){
      cout<<1;
      return 0;
    }
    cout<<2;
    return 0;
}