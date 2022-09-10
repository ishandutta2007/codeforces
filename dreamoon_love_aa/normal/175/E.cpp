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
int nf,ne,ns,n,who[22],df,de;
double rf,re,rs,r[22],damage[22];
double an;
double sqr(double v){return v*v;}
double inter(double x1,double y1,double x2,double y2){
    if(y1<=x2)return 0;
    if(y2<=x1)return 0;
    return min(y1,y2)-max(x1,x2);
}
int g(bool x){if(x)return 1;return 0;}
double ss(int x){
    double res=0;
    if(who[x]<=1)res+=damage[x]*r[x]*2;
    for(int i=0;i<x;i++){
        if(g(who[x]<=1)^g(who[i]<=1))res+=(damage[x]+damage[i])*inter((x>>1)-r[x],(x>>1)+r[x],(i>>1)-r[i],(i>>1)+r[i]);
    }
    return res;
}
void dfs(int x,int num_f,int num_e,int num_s,double v){
    if(x==n){
        an=max(an,v);
        return;
    }
    if(num_f<nf&&(!(x&1)||who[x-1]<=0)){
        who[x]=0;
        damage[x]=df;
        r[x]=rf;
        dfs(x+1,num_f+1,num_e,num_s,v+ss(x));
    }
    if(num_e<ne&&(!(x&1)||who[x-1]<=1)){
        who[x]=1;
        damage[x]=de;
        r[x]=re;
        dfs(x+1,num_f,num_e+1,num_s,v+ss(x));
    }
    if(num_s<ns){
        who[x]=2;
        damage[x]=0;
        r[x]=rs;
        dfs(x+1,num_f,num_e,num_s+1,v+ss(x));
    }
}
int main(){
    an=0;
    int i,j,k;
    cin>>nf>>ne>>ns;
    n=nf+ne+ns;
    cin>>rf>>re>>rs;
    rf=sqrt(sqr(rf)-1);
    re=sqrt(sqr(re)-1);
    rs=sqrt(sqr(rs)-1);
    cin>>df>>de;
    dfs(0,0,0,0,0.);
    printf("%.9lf\n",an);
    return 0;
}