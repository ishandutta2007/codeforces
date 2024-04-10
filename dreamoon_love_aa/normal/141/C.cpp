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
struct data{
    char s[16];
    int h;
    bool operator<(const data& b)const{return h<b.h;}
}a[3000];
int an[3000];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%d",a[i].s,&a[i].h);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(a[i].h>i){
            puts("-1");
            return 0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++)
            if(an[j]>a[i].h)an[j]++;
        an[i]=a[i].h+1;
    }
    for(i=0;i<n;i++)printf("%s %d\n",a[i].s,n+1-an[i]);
    return 0;
}