#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 100000
int a[SIZE];
bool p[10000000];
int main(){
    int i,j,k,x,now,an=0,n;
    scanf("%d%d",&n,&x);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    if(x==2){
        puts("0");
        return 0;
    }
    sort(a,a+n);
    if(a[0]==1){
        puts("1");
        return 0;
    }
    for(i=2;i<10000000&&i<x;i++){
        if(!p[i]){
            int *r=lower_bound(a,a+n,i);
            if(r==NULL)break;
            else if(*r!=i)break;
            else an++;
            for(j=i+i;j<10000000;j+=i)p[j]=1;
        }
    }
    if(i==x)printf("%d\n",an);
    else puts("-1");
    return 0;
}