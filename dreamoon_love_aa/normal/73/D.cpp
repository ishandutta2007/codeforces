#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 1000001
vector<int>e[SIZE],d;
bool used[SIZE];
int go(int x){
    static int bfs[SIZE];
    int i,j,k,an=1;
    used[x]=1;
    bfs[0]=x;
    for(i=0,j=1;i<j;i++){
        x=bfs[i];
        for(k=0;k<e[x].size();k++){
            if(!used[e[x][k]]){
                bfs[j++]=e[x][k];
                an++;
                used[e[x][k]]=1;
            }
        }
    }
    return an;
}
main(){
    int n,m,k,i,x,y,degree;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(i=1;i<=n;i++)
        if(!used[i])d.push_back(go(i));
    for(i=0;i<d.size();i++)d[i]=min(d[i],k);
    x=degree=0;
    for(i=0;i<d.size();i++){
        x++;
        degree+=d[i];
    }
    if(degree>=(x-1)*2)puts("0");
    else if(k==1)printf("%d\n",x-2);
    else printf("%d\n",(((x-1)*2-degree+1)/2));
}