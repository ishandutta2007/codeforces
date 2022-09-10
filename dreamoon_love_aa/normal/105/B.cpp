#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int b[8],A,n;
double an,tmp;
void dfs2(int x,int l[],double p,int v,int people){
    if(x==n){
        if(people*2>n)tmp+=p;
        else tmp+=p*A/(A+v);
        return;
    }
    dfs2(x+1,l,p*l[x]/100,v,people+1);
    dfs2(x+1,l,p*(100-l[x])/100,v+b[x],people);
}
void dfs(int x,int r,int l[]){
    if(x==n-1){
        int add=min(r,(100-l[x])/10);
        l[x]+=add*10;
        tmp=0;
        dfs2(0,l,1,0,0);
        an=max(an,tmp);
        l[x]-=add*10;
        return;
    }
    int i;
    for(i=0;i<=r&&l[x]+10*i<=100;i++){
        l[x]+=i*10;
        dfs(x+1,r-i,l);
        l[x]-=i*10;
    }
}
main(){
    int k,i,l[8];
    cin>>n>>k>>A;
    for(i=0;i<n;i++)cin>>b[i]>>l[i];
    dfs(0,k,l);
    printf("%.10lf\n",an);
}