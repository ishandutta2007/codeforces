#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define INF 1000000002
int t[N*36+5],x[N],p[N];
long long sum[N*9+5],sum1[N*9+5],sum2[N*9+5];
long long S[N*36+5],S1[N*36+5],S2[N*36+5];
void work1(int i,int l,int r){
    if(l==r){
        S[i]=sum[l];
        S1[i]=sum1[l];
        S2[i]=sum2[l];
        return;
    }
    int mid=(l+r)>>1;
    work1(i<<1,l,mid);
    work1(i<<1|1,mid+1,r);
    S[i]= max(S[i<<1],S[i<<1|1]);
    S1[i]=max(S1[i<<1],S1[i<<1|1]);
    S2[i]=max(S2[i<<1],S2[i<<1|1]);
}
vector<int>v;
void init(int i,int l,int r){
    t[i]=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    init(i<<1,l,mid);
    init(i<<1|1,mid+1,r);
}
void add(int i,int l,int r,int x,int y,int d){
    if(x<=l&&r<=y){
        t[i]+=d;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)add(i<<1,l,mid,x,y,d);
    if(y>mid)add(i<<1|1,mid+1,r,x,y,d);
}
void upd(int i,int l,int r){
    if(l==r)return;
    t[i<<1]+=t[i];
    t[i<<1|1]+=t[i];
    t[i]=0;
    int mid=(l+r)>>1;
    upd(i<<1,l,mid);
    upd(i<<1|1,mid+1,r);
}
int qry(int i,int l,int r,int x){
    if(l==r)return t[i];
    int mid=(l+r)>>1;
    if(x<=mid)return qry(i<<1,l,mid,x);
    else return qry(i<<1|1,mid+1,r,x);
}
int find(int x){
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}
long long query(int i,int l,int r,int x,int y){
    assert(y>=x);
    if(x<=l&&r<=y)return S[i];
    int mid=(l+r)>>1;
    long long res=-1LL*INF*INF;
    if(x<=mid)res=max(res,query(i<<1,l,mid,x,y));
    if(y>mid)res=max(res,query(i<<1|1,mid+1,r,x,y));
    return res;
}
long long query1(int i,int l,int r,int x,int y){
    assert(y>=x);
    if(x<=l&&r<=y)return S1[i];
    int mid=(l+r)>>1;
    long long res=-1LL*INF*INF;
    if(x<=mid)res=max(res,query1(i<<1,l,mid,x,y));
    if(y>mid)res=max(res,query1(i<<1|1,mid+1,r,x,y));
    return res;
}
long long query2(int i,int l,int r,int x,int y){
    assert(y>=x);
    if(x<=l&&r<=y)return S2[i];
    int mid=(l+r)>>1;
    long long res=-1LL*INF*INF;
    if(x<=mid)res=max(res,query2(i<<1,l,mid,x,y));
    if(y>mid)res=max(res,query2(i<<1|1,mid+1,r,x,y));
    return res;
}
void work(){
    int n,m1,i,j;
    v.clear();
    v.push_back(-INF);
    v.push_back(INF*2);
    scanf("%d%d",&n,&m1);
    for(i=1;i<=n;++i){
        scanf("%d%d",&x[i],&p[i]);
        v.push_back(x[i]+p[i]);
        v.push_back(x[i]+p[i]-1);
        v.push_back(x[i]+p[i]+1);
        v.push_back(x[i]-p[i]);
        v.push_back(x[i]-p[i]+1);
        v.push_back(x[i]-p[i]-1);
        v.push_back(x[i]);
        v.push_back(x[i]+1);
        v.push_back(x[i]-1);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    int m=v.size();
    init(1,0,m-1);
    for(i=1;i<=n;++i){
        int l=find(x[i]-p[i]+1);
        int r=find(x[i]);
        add(1,0,m-1,l,r,1);
        l=find(x[i]+1);
        r=find(x[i]+p[i]);
        add(1,0,m-1,l,r,-1);
    }
    upd(1,0,m-1);
    sum[0]=qry(1,0,m-1,0);
    for(i=1;i<m;++i)sum[i]=sum[i-1]+1LL*qry(1,0,m-1,i)*(v[i]-v[i-1]);
    for(i=0;i<m;++i)sum1[i]=sum[i]+v[i],sum2[i]=sum[i]-v[i];
    //for(i=0;i<m;++i)printf("<%d:%lld %lld %lld> ",v[i],sum[i],sum1[i],sum2[i]);
    work1(1,0,m-1);
    for(i=1;i<=n;++i){
        long long ans = -1LL*INF*INF;
        long long res1=query2(1,0,m-1,find(x[i]-p[i]),find(x[i]))-(p[i]-x[i]);
        long long res2=query1(1,0,m-1,find(x[i]),find(x[i]+p[i]))-(p[i]+x[i]);
        long long res3= query(1,0,m-1,0,find(x[i]-p[i]));
        long long res4= query(1,0,m-1,find(x[i]+p[i]),m-1);
        assert(min(res1,res2)>=0&&min(res3,res4)>=0);
        //printf("%lld %lld %lld %lld\n",res1,res2,res3,res4);
        ans=max(max(res1,res2),max(res3,res4));
        if(ans-m1>0LL)printf("0");
        else printf("1");
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}