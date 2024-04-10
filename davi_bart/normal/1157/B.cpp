#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
char cambio[10];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    string a;
    cin>>a;
    bool sub=0;
    for(int i=1;i<10;i++){
      cin>>cambio[i];
    }
    for(int i=0;i<N;i++){
      int o=a[i]-'0';
      if(sub){
        if(cambio[o]-'0'>=o)a[i]=cambio[o];
        else break;
      }else{
        if(cambio[o]-'0'>o){
          a[i]=cambio[o];
          sub=1;
        }
      }
    }
    cout<<a;
    return 0;
}