#include<stdio.h>
#include<queue>
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
#define SIZE 200010
struct EDGE{
    int x,y,v;
    EDGE(int _x=0,int _y=0,int _v=0){x=_x;y=_y;v=_v;}
}a[SIZE];
vector<EDGE*>e[SIZE];
bool used[SIZE];
int r[SIZE],an[SIZE];
struct data{
    int x,v;
    data(int _x=1,int _v=0){x=_x;v=_v;}
    bool operator<(const data& b)const{return v<b.v;}
};
priority_queue<data>H;
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
        e[a[i].x].pb(&a[i]);
        e[a[i].y].pb(&a[i]);
        r[a[i].x]+=a[i].v;
        r[a[i].y]+=a[i].v;
    }
    H.push(data(1,0));
    used[1]=1;
    while(!H.empty()){
        int x=H.top().x;
        int v=H.top().v;
        H.pop();
        for(i=0;i<e[x].size();i++){
            int y;
            if(e[x][i]->x==x){
                y=e[x][i]->y;
            }
            else{
                y=e[x][i]->x;
                if(!used[y])an[e[x][i]-a]=1;
            }
            if(!used[y]&&y!=n){
                r[y]-=2*e[x][i]->v;
                if(!r[y]){
                    used[y]=1;
                    H.push(data(y,0));
                }
            }
        }
    }
    for(i=0;i<m;i++)printf("%d\n",an[i]);
    return 0;
}