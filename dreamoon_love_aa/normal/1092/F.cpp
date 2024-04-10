#include<cstdio>
#include<vector>
using namespace std;
vector<int>e[200001];
long long dp0[200001],s[200001];
long long a[200001];
void dfs0(int x,int lt){
    s[x]=a[x];
    for(int y:e[x]){
        if(y==lt)continue;
        dfs0(y,x);
        dp0[x]+=dp0[y]+s[y];
        s[x]+=s[y];
    }
}
long long an;
void dfs(int x,int lt,long long v){
    if(v+dp0[x]>an)an=v+dp0[x];
    for(int y:e[x]){
        if(y==lt)continue;
        dfs(y,x,v+dp0[x]-dp0[y]-s[y]*2+s[1]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs0(1,1);
    dfs(1,1,0);
    printf("%lld\n",an);
    return 0;
}