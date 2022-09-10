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
struct data{
    int x,y;
    bool operator<(const data& b)const{
        return x*y*(100-b.y)>b.x*b.y*(100-y);
    }
}a[50010];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i].x>>a[i].y;
    sort(a,a+n);
    long long now=0,an=0;
    for(i=0;i<n;i++){
        an+=a[i].x*10000;
        an+=now*(100-a[i].y);
        now+=a[i].x*a[i].y;
    }
    printf("%I64d.%04I64d",an/10000,an%10000);
    return 0;
}