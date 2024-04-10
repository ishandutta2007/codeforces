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
    int i,j,k,n,m,x1,y1,x2,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    if(abs(x1-x2)>=5||abs(y1-y2)>=5)puts("Second");
    else if(abs(x1-x2)==0||abs(y1-y2)==0)puts("First");
    else if(abs(x1-x2)>=3&&abs(y1-y2)>=4)puts("Second");
    else if(abs(x1-x2)>=4&&abs(y1-y2)>=3)puts("Second");
    else if(abs(x1-x2)<=4&&abs(y1-y2)<=4)puts("First");
    else puts("Second");
    return 0;
}