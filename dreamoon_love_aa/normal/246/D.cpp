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
#define SIZE 100001
int c[SIZE],v[SIZE],ma,an;
vector<int>e[SIZE];
int main(){
    int i,j,k,n,m;
    ma=-1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){scanf("%d",&c[i]);v[c[i]]=1;}
    for(i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(c[x]!=c[y]){
            e[c[x]].pb(c[y]);
            e[c[y]].pb(c[x]);
        }
    }
    for(i=1;i<=100000;i++){
        if(!v[i])continue;
        sort(e[i].begin(),e[i].end());
        e[i].resize(unique(e[i].begin(),e[i].end())-e[i].begin());
        if((int)e[i].size()>ma){
            ma=e[i].size();
            an=i;
        }
    }
    printf("%d\n",an);
    return 0;
}