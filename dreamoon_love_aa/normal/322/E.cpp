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
#define SIZE 100010
vector<int>e[SIZE];
int bfs[SIZE],last[SIZE],used[SIZE],tt,v[SIZE],stop[SIZE],an[SIZE];
int go(int x){
    int i,j,k;
    bfs[0]=x;
    tt++;
    used[x]=tt;
    v[x]=0;
    last[x]=-1;
    for(i=0,j=1;i<j;i++){
        x=bfs[i];
        for(k=0;k<e[x].size();k++){
            int y=e[x][k];
            if(used[y]==tt||stop[y])continue;
            bfs[j++]=y;
            last[y]=x;
            used[y]=tt;
            v[y]=v[x]+1;
        }
    }
    return i;
}
int find_mid(int x){
    int n=go(x),i;
    int st=bfs[n-1];
    go(st);
    int k=bfs[n-1];
    for(i=0;i<v[bfs[n-1]]/2;i++){
        if(last[k]!=-1)k=last[k];
    }
    return k;
}
void fill(int x,int u){
    int i;
    an[x]=u;
    stop[x]=1;
    for(i=0;i<e[x].size();i++){
        int y=e[x][i];
        if(stop[y])continue;
        int mid=find_mid(y);
        fill(mid,u+1);
    }
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    int mid=find_mid(1);
    stop[mid]=1;
    fill(mid,0);
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        printf("%c",an[i]+'A');
    }
    puts("");
    return 0;
}