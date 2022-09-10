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
#define SIZE 600060
int x[150001],p[150000];
double save[150001],ll[SIZE],rr[SIZE],all[SIZE],mm[SIZE];
// 0 left 1 right 2 all
void init(int id,int L,int R){
    if(L==R){
        ll[id]=max(0.,save[L]);
        rr[id]=max(0.,save[L]);
        all[id]=save[L];
        mm[id]=max(0.,save[L]);
        return;
    }
    int M=(L+R)/2;
    init(id*2,L,M);
    init(id*2+1,M+1,R);
    ll[id]=max(ll[id*2],all[id*2]+ll[id*2+1]);
    rr[id]=max(rr[id*2+1],all[id*2+1]+rr[id*2]);
    all[id]=all[id*2+1]+all[id*2];
    mm[id]=max(max(mm[id*2],mm[id*2+1]),rr[id*2]+ll[id*2+1]);
}
double qq(int id,int L,int R,int l,int r,double d[]){
    if(l<=L&&r>=R){
        d[1]=rr[id];
        d[0]=ll[id];
        d[2]=all[id];
        return max(0.,mm[id]);
    }
    int M=(L+R)/2;
    if(r<=M)return qq(id*2,L,M,l,r,d);
    if(l>M)return qq(id*2+1,M+1,R,l,r,d);
    double d1[3],d2[3],res=0;
    res=max(res,qq(id*2,L,M,l,r,d1));
    //printf("<%lf>\n",res);
    res=max(res,qq(id*2+1,M+1,R,l,r,d2));
    //printf("<%lf>\n",res);
    res=max(res,d1[1]+d2[0]);
    d[0]=max(d1[0],d1[2]+d2[0]);
    d[1]=max(d2[1],d2[2]+d1[1]);
    d[2]=d1[2]+d2[2];
    return res;
}
int main(){
    int i,j,k,n,m,c,LL,RR;
    double an=0;
    scanf("%d%d%d",&n,&m,&c);
    LL=1,RR=n-1;
    for(i=1;i<=n;i++)scanf("%d",&x[i]);
    for(i=1;i<n;i++)scanf("%d",&p[i]);
    for(i=1;i<n;i++)
        save[i]=(x[i+1]-x[i])*0.5-p[i]*0.01*c;
    init(1,1,n-1);
    for(i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        double d[3];
        an+=qq(1,1,n-1,x,y-1,d);
        //printf("[%lf]\n",an);
    }
    printf("%.8lf\n",an);
    return 0;
}