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
    int v,No;
    bool operator<(const data& b)const{return v>b.v||(v==b.v&&No<b.No);}
}d[1001];
int main(){
    int i,j,k,n,t1,t2,a1,a2;
    scanf("%d%d%d%d",&n,&t1,&t2,&k);
    k=100-k;
    for(i=0;i<n;i++){
        scanf("%d%d",&a1,&a2);
        d[i].No=i+1;
        d[i].v=a1*t1*k+a2*t2*100;
        if(d[i].v<a2*t1*k+a1*t2*100){
            d[i].v=a2*t1*k+a1*t2*100;
        }
    }
    sort(d,d+n);
    for(i=0;i<n;i++){
        printf("%d %d.%02d\n",d[i].No,d[i].v/100,d[i].v%100);
    }
    return 0;
}