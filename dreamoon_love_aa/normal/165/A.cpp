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
struct Point
{
    int x,y;
}a[222];
int main(){
    int i,j,k,n,an=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i].x>>a[i].y;
    for(i=0;i<n;i++){
        int flag=0;
        for(j=0;j<n;j++){
            if(i==j)continue;
            if(a[i].x==a[j].x&&a[i].y<a[j].y)flag|=1;
            if(a[i].x==a[j].x&&a[i].y>a[j].y)flag|=2;
            if(a[i].y==a[j].y&&a[i].x<a[j].x)flag|=4;
            if(a[i].y==a[j].y&&a[i].x>a[j].x)flag|=8;
        }
        if(flag==15)an++;
    }
    cout<<an<<endl;
    return 0;
}