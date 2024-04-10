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
int main(){
    long long x1,x2,y1,y2,a,b;
    cin>>a>>b>>x1>>y1>>x2>>y2;
    a<<=1;
    b<<=1;
    long long xx1=x1+y1,yy1=x1-y1;
    long long xx2=x2+y2,yy2=x2-y2;
    xx1-=(xx1%a+a)%a;
    xx2-=(xx2%a+a)%a;
    yy1-=(yy1%b+b)%b;
    yy2-=(yy2%b+b)%b;
    cout<<max(abs(xx1-xx2)/a,abs(yy1-yy2)/b)<<endl;
    return 0;
}