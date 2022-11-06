#include<bits/stdc++.h>
using namespace std;
#define N 200005
char s[N];
int a[N],n;
int t[N<<4];
long long sum[N];

pair<long long,long long>t0[N<<4];
void up0(int x){
    t0[x].first = t0[x<<1].first + t0[x<<1|1].first;
    t0[x].second = t0[x<<1].second + t0[x<<1|1].second;
}
void init0(int i,int l,int r){
    if(l==r){
        t0[i].first=t0[i].second=0;
        return;
    }
    int mid=(l+r)>>1;
    init0(i<<1,l,mid);
    init0(i<<1|1,mid+1,r);
    up0(i);
}
void add(int i,int l,int r,int x){
    if(l==r){
        t0[i].first ++;
        t0[i].second += x;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)add(i<<1,l,mid,x);
    else add(i<<1|1,mid+1,r,x);
    up0(i);
}
pair<long long,long long> qry0(int i,int l,int r,int x){
    if(r<=x)return t0[i];
    int mid=(l+r)>>1;
    pair<long long,long long> res = qry0(i<<1,l,mid,x);
    if(mid<x){
        pair<long long,long long> res1 = qry0(i<<1|1,mid+1,r,x);
        res.first+=res1.first;
        res.second+=res1.second;
    }
    return res;
}

void up(int x){
    if(a[t[x<<1]] <= a[t[x<<1|1]])t[x] = t[x<<1];
    else t[x]=t[x<<1|1];
}
void init(int i,int l,int r){
    if(l==r){
        t[i]=l;
        return;
    }
    int mid=(l+r)>>1;
    init(i<<1,l,mid);
    init(i<<1|1,mid+1,r);
    up(i);
}
long long ans = 0;
int qry(int i,int l,int r,int x,int y){
    if(x<=l&&r<=y)return t[i];
    int mid=(l+r)>>1,res=-1;
    if(x<=mid){
        int a1=qry(i<<1,l,mid,x,y);
        if(res==-1)res=a1;
    }
    if(y>mid){
        int a1=qry(i<<1|1,mid+1,r,x,y);
        if(res==-1)res=a1;
        else if(a[res]>a[a1])res=a1;
    }
    return res;
}
void solve(int l,int r){
    if(l>=r)return;
    int id = qry(1,0,n,l,r);
    ans += (sum[id]-sum[max(0,l-1)]-1LL*a[id]*(id-l+1))*(r-id+1);
    solve(l,id-1);
    solve(id+1,r);
}
void work(){
    int i,j,k;
    scanf("%d",&n);
    scanf("%s",s+1);
    init0(1,-n,n);
    add(1,-n,n,0);
    ans = 0;
    for(i=1;i<=n;++i){
        if(s[i]=='(')a[i]=a[i-1]+1;
        else a[i]=a[i-1]-1;
        auto p = qry0(1,-n,n,a[i]);
        add(1,-n,n,a[i]);
        ans = ans + 1LL*a[i]*p.first - p.second;
        sum[i] = sum[i-1]+a[i];
        //printf("<%lld, %lld>",p.first , p.second);
    }
    //printf("%lld\n",ans);
    init(1,0,n);
    solve(0,n);
    printf("%lld\n",ans);
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--)work();
    return 0;
}