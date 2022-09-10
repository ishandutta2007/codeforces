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
#define SIZE 100010
int x[SIZE],y[SIZE];
double a[SIZE];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i];
        a[i]=atan2(y[i],x[i]);
    }
    sort(a,a+n);
    double ma=0;
    for(i=1;i<n;i++)ma=max(ma,a[i]-a[i-1]);
    ma=max(ma,a[0]+acos(-1)*2-a[n-1]);
    printf("%.12lf\n",360-ma*180/acos(-1));
    return 0;
}