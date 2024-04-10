#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,ver[N*6],nxt[N*6],head[N],tot,la,col[N],num[3];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void f(){puts("-1");exit(0);}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
    for(int i=head[1],y;i;i=nxt[i])col[la=y=ver[i]]=1;
    for(int i=head[la],y;i;i=nxt[i])if(col[y=ver[i]])col[y]=2;
    for(int i=1;i<=n;i++)num[col[i]]++;
    if(!num[0]||!num[1]||!num[2])f();
    for(int x=1;x<=n;x++){
        int nn=0;
        for(int i=head[x],y;i;i=nxt[i],nn++)if(col[y=ver[i]]==col[x])f();
        if(nn!=n-num[col[x]])f();
    }
    for(int i=1;i<=n;i++)printf("%d ",col[i]+1);
    return 0;
}