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
int main(){
    long long t1,t2,x1,x2,t0,i,y1=0,y2=0;
    double mi=1e15;
    cin>>t1>>t2>>x1>>x2>>t0;
    if(t2==t1){
        cout<<x1<<" "<<x2<<endl;
        return 0;
    }
    if(t0==t2){
        cout<<0<<" "<<x2<<endl;
        return 0;
    }
    if(t0==t1){
        cout<<x1<<" "<<0<<endl;
        return 0;
    }
    for(i=0;i<=x1;i++){
        long long yy1=i;
        long long yy2=(i*(t0-t1)+t2-t0-1)/(t2-t0);
        if(yy1==0)yy2=x2;
        if(yy2>x2)continue;
        double tmp=(yy1*t1+yy2*t2-(yy1+yy2)*t0)*1./(yy1+yy2);
        if(tmp<-1e-9)continue;
        if(tmp+1e-9<mi||(fabs(tmp-mi)<1e-9&&yy1+yy2>y1+y2)){
            mi=tmp;
            y1=yy1;
            y2=yy2;
        }
    }
    cout<<y1<<" "<<y2<<endl;
    return 0;
}