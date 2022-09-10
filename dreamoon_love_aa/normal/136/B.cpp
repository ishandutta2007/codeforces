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
int aa[30],bb[30];
int main(){
    int i,j,k,n,a,b;
    scanf("%d%d",&a,&b);
    for(i=0;i<30;i++){
        aa[i]=a%3;
        a/=3;
    }
    for(i=0;i<30;i++){
        bb[i]=b%3;
        b/=3;
    }
    for(i=29,k=0;i>=0;i--){
        k*=3;
        k+=(bb[i]-aa[i]+3)%3;
    }
    printf("%d\n",k);
    return 0;
}