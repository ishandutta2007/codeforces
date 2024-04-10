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
#define SIZE 500000
struct data{
    int pos,type;
    int p;
    data(int _pos=0,int _type=0,int _p=0):pos(_pos),type(_type),p(_p){}
    bool operator<(const data& b)const{
        if(pos==b.pos)return type<b.type;
        return pos<b.pos;
    }
}a[SIZE];
int u,cnt[111];
double mypow(double x,int y){
    double an=1;
    while(y){
        if(y&1){
            an*=x;
        }
        x*=x;
        y>>=1;
    }
    return an;
}
int main(){
    int i,j,n,m,x,h,l,r,b,z;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&x,&h,&l,&r);
        l=100-l;
        r=100-r;
        a[u++]=data(x-h,0,l);
        a[u++]=data(x,0,300+l);
        a[u++]=data(x+1,0,r);
        a[u++]=data(x+h+1,0,300+r);
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&b,&z);
        a[u++]=data(b,z);
    }
    sort(a,a+u);
    double an=0;
    for(i=0;i<u;i++){
        if(a[i].type==0){
            if(a[i].p<=100)cnt[a[i].p]++;
            else cnt[a[i].p-300]--;
        }
        else{
            double now=1;
            for(j=0;j<=100;j++)
                if(cnt[j])now*=mypow(j*0.01,cnt[j]);
            an+=a[i].type*now;
        }
    }
    printf("%.12lf\n",an);
    return 0;
}