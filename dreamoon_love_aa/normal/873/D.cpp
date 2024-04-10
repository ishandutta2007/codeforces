/*
k:
n  k
----
2  3
3  5
4  7
5  9
6  11
7  13
8  15
x  2x-1
*/
#include <bits/stdc++.h>
using namespace std;

int n,k,a[120000];

void f(int l,int r,int x){
    if(l+1>=r){
        a[l]=x;
        return;}
    if(k==0){
        int tmp=x;
        for(int i=l;i<r;i++)a[i]=tmp++;
        return;}//
    k-=2;
    int mid=(l+r)/2;
    f(l,mid,x+(r-mid));
    f(mid,r,x);
return;}

int main(){
    scanf("%d %d",&n,&k);
    if(k<1||k%2==0||k>=2*n){
        puts("-1");
        return 0;}
    k--;
    f(0,n,1);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    puts("");
return 0;}

// inline int ms(int l,int r){//
//     bool y=true;
//     for(int i=l+1;i<r&&y;i++)if(a[i]<a[i-1])y=false;
//     // for(int i=0;i<n;i++)scanf("%d ",a)
//     printf("%d %d %d\n",l,r,y);
//     if(y||(l+1>=r))return 1;

//     int mid=(l+r)>>1;
//     int ans=ms(l,mid)+ms(mid,r)+1;
//     sort(a+l,a+r);
//     return ans;}//merge sort