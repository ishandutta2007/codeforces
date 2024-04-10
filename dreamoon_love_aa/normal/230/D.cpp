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
using namespace std;
#define SIZE 100010
#define MAX 1010000000
struct EDGE{
    int y,v;
    EDGE(int _y=0,int _v=0){y=_y;v=_v;}
    bool operator<(const EDGE& b)const{return v<b.v||(v==b.v&&y<b.y);}
};
vector<EDGE>e[SIZE],delay[SIZE];
int tmp[SIZE],mi[SIZE];
bool used[SIZE];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        e[x].pb(EDGE(y,v));
        e[y].pb(EDGE(x,v));
    }
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++)
            scanf("%d",&tmp[j]);
        int jj;
        for(j=0;j<k;j+=jj){
            for(jj=1;j+jj<k&&tmp[j+jj]==tmp[j+jj-1]+1;jj++);
            delay[i].pb(EDGE(tmp[j],tmp[j+jj-1]));
        }
    }
    queue<int>qq;
    for(i=1;i<=n;i++)mi[i]=MAX;
    qq.push(1);
    mi[1]=0;
    while(qq.size()){
        int now=qq.front();qq.pop();
        used[now]=0;
        int of=lower_bound(delay[now].begin(),delay[now].end(),EDGE(-1,mi[now]))-delay[now].begin();
        int st;
        if(of==delay[now].size()){
            st=mi[now];
        }
        else{
            if(mi[now]>=delay[now][of].y&&mi[now]<=delay[now][of].v)st=delay[now][of].v+1;
            else st=mi[now];
        }
        for(i=0;i<e[now].size();i++){
            if(mi[e[now][i].y]>st+e[now][i].v){
                mi[e[now][i].y]=st+e[now][i].v;
                if(!used[e[now][i].y]){
                    used[e[now][i].y]=1;
                    qq.push(e[now][i].y);
                }
            }
        }
    }
    if(mi[n]==MAX)puts("-1");
    else printf("%d\n",mi[n]);
    return 0;
}