#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
int n,m,c[605][605];
int dis[605],w[605],book[605];
void dijkstra(int s){
    memset(dis,0x7f,sizeof(dis));
    memset(book,0,sizeof(book));
    dis[s]=0;
    int id=s,mn=2e9;
    book[s]=1;
    while(id!=-1){
        int now=id;
        memset(w,0x7f,sizeof(w));
        for (int i=0;i<n;i++)
            if (c[now][i]!=-1)w[(i+dis[now])%n]=c[now][i];
        for (int i=0;i<n;i++)w[i]=min(w[i],w[(i+n-1)%n]+1);
        for (int i=0;i<n;i++)w[i]=min(w[i],w[(i+n-1)%n]+1);
        for (int i=0;i<n;i++)dis[i]=min(dis[i],dis[now]+w[i]);
        id=-1,mn=2e9;
        for (int i=0;i<n;i++){
            if (book[i]==1)continue;
            if (dis[i]<mn)mn=dis[i],id=i;
        }
        book[id]=1;
    }
    return;
}
int main(){
    cin>>n>>m;
    memset(c,-1,sizeof(c));
    for (int i=1;i<=m;i++){
        int u,v,w;
        u=read(),v=read(),w=read();
        c[u][v]=w;
    }
    for (int i=0;i<n;i++){
        dijkstra(i);
        for (int j=0;j<n;j++)printf("%d ",dis[j]);
        puts("");
    }
    return 0;
}