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
#define SIZE 100010
struct data{
    int v,No;
    bool operator<(const data& b)const{return v<b.v;}
}a[SIZE];
int an[SIZE];
int main(){
    int i,j,k,n,h,dif;
    cin>>n>>h;
    for(i=0;i<n;i++){cin>>a[i].v;a[i].No=i;}
    if(n==2){
        printf("0\n1 1\n");
        return 0;
    }
    sort(a,a+n);
    dif=a[n-1].v+a[n-2].v-a[0].v-a[1].v;
    if(dif<=max(a[0].v+a[n-1].v+h,a[n-1].v+a[n-2].v)-min(a[0].v+a[1].v+h,a[1].v+a[2].v)){
        for(i=0;i<n;i++)an[a[i].No]=1;
    }
    else{
        dif=max(a[0].v+a[n-1].v+h,a[n-1].v+a[n-2].v)-min(a[0].v+a[1].v+h,a[1].v+a[2].v);
        for(i=0;i<n;i++)an[a[i].No]=1;
        an[a[0].No]=2;
    }
    printf("%d\n",dif);
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}