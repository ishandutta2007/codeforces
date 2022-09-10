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
long long f(long long x){
    if(x<=1000){
        int i,res=0;
        for(i=1;i<=x;i++){
            char s[12];
            sprintf(s,"%d",i);
            if(s[0]==s[strlen(s)-1])res++;
        }
        return res;
    }
    int i,j;
    long long res=18,ten=100;
    for(i=3;i<=18;i++,ten*=10){
        if(ten*10<=x)res+=9*ten/10;
        else{
            for(j=1;j<=9;j++){
                if(j<x/ten)res+=ten/10;
                else{
                    res+=x%ten/10+(j<=x%10);
                    break;
                }
            }
            break;
        }
    }
    return res;
}
int main(){
    int i,j,k,n;
    long long ll,rr;
    cin>>ll>>rr;
    cout<<f(rr)-f(ll-1)<<endl;
    return 0;
}