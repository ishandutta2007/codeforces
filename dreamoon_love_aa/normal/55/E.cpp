#include<stdio.h>
#include<iostream>
using namespace std;
#define SIZE 100010
struct Point{
    long long x,y;
    Point operator-(Point b)const{return (Point){x-b.x,y-b.y};}
    long long operator*(Point b)const{return x*b.y-y*b.x;}
    void scan(){cin>>x>>y;}
}p[SIZE],now;
main(){
    int n,i,j,t;
    long long an,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++)p[i].scan();
    p[n]=p[0];
    scanf("%d",&t);
    while(t--){
        an=1ll*n*(n-1)*(n-2)/6;
        now.scan();
        for(i=0;i<n;i++)
            if((p[i+1]-p[i])*(now-p[i])>0)break;
        if(i<n)puts("0");
        else{
            for(i=0,j=1;i<n;i++){
                while((p[j]-p[i])*(now-p[i])<0){
                    j++;
                    if(j==n)j=0;
                }
                tmp=j-i;
                if(tmp<0)tmp+=n;
                an-=(tmp-1)*(tmp-2)/2;
            }
        cout<<an<<endl;
        }
    }
}