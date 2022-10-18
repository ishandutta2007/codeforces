#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int n;cin>>n;
    int a=n&1,b=(n>>1)&1,c=(n>>2)&1,d=(n>>3)&1,e=(n>>4)&1,f=(n>>5)&1;
    cout<<((f<<5)|(a<<4)|(c<<3)|(d<<2)|(b<<1)|e);
    return 0;
}
//And after happily lived ever they
//and they lived happily ever after