#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#define SIZE 100010
using namespace std;
int le[SIZE],ri[SIZE],lm[SIZE],rm[SIZE],value[SIZE],sp;
double an[SIZE];
void Init(int x,int &mi,int &ma){
    if(le[x]==-1){
        mi=ma=value[x];
        return;
    }
    int mi2,ma2;
    Init(le[x],mi,ma);
    lm[x]=ma;
    Init(ri[x],mi2,ma2);
    rm[x]=mi2;
    ma=ma2;
}
void dfs(int x,double v,int cnt){
    if(le[x]==-1){
        an[sp++]=v/cnt;
        return;
    }
    dfs(le[x],v+rm[x],cnt+1);
    dfs(ri[x],v+lm[x],cnt+1);
}
main(){
    int n,m,root,i,x,y;
    cin>>n;
    memset(le,-1,sizeof(le));
    memset(ri,-1,sizeof(ri));
    for(i=1;i<=n;i++)
        cin>>lm[i]>>value[i];
    for(i=1;i<=n;i++){
        if(lm[i]!=-1){
            if(value[i]>value[lm[i]])ri[lm[i]]=i;
            else le[lm[i]]=i;
        }
        else root=i;
    }
    Init(root,x,y);
    dfs(root,0,0);
    sp=0;
    for(i=1;i<=n;i++){
        if(le[i]!=-1){
            value[sp++]=value[i];
        }
    }
    sort(value,value+sp);
    cin>>m;
    int Left,Right,Mid;
    while(m--){
        cin>>x;
        Left=0;
        Right=sp;
        while(Left<Right){
            Mid=(Left+Right)/2;
            if(value[Mid]>x)Right=Mid;
            else Left=Mid+1;
        }
        printf("%.10lf\n",an[Left]);
    }
}