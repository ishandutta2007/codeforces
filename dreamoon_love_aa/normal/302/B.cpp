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
int c[100000],t[100000],st[100000];
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<n;i++)scanf("%d%d",&c[i],&t[i]);
    for(i=1;i<n;i++)st[i]=st[i-1]+c[i-1]*t[i-1];
    while(m--){
        int x;
        scanf("%d",&x);
        int idx=lower_bound(st,st+n,x)-st;
        printf("%d\n",idx);
    }
    return 0;
}