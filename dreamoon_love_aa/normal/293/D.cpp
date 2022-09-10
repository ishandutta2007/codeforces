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
#define MM 1000001
int x[MM<<1],y[MM<<1],cx[MM],cy[MM];
long long CNT;
long double TWO,ONE;
vector<long double>xx[2000001];
int get(long double v1,long double v2){
    return (int)(floor(v2+1e-9)-ceil(v1-1e-9))+1;
}
void go(int px[],int py[],int n){
    long double two=0,sum=0,sec=0;
    int i,j;
    long long cnt=0;
    if((long long)(px[0]-px[1])*(py[2]-py[1])-(long long)(px[2]-px[1])*(py[0]-py[1])>0){
        for(i=1;i<n-i;i++){
            swap(px[i],px[n-i]);
            swap(py[i],py[n-i]);
        }
    }
    //for(i=0;i<n;i++)printf("(%d,%d)\n",px[i],py[i]);
    for(i=0;i<=2000000;i++)xx[i].clear();
    for(i=0;i<n;i++){
        if(px[i]<px[i+1]){
            for(j=px[i];j<=px[i+1];j++){
                xx[j+MM].pb(py[i]+(py[i+1]-py[i])*1.*(j-px[i])/(px[i+1]-px[i]));
            }
        }
        else if(px[i]>px[i+1]){
            for(j=px[i+1];j<=px[i];j++){
                xx[j+MM].pb(py[i]+(py[i+1]-py[i])*1.*(j-px[i])/(px[i+1]-px[i]));
            }
        }
        else{
            xx[px[i]+MM].pb(py[i]);
            xx[px[i]+MM].pb(py[i+1]);
        }
    }
    for(i=0;i<=2000000;i++){
        if(xx[i].size()){
            long long ker=i-MM;
            sort(xx[i].begin(),xx[i].end());
            int now=get(xx[i][0],xx[i].back());
            //printf("%d:%d\n",i-MM,now);
            long long nt_cnt=cnt+now;
            long double nt_two=two+((long double)ker*ker*cnt-(long double)ker*sum*2+sec)*now;
            long double nt_sec=sec+(long double)ker*ker*now;
            long double nt_sum=sum+(long double)ker*now;
            cnt=nt_cnt;
            two=nt_two;
            sec=nt_sec;
            sum=nt_sum;
        }
    }
    CNT=cnt;
    TWO+=two;
}
int main(){
    int i,j,k,n,No,miX=100000000,miY;
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        cx[i]=x[i];
        cy[i]=y[i];
        x[n+i]=x[i];
        y[n+i]=y[i];
        if(x[i]<miX||(x[i]==miX&&y[i]<miY)){
            miX=x[i];
            miY=y[i];
            No=i;
        }
    }
    go(x+No,y+No,n);
    miX=100000000;
    for(i=0;i<n;i++){
        x[i]=cy[i];
        y[i]=cx[i];
        x[n+i]=x[i];
        y[n+i]=y[i];
        if(x[i]<miX||(x[i]==miX&&y[i]<miY)){
            miX=x[i];
            miY=y[i];
            No=i;
        }
    }
    go(x+No,y+No,n);
    printf("%.15lf\n",(double)(TWO*0.5/((long double)CNT*(CNT-1)/2)));
    return 0;
}