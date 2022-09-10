#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
main(){
    long long n,k,p,x,even,odd;
    cin>>n>>k>>p;
    if(k+k<=n)even=k;
    else even=n-k;
    if(n&1){
        if(!((k-even)&1)&&even)even--;
    }
    else{
        if((k-even)&1)even--;
    }
    odd=k-even;
    while(p--){
        cin>>x;
        x=n+1-x;
        if(x<=odd)putchar('X');
        else{
            x-=odd;
            if(x>2*even)putchar('.');
            else{
                if(x&1)putchar('X');
                else putchar('.');
            }
        }
    }
    puts("");
}