#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pil pair<int,LL>
using namespace std;
const int N=2e5+50,mod=99991,M=1e6+50,B=450;
int n,m,bel[N],sq,num,ll[N],nxt[N],tot,st[N],tp,pre[M],q,d[N];ULL mark[N],p[N],now;LL ans;
struct node{ULL v;int nn;LL sum;}h[N];
struct Node{
    int x;ULL val;
    bool friend operator <(Node a,Node b){return a.x<b.x;}
}Q[N*2];
int New(){return tp?st[tp--]:++tot;}
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
struct P{
    int head[mod];
    void add(ULL v,int k){
        int val=v%mod,x,kk=k>0?1:-1;
        for(int i=head[val],la=0;i;la=i,i=nxt[i])
            if(h[i].v==v){
                h[i].sum+=k;h[i].nn+=kk;
                if(!h[i].nn)st[++tp]=i,la?nxt[la]=nxt[i]:head[val]=nxt[i];
                return;
            }
        h[x=New()]=(node){v,1,k};nxt[x]=head[val];head[val]=x;
    }
    pil ask(ULL v){
        int val=v%mod;
        for(int i=head[val];i;i=nxt[i])
            if(h[i].v==v)return make_pair(h[i].nn,h[i].sum);
        return make_pair(0,0);
    }
}hsh[B];
void change(int r,ULL v){
    for(int i=1;i<bel[r];i++)mark[i]^=v;
    for(int i=ll[bel[r]];i<=r;i++)p[i]^=v;
}
pil query(int r){
    int ret1=0;LL ret2=0;
    for(int i=1;i<bel[r];i++){
        pil p=hsh[i].ask(mark[i]);
        ret1+=p.first;ret2+=p.second;
    }
    for(int i=ll[bel[r]];i<=r;i++)
        if(!p[i])ret1++,ret2+=i;
    return make_pair(ret1,ret2);
}
int main(){
    n=read();m=read();srand(time(0));sq=500;
    for(int i=1,l,r;i<=n;i++){
        l=read(),r=read();d[l]++;d[r+1]--;
        if(l<r){
            ULL x=1ull*(rand()+1)*(rand()+1)*(rand()+1)*(rand()+1);
            Q[++q]=(Node){l,x};Q[++q]=(Node){r,x};
        }
    }
    sort(Q+1,Q+q+1);
    for(int i=1;i<=m;i++)bel[i]=(i-1)/sq+1;num=bel[m];
    for(int i=1;i<=num;i++)ll[i]=(i-1)*sq+1;
    for(int i=1,j=0;i<=m;i++){
        if(now)change(i-1,now);
        if(i==ll[bel[i]]&&i!=1)
            for(int j=ll[bel[i]-1];j<i;j++)
                hsh[bel[i]-1].add(p[j],j);
        pil p=query(i);
        ans+=1ll*p.first*(i+1)-p.second;
        while(j<q&&Q[j+1].x<=i)now^=Q[++j].val;
    }
    for(int i=1,cnt=0,len=0;i<=m;i++){
        cnt+=d[i];cnt?len=0:len++;
        ans-=1ll*len*(len+1)/2;
    }
    cout<<ans;
    return 0;
}