#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 100002
vector<long long>edge[SIZE];
long long bfs[SIZE],used[SIZE],a[SIZE],father[SIZE];
long long v[SIZE];
main(){
    long long n,m,i,j,k,x,y;
    memset(used,-1,sizeof(used));
    cin>>n;
    m=n-1;
    for(i=1;i<=n;i++)cin>>a[i];
    while(m--){
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    cin>>bfs[0];
    used[bfs[0]]=0;
    for(i=0,j=1;i<j;i++){
        long long size=edge[bfs[i]].size();
        x=bfs[i];
        for(k=0;k<size;k++){
            y=edge[x][k];
            if(used[y]==-1){
                father[y]=x;
                used[y]=j;
                bfs[j++]=y;
            }
        }
    }
    for(i=n-1;i>=0;i--){
        x=bfs[i];
        if(edge[x].size()==1&&i)continue;
        if(a[x]==1&&i)continue;
        long long size=edge[x].size(),tmp=0;
        priority_queue<long long>Heap;
        while(!Heap.empty())Heap.pop();
        for(j=0;j<size;j++){
            y=edge[x][j];
            if(father[x]==y)continue;
            if(v[y])Heap.push(v[y]);
            tmp+=a[y];
        }
        
        while(a[x]>(i?1:0)&&!Heap.empty()){
            a[x]--;
            v[x]+=Heap.top()+1;
            Heap.pop();
        }
        if(i){
            a[x]--;
            v[x]++;
        }
        v[x]+=min(a[x],tmp)*2;
        a[x]=max(a[x]-tmp,0ll);
    }
    cout<<v[bfs[0]]<<endl;
}