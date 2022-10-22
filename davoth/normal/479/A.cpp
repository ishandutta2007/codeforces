#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==1&&b==1&&c==1){
        cout<<3;
    }else if(a==1&&b==1){
        cout<<2*c;
    }else if(b==1&&c==1){
        cout<<2*a;
    }else if(a==1&&c==1){
        cout<<b+2;
    }else if(a==1){
        cout<<(b+1)*c;
    }else if(c==1){
        cout<<(b+1)*a;
    }else if(b==1){
        if(c>a){
            cout<<(a+1)*c;
        }else{
            cout<<(c+1)*a;
        }
    }else{
        cout<<a*b*c;
    }
    return 0;
}