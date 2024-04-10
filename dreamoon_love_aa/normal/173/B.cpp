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
#define SIZE 2024
int a[SIZE][SIZE],bfs[SIZE],v[SIZE],used[SIZE];
char s[SIZE][SIZE];
vector<int>e[SIZE];
int main(){
    int i,j,k;
    int n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i][j]=='#'){
                e[i].pb(j+n);
                e[j+n].pb(i);
            }
        }
    bfs[0]=n-1;
    used[n-1]=1;
    for(i=0,j=1;i<j;i++){
        if(bfs[i]==0)break;
        for(k=0;k<e[bfs[i]].size();k++){
            if(used[e[bfs[i]][k]]==0){
                used[e[bfs[i]][k]]=1;
                v[j]=v[i]+1;
                bfs[j++]=e[bfs[i]][k];
            }
        }
    }
    if(i<j)printf("%d\n",v[i]);
    else puts("-1");
    return 0;
}