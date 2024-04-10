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
    cin>>n>>k;
    for(i=1;i<n-k;i++)printf("%d ",i);
    for(i=n;i>=n-k;i--)printf("%d ",i);
    puts("");
    return 0;
}