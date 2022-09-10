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
int x1[SIZE],yy1[SIZE],z1[SIZE],x2[SIZE],y2[SIZE],z2[SIZE],n,m;
int go(int x,int y){
    int res=1000000000;
    for(int i=0;i<m;i++){
        if(x2[i]>=y)res=min(res,((x-1)/(x2[i]/y*y2[i])+1)*z2[i]);
    }
    return res;
}
int main(){
    int i,j,k,an=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>x1[i]>>yy1[i]>>z1[i];
    cin>>m;
    for(i=0;i<m;i++)cin>>x2[i]>>y2[i]>>z2[i];
    for(i=0;i<n;i++){
        an+=go((x1[i]+yy1[i])*2,z1[i]);
    }
    cout<<an<<endl;
    return 0;
}