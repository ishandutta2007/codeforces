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
    int i,j,k,n,m;
    cin>>n>>m;
    printf("%d\n",min(n,m)+1);
    for(i=min(n,m);i>=0;i--)printf("%d %d\n",i,min(n,m)-i);
    return 0;
}