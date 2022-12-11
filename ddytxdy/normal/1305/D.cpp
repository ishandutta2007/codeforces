#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,ver[N*2],nxt[N*2],head[N],tot=1,d[N],st[N*2],tp,xx,yy;bool fl[N*2],flag=0;
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;d[y]++;}
int ask(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int z;cin>>z;return z;
}
void dfs(int x,int ff){
    if(x==xx||x==yy)flag=1;
    for(int i=head[x],y;i;i=nxt[i])
        if(!fl[i]&&(y=ver[i])!=ff)
            st[++tp]=i,st[++tp]=i^1,dfs(y,x);
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    while(1){
        int x=0,y=0;
        for(int i=1;i<=n;i++)if(d[i]==1){
            if(!x)x=i;
            else{y=i;break;}
        }
        if(!y)cout<<"! "<<x<<endl,exit(0);
        int z=ask(x,y);xx=x;yy=y;
        if(d[z]<=2)cout<<"! "<<z<<endl,exit(0);
        for(int i=head[z];i;i=nxt[i]){
            if(fl[i])continue;
            flag=tp=0;dfs(ver[i],z);
            if(flag){
                while(tp)fl[st[tp]]=1,d[ver[st[tp--]]]--;
                fl[i]=fl[i^1]=1;d[ver[i]]--;d[z]--;
            }
        }
    }
    return 0;
}
// 6
// 1 4
// 4 2
// 5 3
// 6 3
// 2 3