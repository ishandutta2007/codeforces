#include<bits/stdc++.h>
using namespace std;

int n,k,sz[50005];
int nxt[100005],to[100005],head[100005],ecnt;
bool ban[50005];
int arr[100005],parr;

void add(int u,int v){
    nxt[++ecnt]=head[u];
    head[u]=ecnt;
    to[ecnt]=v;
}

int gctr(int x,int p,int tot){
    sz[x]=1;
    int mx=0,res=-1;
    for(int i=head[x];~i;i=nxt[i])if(to[i]!=p&&!ban[to[i]]){
        res=max(res,gctr(to[i],x,tot));
        sz[x]+=sz[to[i]];
        mx=max(mx,sz[to[i]]);
    }
    if(max(mx,tot-sz[x])<=tot>>1)res=x;
    return res;
}

void gdis(int x,int p,int d,int *cnt,int &csz){
    cnt[csz++]=d++;
    for(int i=head[x];~i;i=nxt[i])if(to[i]!=p&&!ban[to[i]]){
        gdis(to[i],x,d,cnt,csz);
    }
}

int solve(int x){
    ban[x]=true;
    int res=0;
    int *v=arr+parr;
    memset(v,0,k<<2);
    parr+=k;
    v[0]=1;
    for(int i=head[x];~i;i=nxt[i])if(!ban[to[i]]){
        int *cnt=arr+parr,csz=0;
        gdis(to[i],x,1,cnt,csz);
        for(int c=0;c<csz;c++)if(cnt[c]<=k)res+=v[k-cnt[c]];
        for(int c=0;c<csz;c++)if(cnt[c]<k)v[cnt[c]]++;
        res+=solve(gctr(to[i],x,csz));
    }
    parr-=k;
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(head,ecnt=-1,sizeof(head));
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    cout<<solve(1)<<endl;

    return 0;
}