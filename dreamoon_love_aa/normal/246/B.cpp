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
    int i,j,k=0,n,x;
    cin>>n;
    for(i=0;i<n;i++){scanf("%d",&x);k+=x;}
    if(k%n==0)printf("%d\n",n);
    else printf("%d\n",n-1);
    return 0;
}