#include<bits/stdc++.h>
using namespace std;
const int N=2e6,mod=1e9+7;
int n,m,cnt,q[N],l,r,dis[N],p;bool vis[N];
vector<int>v[N][10];
void add(int x,int y,int z){
    while(z>9)v[++cnt][z%10].push_back(y),y=cnt,z/=10;
    v[x][z].push_back(y);
}
int main(){
    scanf("%d%d",&n,&m);cnt=n;
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        add(x,y,i);add(y,x,i);
    }
    q[l=r=1]=1;
    while(l<=r){
        for(p=l;p<r&&dis[q[p+1]]==dis[q[p]];p++);
        for(int i=0;i<10;i++){
            for(int j=l;j<=p;j++){
                int x=q[j];
                for(int k=0;k<v[x][i].size();k++){
                    int y=v[x][i][k];
                    if(!vis[y])vis[y]=1,dis[y]=(dis[x]*10ll+i)%mod,q[++r]=y;
                }
            }
        }
        l=p+1;
    }
    for(int i=2;i<=n;i++)printf("%d\n",dis[i]);
    return 0;
}