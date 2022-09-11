#include<iostream>
#include<stdio.h>
char s[5][16]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
using namespace std;
main(){
    long long now=1,n,an;
    cin>>n;
    while(n>now*5){
        n-=now*5;
        now*=2;
    }
    an=(n-1)/now;
    puts(s[an]);
}