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
int main(){
    int i,j,k;
    long long n,x,y,c;
    cin>>n>>x>>y>>c;
    if(c==1){
        puts("0");
        return 0;
    }
    int ll=1,rr=1000000;
    while(ll<rr){
        long long mm=(ll+rr)>>1;
        long long v=mm*mm+(mm+1)*(mm+1);
        if(x<=mm)v-=(mm-x+1)*(mm-x+1);
        if(y<=mm)v-=(mm-y+1)*(mm-y+1);
        if(x+mm>n)v-=(mm+x-n)*(mm+x-n);
        if(y+mm>n)v-=(mm+y-n)*(mm+y-n);

        if(x+y+mm>n+n+1)v+=(x+y+mm-(n+n+1))*(x+y+mm-(n+n+1)+1)/2;
        int xx=x,yy=n+1-y;
        if(xx+yy+mm>n+n+1)v+=(xx+yy+mm-(n+n+1))*(xx+yy+mm-(n+n+1)+1)/2;
        xx=n+1-x,yy=y;
        if(xx+yy+mm>n+n+1)v+=(xx+yy+mm-(n+n+1))*(xx+yy+mm-(n+n+1)+1)/2;
        xx=n+1-x,yy=n+1-y;
        if(xx+yy+mm>n+n+1)v+=(xx+yy+mm-(n+n+1))*(xx+yy+mm-(n+n+1)+1)/2;

        if(v<c)ll=mm+1;
        else rr=mm;
    }
    cout<<ll<<endl;
    return 0;
}