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
set<long long>H;
int n;
void dfs(long long x,int a,int b){
    if(x&&x<=n){
        H.insert(x);
    }
    if(x>n)return;
    if(x*10+a>x)dfs(x*10+a,a,b);
    dfs(x*10+b,a,b);
}
int main(){
    int i,j,k;
    cin>>n;
    for(i=0;i<10;i++)
        for(j=i+1;j<10;j++)dfs(0,i,j);
    printf("%d\n",H.size());
    return 0;
}