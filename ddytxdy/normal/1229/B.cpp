#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=1e5+50,mod=1e9+7;
int n,ver[N*2],nxt[N*2],head[N],tot,ans;LL a[N];
map<LL,int>mp[N];
map<LL,int>::iterator it;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x,int ff){
    for(auto [i,j] : mp[ff])mp[x][gcd(i,a[x])]+=j,ans=(ans+gcd(i,a[x])*j)%mod;
    mp[x][a[x]]++;ans=(ans+a[x])%mod;
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=ff)dfs(y,x);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}