#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0;
        return 0;
    }
    if(a>b)swap(a,b);
    int diff=b-a;
    if((b-a)<a){
        if(a%diff==0)cout<<0;
        else
      cout<<diff-(a%diff);
    }else{
      for(int i=a;i<=diff/2;i++){
        if(diff%i==0){
            cout<<i-a;
            return 0;
        }
      }
      cout<<diff-a;
    }
    return 0;
}