#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        puts(gcd(a,b)==1?"Finite":"Infinite");
    }
    return 0;
}