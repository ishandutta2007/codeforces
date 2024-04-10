#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int main(){
    int i,j,k,n,x1,x2,a,b,ll,rr;
    scanf("%d%d%d%d",&x1,&x2,&a,&b);
    if(x1+a<=x2&&x2<=x1+b){
        puts("FIRST");
        cout<<x2<<endl;
        return 0;
    }
    if(x1<x2){
        if(a<=0){
            puts("DRAW");
            return 0;
        }
        ll=a,rr=b;
    }
    else{
        if(b>=0){
            puts("DRAW");
            return 0;
        }
        ll=-b,rr=-a;
    }
    n=abs(x2-x1);
    n%=(ll+rr);
    if(n==0)puts("SECOND");
    else if(n<ll||n>rr)puts("DRAW");
    else{
        puts("FIRST");
        if(x1<x2)cout<<x1+n<<endl;
        else cout<<x1-n<<endl;
    }
    return 0;
}