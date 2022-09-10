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
    int n,x;
    scanf("%d",&n);
    int y=0,z=0;
    double an=0;
    while(scanf("%d",&x)==1){
        y+=x;
        z++;
        an=max(an,y*1./z);
    }
    printf("%.12f\n",an);
    return 0;
}