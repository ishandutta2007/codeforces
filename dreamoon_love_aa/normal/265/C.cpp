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
#define SIZE 1000010
char s[SIZE];
int rr[SIZE],ll[SIZE];
int main(){
    int i,j,k,n,nl,nr,mm;
    scanf("%s",s);
    n=strlen(s);
    nl=0,nr=n+1;
    mm=1;
    rr[0]=1;
    rr[1]=n+1;
    ll[1]=0;
    ll[n+1]=1;
    for(i=0;i<n-1;i++){
        if(s[i]=='r'){
            rr[i+2]=nr;
            ll[i+2]=mm;
            rr[mm]=i+2;
            ll[nr]=i+2;
            nl=mm;
            mm=i+2;
        }
        else{
            rr[i+2]=mm;
            ll[i+2]=nl;
            rr[nl]=i+2;
            ll[mm]=i+2;
            nr=mm;
            mm=i+2;
        }
    }
    int now=0;
    while(1){
        now=rr[now];
        if(now!=n+1)printf("%d\n",now);
        else break;
    }
    return 0;
}