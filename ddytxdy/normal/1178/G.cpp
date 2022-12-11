#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define double long double
using namespace std;
const int N=2e5+50,B=1111;
const double inf=5e18;
const double eps=1e-12;
int n,q,a[N],b[N],f[N],blo[N],sq,num,ll[N],rr[N],dfn[N],dfm[N],clk,idfn[N];
vector<int>v[N];
int read(){
    int x=0,c,f=1;
    while(!isdigit(c=getchar()))c=='-'?f=-1:0;
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x*f;
}
void dfs(int x){
    dfn[x]=++clk;idfn[clk]=x;
    for(int i=0;i<v[x].size();i++)dfs(v[x][i]);
    dfm[x]=clk;
}
double k(LL y,int x){return x?1.0*y/x:y>0?inf:-inf;}
void cmax(LL &x,LL y){y>x?x=y:0;}
bool cmp(int x,int y){return b[idfn[x]]<b[idfn[y]];}
struct node{
    int a[N],b[N],t[N],st[B][B],tp[B];LL y[N];
    vector<int>v[B];
    void build(int i){
        int *Q=st[i],&R=tp[i];R=0;
        for(int j=0;j<v[i].size();j++){
            int x=v[i][j];assert(!j||b[x]>=b[v[i][j-1]]);
            while(R>1&&k(y[Q[R]]-y[Q[R-1]],b[Q[R]]-b[Q[R-1]])-k(y[x]-y[Q[R]],b[x]-b[Q[R]])<eps)R--;
            Q[++R]=x;
        }
    }
    void init(){
        for(int i=1;i<=num;i++){
            for(int j=ll[i];j<=rr[i];j++)v[i].pb(j),y[j]=1ll*a[j]*b[j];
            sort(v[i].begin(),v[i].end(),cmp);build(i);
        }
    }
    void change(int l,int r,int x){
        for(int i=l;i<=min(r,rr[blo[l]]);i++)a[i]-=x,y[i]=1ll*a[i]*b[i];build(blo[l]);
        if(blo[l]!=blo[r]){for(int i=ll[blo[r]];i<=r;i++)a[i]-=x,y[i]=1ll*a[i]*b[i];build(blo[r]);}
        for(int i=blo[l]+1;i<blo[r];i++)t[i]+=x;
    }
    LL query(int l,int r){
        LL ret=0;
        for(int i=l;i<=min(r,rr[blo[l]]);i++)cmax(ret,1ll*(a[i]-t[blo[l]])*b[i]);
        if(blo[l]!=blo[r])for(int i=ll[blo[r]];i<=r;i++)cmax(ret,1ll*(a[i]-t[blo[r]])*b[i]);
        for(int i=blo[l]+1;i<blo[r];i++){
            int *Q=st[i],&R=tp[i];
            while(R>1&&k(y[Q[R]]-y[Q[R-1]],b[Q[R]]-b[Q[R-1]])<t[i]+eps)R--;
            cmax(ret,1ll*(a[Q[R]]-t[i])*b[Q[R]]);//cout<<a[Q[R]]<<"~"<<b[Q[R]]<<" "<<Q[R]<<endl;
        }
        return ret;
    }
}F,G;
int main(){
    scanf("%d%d",&n,&q);sq=max((int)sqrt(n/6),1);
    for(int i=2;i<=n;i++)v[f[i]=read()].pb(i);dfs(1);
    for(int i=1;i<=n;i++)a[i]=read()+a[f[i]];
    for(int i=1;i<=n;i++)b[i]=read()+b[f[i]];
    // for(int i=1;i<=n;i++)printf("%d %d %d %d\n",a[i],b[i],dfn[i],dfm[i]);
    for(int i=1;i<=n;i++)blo[i]=(i-1)/sq+1;num=blo[n];
    for(int i=1;i<=num;i++)ll[i]=(i-1)*sq+1,rr[i]=i*sq;rr[num]=n;
    for(int i=1;i<=n;i++)F.a[i]=G.a[i]=-a[idfn[i]],F.b[i]=b[idfn[i]],G.b[i]=-b[idfn[i]];
    F.init();for(int i=1;i<=n;i++)b[i]=-b[i];G.init();
    for(int i = 1, op, x, y;i <= q;i++){
        op=read();x=read();
        if(op==1)y=read(),F.change(dfn[x],dfm[x],y),G.change(dfn[x],dfm[x],y);
        else cout<<max(F.query(dfn[x],dfm[x]),G.query(dfn[x],dfm[x]))<<endl;
    }
    return 0;
}