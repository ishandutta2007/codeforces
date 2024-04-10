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
#define SIZE 333
int a[SIZE],res,n;
vector<int>e[SIZE],ae[SIZE];
int bfs[1000000];
void dfs(int i,int& r,int now,int need[],int get[]){
    get[i]=1;
    r--;
    for(int j=0;j<ae[i].size();j++){
        need[ae[i][j]]--;
        if(need[ae[i][j]]==0&&a[ae[i][j]]==now)
            dfs(ae[i][j],r,now,need,get);
    }
}
void go(int now){
    int r=n,i,j;
    int get[SIZE]={};
    int need[SIZE];
    for(i=1;i<=n;i++)need[i]=e[i].size();
    int yo=0;
    while(r){
        for(i=1;i<=n;i++){
            if(a[i]==now&&need[i]==0&&get[i]==0){
                dfs(i,r,now,need,get);
            }
        }
        now=now%3+1;
        if(r)yo++;
    }
    res=min(res,yo);
}
int main(){
    res=1000000000;
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(j=1;j<=n;j++){
        int m;
        scanf("%d",&m);
        for(k=0;k<m;k++){
            int x;
            scanf("%d",&x);
            e[j].pb(x);
            ae[x].pb(j);
        }
    }
    for(i=1;i<=3;i++)go(i);
    printf("%d\n",res+n);
    return 0;
}