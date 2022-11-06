#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define M 21
int maxval[N],father[N],F[N][M+3],dep[N],d[N];
vector<int>e[N];
struct node{
    int x,y,z;
    bool used;
    node(){}
    node(int _x,int _y,int _z){
        x=_x;y=_y;z=_z;
        used=0;
    }
    bool operator <(const node t)const{
        return z<t.z;
    }
}E[N*2];
int cnt=0;
int find(int x){
    return x==father[x]?x:father[x]=find(father[x]);
}
void kruskal(int n){
    int i,j,k;
    for(i=1;i<=n;++i)father[i]=i;
    sort(E+1,E+1+cnt);
    for(i=1;i<=cnt;++i){
        if(find(E[i].x)!=find(E[i].y)){
            father[find(E[i].x)]=find(E[i].y);
            maxval[E[i].x]=max(maxval[E[i].x],E[i].z);
            maxval[E[i].y]=max(maxval[E[i].y],E[i].z);
            e[E[i].x].push_back(E[i].y);
            e[E[i].y].push_back(E[i].x);
            E[i].used=1;
        }
    }
}
void DFS(int x,int fa){
    F[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(auto y:e[x]){
        if(y!=fa){
            DFS(y,x);
        }
    }
}
void DFS2(int x,int fa){
    d[x]+=d[fa];
    for(auto y:e[x]){
        if(y!=fa){
            DFS2(y,x);
        }
    }
}
void beizeng(int n){
    int i,j;
    for(i=1;i<M;++i){
        for(j=1;j<=n;++j)F[j][i]=F[F[j][i-1]][i-1];
    }
}
int LCA(int x,int y){
    int i;
    if(dep[x]>dep[y]){
        for(i=M-1;i>=0;--i){
            if(dep[F[x][i]]>=dep[y])x=F[x][i];
        }
    }
    if(x==y)return x;
    for(i=M-1;i>=0;--i){
        if(F[x][i]!=F[y][i]){
            x=F[x][i];
            y=F[y][i];
        }
    }
    return F[x][0];
}
void work(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    int lca=LCA(x,y),i;
    if(lca!=y){
        //printf("%d %d\n",x,y);
        ++d[1];
        --d[x];
        --d[y];
    }
    else{
        --d[x];
        for(i=M-1;i>=0;--i){
            if(dep[F[x][i]]>=dep[y]+1){
                x=F[x][i];
            }
        }
        ++d[x];
    }
}
int main(){
    int n,m,i,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        E[++cnt]=node(x,y,i);
    }
    kruskal(n);
    DFS(1,0);
    beizeng(n);
    for(i=1;i<=cnt;++i){
        if(!E[i].used){
            work(E[i].x,E[i].y);
        }
    }
    DFS2(1,0);
    for(i=1;i<=n;++i){
        if(d[i]!=0)putchar('0');
        else putchar('1');
    }
    return 0;
}