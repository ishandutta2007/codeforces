#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int a;cin>>a;
    for(int i=2;i<=a;i++){
        if(a%i==0){
            cout<<i<<a/i;
            return 0;
        }
    }
    return 0;
}