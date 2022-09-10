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
#define SIZE 200000
int f[SIZE],n,m,get1[SIZE],get2[SIZE],bfs[SIZE],used[SIZE],cs;
vector<int>e[SIZE],ae[SIZE];
int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&f[i]);
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        e[x].pb(y);
        ae[y].pb(x);
    }
    cs++;
    for(i=j=0;i<n;i++)
        if(f[i]==1){
            used[i]=cs;
            get1[i]=1;
            bfs[j++]=i;
        }
    for(i=0;i<j;i++){
        int x=bfs[i];
        for(k=0;k<e[x].size();k++){
            int y=e[x][k];
            get1[y]=1;
            if(used[y]!=cs){
                used[y]=cs;
                bfs[j++]=y;
            }
        }
    }
    cs++;
    for(i=j=0;i<n;i++)
        if(f[i]==2){
            used[i]=cs;
            get2[i]=1;
            bfs[j++]=i;
        }
    for(i=0;i<j;i++){
        int x=bfs[i];
        for(k=0;k<ae[x].size();k++){
            int y=ae[x][k];
            get2[y]=1;
            if(used[y]!=cs){
                used[y]=cs;
                if(f[y]!=1)bfs[j++]=y;
            }
        }
    }
    for(i=0;i<n;i++){
        if(get1[i]&&get2[i])printf("%d\n",1);
        else printf("%d\n",0);
    }
    return 0;
}