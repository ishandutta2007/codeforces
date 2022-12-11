#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;
const int N=2e5+50;
int n,a[N],b[N],m[N],mm[N];pii t[N*4],d[N];
vector<pii >v[N],vv[N];
priority_queue<pii >q;
void build(int x,int l,int r){
    if(l==r){t[x]=d[l];return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    t[x]=max(t[x<<1],t[x<<1|1]);
}
pii query(int x,int l,int r,int ql,int qr){
    if(l>qr||r<ql||ql>qr)return mp(0,0);
    if(l>=ql&&r<=qr)return t[x];
    int mid=(l+r)>>1;
    return max(query(x<<1,l,mid,ql,qr),query(x<<1|1,mid+1,r,ql,qr));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),v[b[i]].pb(mp(a[i],i));
    for(int i=n;i;i--){
        for(int j=0;j<v[i].size();j++)q.push(v[i][j]);
        m[q.top().second]=i;q.pop();
    }
    for(int i=1;i<=n;i++)d[m[i]]=max(d[m[i]],mp(b[i],i));
    build(1,1,n);
    for(int i=1;i<=n;i++){
        pii x=query(1,1,n,a[i],m[i]-1);
        if(x.first>=m[i]){
            memcpy(mm,m,sizeof(m));
            mm[i]=m[x.second];mm[x.second]=m[i];
            break;
        }
    }
    puts(mm[1]?"NO":"YES");
    for(int i=1;i<=n;i++)printf("%d ",m[i]);puts("");
    if(mm[1])for(int i=1;i<=n;i++)printf("%d ",mm[i]);
    return 0;
}