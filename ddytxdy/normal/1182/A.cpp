#include<bits/stdc++.h>
using namespace std;
int n;
int power(int x,int y){
    int ret=1;
    while(y){
        if(y&1)ret*=x;
        x*=x;y>>=1;
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    if(n&1)puts("0");
    else cout<<power(2,n>>1);
}