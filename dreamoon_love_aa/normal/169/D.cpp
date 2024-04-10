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
    int m,v,No;
    bool operator<(const data& b)const{return m<b.m||(m==b.m&&v<b.v);}
}a[SIZE];
int sel[SIZE],sn,an[SIZE];
int k,n,h;
bool valid(double t){
    int i;
    sn=1;
    for(i=0;i<n&&sn<=k;i++){
        if(h*1.*sn/a[i].v<=t){
            sel[sn++]=a[i].No;
        }
    }
    if(sn>k){
        for(i=1;i<=k;i++)an[i]=sel[i];
        return 1;
    }
    return 0;
}
int main(){
    int i;
    scanf("%d%d%d",&n,&k,&h);
    for(i=0;i<n;i++)a[i].No=i+1;
    for(i=0;i<n;i++)scanf("%d",&a[i].m);
    for(i=0;i<n;i++)scanf("%d",&a[i].v);
    sort(a,a+n);
    double ll=0,rr=1e21;
    for(i=0;i<200;i++){
        double mm=(ll+rr)*0.5;
        if(valid(mm))rr=mm;
        else ll=mm;
    }
    for(i=1;i<=k;i++){
        if(i!=1)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}