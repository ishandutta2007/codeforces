#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int an[1000][1000];
long long sqr(long long x){return x*x;}
struct Fence{
    int x,y,r;
    void scan(){scanf("%d%d%d",&r,&x,&y);}
    bool operator<(Fence b)const{return r<b.r||(r==b.r&&x<b.x)||(r==b.r&&x==b.x&&y<b.y);}
    bool in(Fence X){
        if(X.r<=r)return 0;
        if(sqr(x-X.x)+sqr(y-X.y)<=sqr(X.r-r))return 1;
        return 0;
    }
}fence[1000];
struct Knight{
    int x,y;
    void scan(){scanf("%d%d",&x,&y);}
    bool in(Fence X){
        return sqr(x-X.x)+sqr(y-X.y)<=sqr(X.r);
    }
}knight[1000];
vector<int>edge[1001],knight_in_fence[1001];
struct data{
    int x,y;
};
void dfs(int x,vector<data> &d){
    int i,j,k;
    vector<data>d2;
    for(i=0;i<knight_in_fence[x].size();i++){
        int tmp=knight_in_fence[x][i];
        for(j=0;j<d.size();j++)an[tmp][d[j].x]=an[d[j].x][tmp]=0;
        d.push_back((data){tmp,0});
    }
    for(i=0;i<edge[x].size();i++){
        d2.clear();
        dfs(edge[x][i],d2);
        for(j=0;j<d2.size();j++)
            for(k=0;k<d.size();k++)an[d2[j].x][d[k].x]=an[d[k].x][d2[j].x]=d2[j].y+d[k].y;
        for(j=0;j<d2.size();j++)d.push_back(d2[j]);
    }
    for(i=0;i<d.size();i++)d[i].y++;
}
main(){
    int i,j,n,m,k,x,y;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)knight[i].scan();
    for(i=0;i<m;i++)fence[i].scan();
    sort(fence,fence+m);
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(fence[i].in(fence[j])){
                edge[j].push_back(i);
                break;
            }
        }
        if(j==m)edge[m].push_back(i);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(knight[i].in(fence[j])){
                knight_in_fence[j].push_back(i);
                break;
            }
        }
        if(j==m)knight_in_fence[m].push_back(i);
    }
    vector<data>d;
    d.clear();
    dfs(m,d);
    while(k--){
        scanf("%d%d",&x,&y);
        x--;
        y--;
        printf("%d\n",an[x][y]);
    }
}