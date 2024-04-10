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
double pi=acos(-1);
int main(){
    int i,j,k,n,r,R,cnt;
    scanf("%d%d%d",&n,&R,&r);
    if(r>R)cnt=0;
    else if(r*2>R)cnt=1;
    else if(r*2==R)cnt=2;
    else{
        double tmp=asin(r*1./(R-r));
        if(tmp*n<=pi+1e-12)puts("YES");
        else puts("NO");
        return 0;
    }   
    if(cnt>=n)puts("YES");
    else puts("NO");
    return 0;
}