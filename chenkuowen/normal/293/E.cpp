#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> void chmax(T& x,T y){ y>x?x=y:T(); }
template<class T> void chmin(T& x,T y){ y<x?x=y:T(); }
namespace IO{
    const int sz=1<<20;
    char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
    inline char gc(){
        return getchar();
        return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
    }
    template<class T> void gi(T& x){
        x=0; char c=gc(); int f=1;
        for(;c<'0'||c>'9';c=gc())
            if(c=='-') f=-1;
        for(;c>='0'&&c<='9';c=gc())
            x=x*10+(c-'0');
        x*=f;
    }
    inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
    inline void pc(char x){*t++=x; if(t-b==sz) flush();}
    template<class T>inline void pi(T x,char c='\n'){
        if(x<0) x=-x,pc('-');
        if(x==0) pc('0'); int t=0;
        for(;x;x/=10) p[++t]=x%10+'0';
        for(;t;--t) pc(p[t]); pc(c);
    }
    struct F{~F(){flush();}}f;
}
using IO::gi;
using IO::pi;
const int N=5+1e5;
struct BIT{
    vector<int> c;
    BIT(int n=0){c=vector<int>(n+2,0);}
    inline void add(int x,int k){
        ++x;
        for(;x<c.size();x+=x&-x) c[x]+=k;
    }
    inline int query(int x){
        ++x;
        if(x>=(int)c.size()) x=(int)c.size()-1;
        if(x<0) return 0;
        int ret=0;
        for(;x;x-=x&-x) ret+=c[x];
        return ret;
    }
}bit;
struct Graph{
    struct Edge{ int to,nxt,k; bool mark; }edge[N*2];
    int head[N],top;
    Graph(){memset(head,-1,sizeof(head)),top=-1;}
    inline void add(int x,int y,int k){
        edge[++top]=(Edge){y,head[x],k,false};
        head[x]=top;
    }
    inline void add2(int x,int y,int k){
        add(x,y,k); add(y,x,k);
    }
}G;
int sz[N],val[N];
void get_sz(int x,int pre){
    sz[x]=1; val[x]=0;
    for(int j=G.head[x];~j;j=G.edge[j].nxt){
        int y=G.edge[j].to;
        if(y!=pre&&!G.edge[j].mark){
            get_sz(y,x); sz[x]+=sz[y];
            chmax(val[x],sz[y]);
        }
    }
}
int get_rt(int x,int pre,int size){
    int rt=x; chmax(val[x],size-sz[x]);
    for(int j=G.head[x];~j;j=G.edge[j].nxt){
        int y=G.edge[j].to;
        if(y!=pre&&!G.edge[j].mark){
            int k=get_rt(y,x,size);
            if(val[k]<val[rt]) rt=k;
        }
    }
    return rt;
}
void dfs(int x,int pre,int weight,int length,vector<pair<int,int> >& g){
    g.push_back(make_pair(weight,length));
    for(int j=G.head[x];~j;j=G.edge[j].nxt){
        int y=G.edge[j].to;
        if(y!=pre&&!G.edge[j].mark)
            dfs(y,x,weight+G.edge[j].k,length+1,g);
    }
}
typedef vector<pair<int,int> > V;
ll ans=0;
struct Cmp{
    bool operator()(V a,V b){ return a.size()>b.size(); }
};
int tpw,tpl;
V merge(V a,V b){
    int mx=0;
    for(int i=0;i<b.size();++i)
        chmax(mx,b[i].second);
    BIT bit(mx);
    for(int i=0;i<b.size();++i)
        bit.add(b[i].second,1);
    int j=(int)b.size()-1;
    for(int i=0;i<a.size();++i){
        for(;j>=0&&b[j].first+a[i].first>tpw;--j)
            bit.add(b[j].second,-1);
        ans+=bit.query(tpl-a[i].second);
    }
    V c; c.resize(a.size()+b.size());
    merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
    return c;
}
void dc(int x){
    get_sz(x,0);
    x=get_rt(x,0,sz[x]);
    get_sz(x,0);
    priority_queue<V,vector<V>,Cmp> q;
    V f; f.push_back(make_pair(0,0));
    q.push(f);
    for(int j=G.head[x];~j;j=G.edge[j].nxt){
        int y=G.edge[j].to;
        if(!G.edge[j].mark){
            vector<pair<int,int> > g; g.reserve(sz[y]);
            dfs(y,x,G.edge[j].k,1,g);
            sort(g.begin(),g.end());
            q.push(g);
        }
    }
    while(q.size()>1){
        V a=q.top(); q.pop();
        V b=q.top(); q.pop();
        q.push(merge(a,b));
    }
//  printf("<%d %lld>",x,ans);
    for(int j=G.head[x];~j;j=G.edge[j].nxt){
        int y=G.edge[j].to;
        if(!G.edge[j].mark){
            G.edge[j].mark=G.edge[j^1].mark=1;
            dc(y);
        }
    }
}
int main(){
//  freopen("1.in","r",stdin);
//  freopen("1.out","w",stdout);
    int n; gi(n); gi(tpl); gi(tpw);
//  q=ans=vector<int>(m);
    for(int i=2;i<=n;++i){
        int x,w; gi(x); gi(w);
        G.add2(x,i,w);
    }
    dc(1);
    printf("%lld\n",ans);
    return 0;
}