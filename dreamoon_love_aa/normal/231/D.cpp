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
int a[7];
int main(){
    int i,j,k,n,x,y,z,x1,y1,z1,an=0;
    cin>>x>>y>>z;
    cin>>x1>>y1>>z1;
    for(i=1;i<=6;i++)cin>>a[i];
    if(y<0)an+=a[1];
    if(y>y1)an+=a[2];
    if(z<0)an+=a[3];
    if(z>z1)an+=a[4];
    if(x<0)an+=a[5];
    if(x>x1)an+=a[6];
    cout<<an<<endl;
    return 0;
}