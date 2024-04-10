#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=7050,M=N*N/2;
int n,b[N],ver[M],nxt[M],head[N],tot;LL a[N],ans;bool vis[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
vector<int>v;
void dfs(int x){
    ans+=b[x];vis[x]=1;
    for(int i=head[x];i;i=nxt[i])if(!vis[ver[i]])dfs(ver[i]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=i+1;j<=n;j++){
            if(a[j]==a[i])flag=1,add(i,j);
            else if((a[i]&a[j])==a[i])add(j,i);
            else if((a[i]&a[j])==a[j])add(i,j);
        }
        if(flag)v.push_back(i);
    }
    for(int i=0;i<v.size();i++)if(!vis[v[i]])dfs(v[i]);
    cout<<ans;
    return 0;
}