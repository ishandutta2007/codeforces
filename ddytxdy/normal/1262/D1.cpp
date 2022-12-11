#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m,mx[N*4],cnt[N*4],a[N],ans[N];
struct node{int k,pos,id;bool friend operator <(node a,node b){return a.k<b.k;}}Q[N];
void build(int x,int l,int r){
    if(l==r){scanf("%d",&a[l]);mx[x]=a[l];return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
void change(int x,int l,int r){
    if(l==r){cnt[x]++;mx[x]=0;return;}
    int mid=(l+r)>>1;
    if(mx[x<<1|1]>mx[x<<1])change(x<<1|1,mid+1,r);
    else change(x<<1,l,mid);
    cnt[x]=cnt[x<<1]+cnt[x<<1|1];
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
int query(int x,int l,int r,int k){
    if(l==r)return a[l];
    int mid=(l+r)>>1;
    if(cnt[x<<1]>=k)return query(x<<1,l,mid,k);
    return query(x<<1|1,mid+1,r,k-cnt[x<<1]);
}
int main(){
    scanf("%d",&n);build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d%d",&Q[i].k,&Q[i].pos),Q[i].id=i;
    sort(Q+1,Q+m+1);
    for(int i=1,j=1;i<=m;i++){
        while(j<=Q[i].k)change(1,1,n),j++;
        ans[Q[i].id]=query(1,1,n,Q[i].pos);
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}