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
char s1[1024],s2[1024];
int l1,l2,d1[1024],d2[1024];
int win[3][3]={{0,1,0},{0,0,1},{1,0,0}};
int to(char c){
    if(c=='R')return 0;
    if(c=='P')return 1;
    return 2;
}
int main(){
    int i,j,k,n,M,an1=0,an2=0;
    cin>>n;
    scanf("%s%s",s1,s2);
    l1=strlen(s1);
    l2=strlen(s2);
    for(i=0;i<l1;i++)d1[i]=to(s1[i]);
    for(i=0;i<l2;i++)d2[i]=to(s2[i]);
    M=l1*l2;
    for(i=0;i<M&&i<n;i++){
        if(win[d1[i%l1]][d2[i%l2]]){
            an1+=n/M+(i<n%M);
        }
        else if(win[d2[i%l2]][d1[i%l1]]){
            an2+=n/M+(i<n%M);
        }
    }
    printf("%d %d\n",an1,an2);
    return 0;
}