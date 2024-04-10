#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50,inf=1e9+1;
int n,a[N],rt,ans1,ans2,d[N],f[2];
vector<int>v[N];
void dfs(int x,int ff){
    int num=0;
    for(int i=0,y;i<v[x].size();i++){
        if((y=v[x][i])==ff)continue;
        num+=v[y].size()==1;d[y]=d[x]+1;dfs(y,x);
    }
    if(num>1)ans2-=num-1;
}
int main(){
    scanf("%d",&n);ans2=n-1;
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),v[x].pb(y),v[y].pb(x);
    for(int i=1;i<=n;i++)if(v[i].size()>1)rt=i;
    dfs(rt,0);for(int i=1;i<=n;i++)if(v[i].size()==1)f[d[i]&1]=1;
    cout<<(f[0]&&f[1]?3:1)<<" "<<ans2<<endl;
    return 0;
}