#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000100
char string_b[SIZE],string_n[SIZE];
long long b,n,c;
long long Eular(long long x){
    long long i,an=x;
    for(i=2;i*i<=x;i++){
        if(x%i==0){
            an*=(i-1);
            an/=i;
            while(x%i==0)x/=i;
        }
    }
    if(x!=1){
        an*=(x-1);
        an/=x;
    }
    return an;
}
long long reduce(char s[],long long mod){
    int i;
    long long an=0;
    for(i=0;s[i];i++){
        an*=10;
        an+=s[i]-'0';
        an%=mod;
    }
    return an;
}
long long pow(long long x,long long y,long long mod){
    long long an=1;
    while(y){
        if(y&1){
            an*=x;
            an%=mod;
        }
        x*=x;
        x%=mod;
        y>>=1;
    }
    return an;
}
main(){
    long long cc,an;
    scanf("%s%s%lld",string_b,string_n,&c);
    cc=Eular(c);
    b=reduce(string_b,c);
    if(strlen(string_n)<3){
        an=((b+c-1)*pow(b,atoi(string_n)-1,c))%c;
    }
    else{
        n=reduce(string_n,cc);
        an=((b+c-1)*pow(b,n+cc-1,c))%c;
    }
    if(an==0)an=c;
    printf("%lld\n",an);
}