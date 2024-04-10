#include<bits/stdc++.h>
using namespace std;

void suffixarray(const int& n,char *s,int *sa,int *rk){
    static int *oldrk,*id,*rkid,*cnt;
    oldrk=new int[(n<<1)+5];id=new int[n+5];rkid=new int[n+5];cnt=new int[max(n+5,305)];
    memset(oldrk,0,(n<<1)+5<<2);memset(cnt,0,max(n+5,305)<<2);
    struct sacmp{
        bool operator()(const int& x,const int& y,const int& w){
            return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
        }
    }cmp;

    for(int i=1;i<=n;i++)cnt[rk[i]=s[i]]++;
    for(int i=1;i<=300;i++)cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--)sa[cnt[rk[i]]--]=i;

    for(int w=1,m=300,p,i;w<n;w<<=1,m=p){
        for(p=0,i=n;i>n-w;i--)id[++p]=i;
        for(i=1;i<=n;i++)if(sa[i]>w)id[++p]=sa[i]-w;
        memset(cnt,0,max(n+5,305)<<2);
        for(i=1;i<=n;i++)cnt[rkid[i]=rk[id[i]]]++;
        for(i=1;i<=m;i++)cnt[i]+=cnt[i-1];
        for(i=n;i>=1;i--)sa[cnt[rkid[i]]--]=id[i];
        memcpy(oldrk+1,rk+1,n<<2);
        for(p=0,i=1;i<=n;i++)rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
    }

    delete[] oldrk;
    delete[] id;
    delete[] rkid;
    delete[] cnt;
}

template<typename T> struct BIT{
    int sz;
    vector<T> bit;

    BIT(int _sz){
        sz=_sz;
        bit.resize(sz+1);
    }

    T sum(int pos){
        T res=0;
        while(pos>0){
            res+=bit[pos];
            pos-=pos&-pos;
        }
        return res;
    }

    void add(int pos,T val){
        while(pos<=sz){
            bit[pos]+=val;
            pos+=pos&-pos;
        }
    }

    void clear(){
        bit.assign(sz+1,0);
    }
};

BIT<int> bit(200000);
int n,k,l[200005],r[200005],dfn[200005],dfc,st[200005],ed[200005],rnk[200005],sa[200005],rk[200005],dep[200005],fa[200005][18];
char ch[200005],s[200005];
bool vis[200005];

void gens(int x){
    st[x]=dfc+1;
    if(l[x]){
        dep[l[x]]=dep[x]+1;
        fa[l[x]][0]=x;
        gens(l[x]);
    }
    dfn[x]=++dfc;
    rnk[dfc]=x;
    s[dfc]=ch[x];
    if(r[x]){
        dep[r[x]]=dep[x]+1;
        fa[r[x]][0]=x;
        gens(r[x]);
    }
    ed[x]=dfc;
}

void init(){
    fa[1][0]=-1;
    for(int j=0;j<17;j++){
        for(int i=1;i<=n;i++){
            if(fa[i][j]==-1)fa[i][j+1]=-1;
            else fa[i][j+1]=fa[fa[i][j]][j];
        }
    }
}

void print(int x){
    if(l[x])print(l[x]);
    cout<<ch[x];if(vis[x])cout<<ch[x];
    if(r[x])print(r[x]);
}

void deal(int x){
    if(vis[x])return;
    int y=x;
    for(int i=17;i>=0;i--){
        if(fa[y][i]!=-1&&!vis[fa[y][i]])y=fa[y][i];
    }
    if(k<dep[x]-dep[y]+1)return;
    k-=dep[x]-dep[y]+1;
    vis[x]=1;
    while(x!=y)vis[x=fa[x][0]]=1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>ch+1;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
    gens(1);
    init();
    suffixarray(n,s,sa,rk);
    for(int i=1;i<=n;i++)if(rk[i]>rk[i+1]){
        if(!vis[rnk[i]]){
            bit.add(st[rnk[i]],1);
            bit.add(ed[rnk[i]]+1,-1);
        }
    }else if(!bit.sum(i)){
        deal(rnk[i]);
    }
    print(1);

    return 0;
}