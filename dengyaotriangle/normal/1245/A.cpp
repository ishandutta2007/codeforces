#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<(gcd(a,b)==1?"Finite\n":"Infinite\n");
    }
    return 0;
}