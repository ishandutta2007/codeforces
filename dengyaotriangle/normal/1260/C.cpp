#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

#define No "REBEL"
#define Yes "OBEY"
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int g=gcd(a,b);a/=g;b/=g;
        if(a==b){
            if(k==1){
                puts(No);
            }else puts(Yes);
            continue;
        } 
        if(a<b)swap(a,b);
        if(b==1){
            int c=a-1;
            if(k>c)puts(Yes);
            else puts(No);
            continue;
        }
        int l=a/b,r=(a+b-2)/b;
        if(r>=k){
            puts(No);
        }else puts(Yes);/*
        for(int i=0;i<=a*b;i++){
            if(!(i%a)&&!(i%b))cout<<'x';
            else if(!(i%a))cout<<'a';
            else if(!(i%b))cout<<'b';
        }
        cout<<','<<l<<','<<r<<endl;*/
    }
    return 0;
}