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
#define SIZE 1000
int x[SIZE],y[SIZE],r[SIZE],n;
inline int sqr(int x){return x*x;}
bool check(int xx,int yy){
    int i;
    for(i=0;i<n;i++){
        if(sqr(x[i]-xx)+sqr(y[i]-yy)<=sqr(r[i]))return 1;
    }
    return 0;
}
int main(){
    int i,j,k,x1,x2,y1,y2,an=0;
    cin>>x1>>y1>>x2>>y2;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    cin>>n;
    for(i=0;i<n;i++)cin>>x[i]>>y[i]>>r[i];
    for(i=x1;i<=x2;i++){
        if(!check(i,y1))an++;
        if(!check(i,y2))an++;
    }
    for(i=y1+1;i<y2;i++){
        if(!check(x1,i))an++;
        if(!check(x2,i))an++;
    }
    cout<<an<<endl;
    return 0;
}