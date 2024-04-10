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
    int i,j,k,n;
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double h=1-(b-a)/b*(d-c)/d;
    printf("%.12lf\n",a/b/h);
    return 0;
}