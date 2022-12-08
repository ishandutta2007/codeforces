#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,top;
int ans[maxn],a[maxn];
int fir[maxn*2],nxt[maxn*2],gett[maxn*2];
inline void add(int x,int y){
    gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
void get_ans(int x,int fa,int val){
    ans[x]=val;
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        get_ans(v,x,__gcd(val,a[v]));
    }
}
void dfs(int x,int fa,int val,int k){
    if (k>=2) return;
    ans[x]=max(ans[x],val);
    int f=1;
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        if (a[v]%val==0) f=0;
        dfs(v,x,val,k+f);
        f=1;
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1,x,y;i<n;++i){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    } 
    get_ans(1,0,0);
    for (int i=1;i*i<=a[1];++i){
        if (a[1]%i) continue;
        dfs(1,0,i,0); dfs(1,0,a[1]/i,0);
    }
    for (int i=1;i<=n;++i) printf("%d ",ans[i]);
    return 0;
}