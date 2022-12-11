#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=3e5+50;
int T,n,a[N],p=0;bool vis[N];
vector<int>ans;
int mex(){
    for(int i=0;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++)vis[a[i]]=1;
    for(int i=0;i<=n;i++)if(!vis[i])return i;
}
void solve(){
    scanf("%d",&n);p=1;ans.clear();a[n+1]=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    while(p!=n+1){
        int x=mex();
        if(x==n)a[p]=x,ans.pb(p);
        else a[x+1]=x,ans.pb(x+1);
        while(a[p]==p-1)p++;
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);puts("");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}