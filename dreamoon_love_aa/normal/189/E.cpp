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
#include<queue>
#define pb push_back
#define SIZE 200001
using namespace std;
int n,s,t,used[SIZE],cs,ma,mi[SIZE];
struct data{
    int x,v;
    data(int _x=0,int _v=0){x=_x,v=_v;}
    bool operator<(const data& b)const{return v>b.v||(v==b.v&&x<b.x);}
};
bool sp[SIZE];
vector<int>e[SIZE];
bool con(int x,int y){
    if(x==y)return 1;
    if(used[x]==cs)return 0;
    used[x]=1;
    for(int i=0;i<e[x].size();i++)
        if(con(e[x][i],y))return 1;
    return 0;
}
int main(){
    int i,j,k,m;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;i++){
        int x;
        scanf("%d",&x);
        sp[x]=1;
    }
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    scanf("%d%d",&s,&t);
    cs++;
    if(!con(s,t)){
        puts("-1");
        return 0;
    }
    for(i=1;i<=n;i++)mi[i]=1000000000;
    priority_queue<data>heap;
    mi[s]=0;
    heap.push(data(s,0));
    while(1){
        data now=heap.top();heap.pop();
        int x=now.x;
        int v=now.v;
        for(i=0;i<(int)e[x].size();i++){
            int y=e[x][i];
            if(v+1<mi[y]){
                ma=max(ma,v+1);
                if(y==t)break;
                if(sp[y]){
                    mi[y]=0;
                    heap.push(data(y,0));
                }
                else{
                    mi[y]=v+1;
                    heap.push(data(y,v+1));
                }
            }
        }
        if(i<e[x].size())break;
    }
    printf("%d\n",ma);
    return 0;
}