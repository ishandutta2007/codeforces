#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
double a[100005],l;
int n;
double eps=1e-7;
int check(double t){
    double v1=1,v2=1,d1=0,d2=0;
    int x=0,y=n+1;
    double tt=t;
    while(t>(a[x+1]-a[x])/v1&&x<=n){
        t-=(a[x+1]-a[x])/v1;
        v1+=1;
        x++;
    }
    if(t>(a[x+1]-a[x])/v1) d1=l;
    else d1=a[x],d1+=t*v1;
    while(tt>(a[y]-a[y-1])/v2&&y){
        tt-=(a[y]-a[y-1])/v2;
        v2+=1;
        y--;
    }
    if(tt>(a[y]-a[y-1])/v2) d2=l;
    else d2=l-a[y],d2+=tt*v2;
    if(d1+d2>=l) return 1;
    else return 0;
}
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int t=0;
        scanf("%d%lf",&n,&l);
        a[n+1]=l;
        for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
        double x=0,y=l;
        while(y-x>eps){
            double mid=(x+y)/2;
            if(check(mid)) y=mid;
            else x=mid;
        }
        printf("%lf\n",(x+y)/2);
    }
    return 0;
}