#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 122
vector<int>e[SIZE];
int Go(int x,int &start){
    int bfs[SIZE],i,j,k,used[SIZE],v[SIZE];
    memset(used,0,sizeof(used));
    bfs[0]=x;
    v[x]=0;
    used[x]=1;
    for(i=0,j=1;i<j;i++){
        x=bfs[i];
        for(k=0;k<e[x].size();k++){
            int y=e[x][k];
            if(used[y]==0){
                used[y]=1;
                v[y]=v[x]+1;
                bfs[j++]=y;
            }
        }
    }
    start=bfs[i-1];
    return v[start];
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n,an=0;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        for(i=1;i<=m;i++)e[i].clear();
        for(i=1;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            e[x].pb(y);
            e[y].pb(x);
        }
        int start;
        Go(1,start);
        an+=Go(start,start);
    }
    cout<<an<<endl;
    return 0;
}