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
double sqr(double x){return x*x;}
bool in(double x,double y,int k){
    if(sqr(x+1)+sqr(y)>sqr(k)+1e-4)return 0;
    if(sqr(x-1)+sqr(y)>sqr(k)+1e-4)return 0;
    if(sqr(x+0.5)+sqr(y+sqrt(0.75))>sqr(k)+1e-4)return 0;
    if(sqr(x+0.5)+sqr(y-sqrt(0.75))>sqr(k)+1e-4)return 0;
    if(sqr(x-0.5)+sqr(y+sqrt(0.75))>sqr(k)+1e-4)return 0;
    if(sqr(x-0.5)+sqr(y-sqrt(0.75))>sqr(k)+1e-4)return 0;
    return 1;
}
int f(int x,int k){
    int left=0,right=1000000;
    while(left<right){
        int mid=(left+right+1)/2;
        if(x&1){
            if(in(1.5*x,(2*mid-1)*sqrt(0.75),k))left=mid;
            else right=mid-1;
        }
        else{
            if(in(1.5*x,(2*mid-2)*sqrt(0.75),k))left=mid;
            else right=mid-1;
        }
    }
    if(x&1)return left*2;
    else return max(left*2-1,0);
}
int main(){
    int i,j,k;
    long long an=0;
    double r=1.5;
    scanf("%d",&k);
    an+=f(0,k);
    for(i=1;i*1.5<=k+1e-12;i++)
        an+=f(i,k)*2;
    cout<<an<<endl;
    return 0;
}