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
#define SIZE 400010
struct data{
    int x,pos;
    data(int _x=0,int _pos=0){x=_x;pos=_pos;}
    bool operator<(const data& b)const{return x<b.x||(x==b.x&&pos<b.pos);}
}d[SIZE];
int a[SIZE],rr[SIZE];
int main(){
    int i,j,k,n;
    memset(rr,-1,sizeof(rr));
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        d[i]=data(a[i],i);
    }
    sort(d,d+n);
    for(i=0;i<n;i=j){
        for(j=i+1;j<n&&d[j].x==d[i].x;j++);
        for(;i+k<=j;i++){rr[d[i].pos]=d[i+k-1].pos;}
    }
    k=SIZE;
    long long an=0;
    for(i=n-1;i>=0;i--){
        if(rr[i]!=-1)k=min(k,rr[i]);
        if(k!=SIZE)an+=n-k;
    }
    cout<<an<<endl;
    return 0;
}