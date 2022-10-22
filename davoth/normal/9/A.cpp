#include <iostream>
using namespace std;

int main(){
    int a,b,n;
    cin>>a>>b;
    if(a>b){
        n=7-a;
    }else{
        n=7-b;
    }
    if(n==6){
        cout<<"1/1";
    }else if(n==5){
        cout<<"5/6";
    }else if(n==4 || n==2){
        cout<<n/2<<"/"<<3;
    }else if(n==1){
        cout<<"1/6";
    }else{
        cout<<"1/2";
    }
    return 0;
}