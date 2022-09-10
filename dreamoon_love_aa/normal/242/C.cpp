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
#define SIZE 111111
int used[SIZE],bfs[SIZE],v[SIZE];
struct data{
    int x,y;
    bool operator<(const data& b)const{return x<b.x||(x==b.x&&y<b.y);}
};
vector<data>ha;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int find(data X){
    int it=lower_bound(ha.begin(),ha.end(),X)-ha.begin();
    if(it==ha.size())return -1;
    if(X.x!=ha[it].x||X.y!=ha[it].y)return -1;
    return it;
}
int main(){
    int i,j,k,n,x0,y0,x1,y1;
    scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int r,a,b;
        scanf("%d%d%d",&r,&a,&b);
        for(j=a;j<=b;j++)ha.pb((data){r,j});
    }
    sort(ha.begin(),ha.end());
    bfs[0]=find((data){x0,y0});
    used[bfs[0]]=1;
    for(i=0,j=1;i<j;i++){
        if(ha[bfs[i]].x==x1&&ha[bfs[i]].y==y1)break;
        //printf("(%d,%d)\n",ha[bfs[i]].x,ha[bfs[i]].y);
        for(k=0;k<8;k++){
            int nx=ha[bfs[i]].x+dx[k];
            int ny=ha[bfs[i]].y+dy[k];
            int next=find((data){nx,ny});
            if(next==-1)continue;
            if(used[next])continue;
            v[j]=v[i]+1;
            bfs[j++]=next;
            used[next]=1;
        }
    }
    if(i==j)puts("-1");
    else printf("%d\n",v[i]);
    return 0;
}