#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
struct edge{
    int x,y,z;
}e[maxn];
int i,j,k,n,m,F[maxn],Fa[maxn][21],deep[maxn],num[maxn],Ans[maxn];
int find(int x){
    if(F[x]==x)return x;
    return F[x]=find(F[x]);
}
vector<int>V[maxn];
string S;
void dfs(int now,int fa){
    Fa[now][0]=fa;
    deep[now]=deep[fa]+1;
    for(int u:V[now]){
        if(u==fa)continue;
        dfs(u,now);
    }
}
int jump(int x,int s){
    for(int i=20;i>=0;i--)
        if(s>=(1<<i))s-=(1<<i),x=Fa[x][i];
    return x;
}
void dfs2(int now,int fa,int S){
    S+=num[now];
    Ans[now]=S;
    for(int u:V[now]){
        if(u==fa)continue;
        dfs2(u,now,S);
    }
}
int main(){
    int T=1;
    // cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)F[i]=i,num[i]=Ans[i]=0;
        for(i=1;i<=m;i++)
            scanf("%d%d",&e[i].x,&e[i].y),e[i].z=i;
        for(i=1;i<=m;i++){
            if(find(e[i].x)!=find(e[i].y)){
                V[e[i].x].push_back(e[i].y);
                V[e[i].y].push_back(e[i].x);
                e[i].z=-1;
                F[find(e[i].x)]=e[i].y;
            }
        }
        dfs(1,0);
        for(i=1;i<=20;i++)
            for(j=1;j<=n;j++)
                Fa[j][i]=Fa[Fa[j][i-1]][i-1];
        for(i=1;i<=m;i++)
            if(e[i].z>0){
                int X=e[i].x,Y=e[i].y;
                if(deep[X]<deep[Y])swap(X,Y);
                if(jump(X,deep[X]-deep[Y])==Y){
                    int Z=jump(X,deep[X]-deep[Y]-1);
                    num[Z]--;
                    num[X]++;
                }else{
                    num[1]--;
                    num[X]++;
                    num[Y]++;
                }
            }
        dfs2(1,0,0);
        for(i=1;i<=n;i++)
            if(!Ans[i])putchar('1');else putchar('0');
    }
}
/*
a1 a2 a3 a4
a2-a1 a3-a2 a4-a3
a3-2a2+a1 a4-2a3+a2
*/