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
char s[1000000];
int pn(int x){
    if(x>0)return 1;
    return -1;
}
int main(){
    int i,j,k,n,m,a,b;
    scanf("%d%d",&n,&m);
    gets(s);
    gets(s);
    a=atoi(s);
    gets(s);
    b=atoi(s);
    if(m>n)printf("0/1\n");
    else if(m<n){
        if(a*b<0)puts("-Infinity");
        else puts("Infinity");
    }
    else{
        printf("%d/%d\n",pn(a*b)*abs(a)/__gcd(abs(a),abs(b)),abs(b)/__gcd(abs(a),abs(b)));
    }
    return 0;
}