#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=4e5+7;
vector<int> prime;
int arr[maxn];
bool isprime[305];
long long seg[maxn*4],lazy[maxn*4];
long long orseg[maxn*4],orlazy[maxn*4];
long long inv[63];
long long quick(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
inline void db()
{
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<=300;i++)
    {
        if(isprime[i]) prime.push_back(i);
        for(int j=0;j<prime.size()&&i*prime[j]<=300;j++)
        {
            if(i%prime[j]==0){
                isprime[i*prime[j]]=0;
                break;
            }
            isprime[i*prime[j]]=0;
        }
    }
    for(int i=0;i<prime.size();i++)
        inv[i]=quick(prime[i],mod-2);
}
inline void pushup(int rt)
{
    seg[rt]=seg[rt*2]*seg[rt*2+1]%mod;
}
void build(int l,int r,int rt)
{
    lazy[rt]=1;
    if(l==r)
    {
        seg[rt]=arr[l];
        return ;
    }
    int mid=l+r>>1;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
inline void pushdown(int rt,int len)
{
    if(lazy[rt]!=1)
    {
        seg[rt*2]=seg[rt*2]*quick(lazy[rt],len-len/2)%mod;
        seg[rt*2+1]=seg[rt*2+1]*quick(lazy[rt],len/2)%mod;
        lazy[rt*2]=lazy[rt*2]*lazy[rt]%mod;
        lazy[rt*2+1]=lazy[rt*2+1]*lazy[rt]%mod;
        lazy[rt]=1;
    }
}
void update(int l,int r,int val,int L,int R,int rt)
{
    if(l<=L&&r>=R)
    {
        seg[rt]=seg[rt]*quick(val,R-L+1)%mod;
        lazy[rt]=lazy[rt]*val%mod;
        return ;
    }
    pushdown(rt,R-L+1);
    int mid=L+R>>1;
    if(l<=mid) update(l,r,val,L,mid,rt*2);
    if(r>mid) update(l,r,val,mid+1,R,rt*2+1);
    pushup(rt);
}
long long query(int l,int r,int L,int R,int rt)
{
    if(l<=L&&r>=R)
        return seg[rt];
    pushdown(rt,R-L+1);
    int mid=L+R>>1;
    long long ret=1;
    if(l<=mid) ret=ret*query(l,r,L,mid,rt*2)%mod;
    if(r>mid) ret=ret*query(l,r,mid+1,R,rt*2+1)%mod;
    return ret;
}
inline void orpushup(int rt)
{
    orseg[rt]=orseg[rt*2]|orseg[rt*2+1];
}
void orbuild(int l,int r,int rt)
{
    orlazy[rt]=0;
    if(l==r)
    {
        int cur=arr[l];
        long long now=0;
        for(int i=0;i<prime.size();i++)
        {
            if(cur%prime[i]==0)
                now+=(1LL<<i);
        }
        orseg[rt]=now;
        return ;
    }
    int mid=l+r>>1;
    orbuild(l,mid,rt*2);
    orbuild(mid+1,r,rt*2+1);
    orpushup(rt);
}
inline void orpushdown(int rt)
{
    if(orlazy[rt])
    {
        orlazy[rt*2]|=orlazy[rt];
        orlazy[rt*2+1]|=orlazy[rt];
        orseg[rt*2]|=orlazy[rt];
        orseg[rt*2+1]|=orlazy[rt];
        orlazy[rt]=0;
    }
}
void orupdate(int l,int r,long long x,int L,int R,int rt)
{
    if(l<=L&&r>=R)
    {
        orseg[rt]|=x;
        orlazy[rt]|=x;
        return;
    }
    orpushdown(rt);
    int mid=L+R>>1;
    if(l<=mid) orupdate(l,r,x,L,mid,rt*2);
    if(r>mid) orupdate(l,r,x,mid+1,R,rt*2+1);
    orpushup(rt);
}
long long orquery(int l,int r,int L,int R,int rt)
{
    if(l<=L&&r>=R)
        return orseg[rt];
    orpushdown(rt);
    int mid=L+R>>1;
    long long ret=0;
    if(l<=mid) ret|=orquery(l,r,L,mid,rt*2);
    if(r>mid) ret|=orquery(l,r,mid+1,R,rt*2+1);
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    db();
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    build(1,n,1);
    orbuild(1,n,1);
    char op[10];
    int l,r,x;
    while(q--)
    {
        cin>>op;
        cin>>l>>r;
        if(op[0]=='M')
        {
            cin>>x;
            long long cur=0;
            for(int i=0;i<prime.size();i++)
                if(x%prime[i]==0)
                    cur+=(1LL<<i);
            update(l,r,x,1,n,1);
            orupdate(l,r,cur,1,n,1);
        }
        else{
            long long ans=query(l,r,1,n,1);
            long long cur=orquery(l,r,1,n,1);
            for(int i=0;i<prime.size();i++)
            {
                if(cur&(1LL<<i))
                    ans=ans*inv[i]%mod*(prime[i]-1)%mod;
            }
            cout<<ans<<endl;
        }
    }
}