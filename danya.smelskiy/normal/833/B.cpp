#include <bits/stdc++.h>
using namespace std;

int n,m,sz;
int a[100005];
int dp[100005];
int tree[500005];
int q[500005];
int last[100005];
bool used[100005];
void push(int x){
    if (q[x]==0) return;
    q[x+x]+=q[x];
    tree[x+x]+=q[x];
    q[x+x+1]+=q[x];
    tree[x+x+1]+=q[x];
    q[x]=0;
}
void update(int l,int r,int ll,int rr,int x){
    if (l!=r) push(x);
    if (l>r || ll>r || l>rr ||ll>rr) return;
    if (l>=ll && r<=rr) {
        tree[x]++;
        q[x]++;
        if (l!=r) push(x);
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x+x);
    update(mid+1,r,ll,rr,x+x+1);
    tree[x]=max(tree[x+x],tree[x+x+1]);
}
int get(int l,int r,int ll,int rr,int x){
    if (l!=r) push(x);
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)>>1;
    return max(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        dp[i]=dp[i-1];
        if (used[a[i]]==false) {
            used[a[i]]=true;
            ++dp[i];
        }
    }
    sz=1;
    while (sz<n+100) sz+=sz;
    for (int i=2;i<=m;++i) {
        for (int j=1;j<=sz+sz;++j){
            q[j]=0;
            tree[j]=0;
        }
        for (int j=1;j<=n;++j) {
            last[j]=1;
            tree[sz+j-1]=dp[j];
        }
        for (int j=sz-1;j>0;--j)
            tree[j]=max(tree[j+j],tree[j+j+1]);
        for (int j=2;j<=n;++j) {
            int x=a[j];
            update(1,sz,last[x],j-1,1);
            int res=get(1,sz,1,j-1,1);
            dp[j]=res;
            last[x]=j;
        }
        dp[i-1]=0;
    }
    cout<<dp[n];
}