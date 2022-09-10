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
long long a[SIZE*2];
struct data{
    long double x;
    int flag;
    bool operator<(const data& ha)const{
        return x<ha.x;
    }
}b[SIZE*4];
int bn;
long double an[SIZE];
int main(){
    int i,j,k,n,l,v1,v2;
    scanf("%d%d%d%d",&n,&l,&v1,&v2);
    long double rl=(long double)l*v2/(v1+v2);
    for(i=0;i<n;i++){
        scanf("%I64d",&a[i]);
        a[n+i]=a[i]+2*l;
    }
    for(i=0;i<2*n;i++){
        b[bn++]=(data){a[i],1};
        b[bn++]=(data){a[i]+rl,-1};
    }
    b[bn++]=(data){l,0};
    b[bn++]=(data){3.*l,0};
    sort(b,b+bn);
    int now=0;
    for(i=0;i<bn;i++){
        if(i&&b[i-1].x+1e-10>l&&b[i].x<3.*l+1e-8){
            an[now]+=(b[i].x-b[i-1].x);
        }
        now+=b[i].flag;
    }
    for(i=0;i<=n;i++)printf("%.12lf\n",(double)(an[i]/(2*l)));
    return 0;
}