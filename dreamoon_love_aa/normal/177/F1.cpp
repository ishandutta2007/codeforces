#include<cstdio>
int x,y,z,n,m,k,med,a[21][21],cnt,u[21];
void dfs(int id,int v){
    if(id>n)return;
    if(cnt>=k)return;
    for(int i=1;i<=n;i++){
        if(!u[i]&&a[id][i]&&v+a[id][i]<=med){
            cnt++;
            u[i]=1;
            dfs(id+1,v+a[id][i]);
            u[i]=0;
        }
    }
    dfs(id+1,v);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++) scanf("%d%d%d",&x,&y,&z), a[x][y]=z;
    int lo=0,hi=n*1000;
    while(lo<hi){
        med=(lo+hi)/2;
        cnt=1;
        dfs(1,0);
        if(cnt>=k)hi=med;
        else lo=med+1;
    }
    printf("%d\n",lo);
}