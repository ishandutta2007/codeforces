#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;
const int maxl=20;

int n,q;

struct node{
    node *c[2];
    int sze;bool typ;
    unsigned tg,ta,to;
}pool[(unsigned long)(maxn*maxl*1.2)];int ps;

node *nwnode(int typ){
    node *nw=pool+ps++;
    nw->sze=nw->typ=typ;nw->ta=-1;
    return nw;
}
void pd(node *rt){
    if(rt&&rt->tg){
        unsigned an=(rt->ta&~rt->tg)|(~rt->to&rt->tg);
        unsigned on=(rt->to&~rt->tg)|(~rt->ta&rt->tg);
        rt->ta=an;rt->to=on;
        if(rt->tg&1)swap(rt->c[0],rt->c[1]);
        if(rt->c[0])rt->c[0]->tg^=rt->tg>>1;
        if(rt->c[1])rt->c[1]->tg^=rt->tg>>1;
        rt->tg=0;
    }
}
void pu(node *rt){
    rt->sze=(rt->c[0]?rt->c[0]->sze:0)+(rt->c[1]?rt->c[1]->sze:0)+rt->typ;
    rt->ta=(rt->c[0]?rt->c[0]->ta<<1:(-1))&(rt->c[1]?rt->c[1]->ta<<1|1:(-1));
    rt->to=(rt->c[0]?rt->c[0]->to<<1:0)|(rt->c[1]?rt->c[1]->to<<1|1:0);
}
node *rt;

node *mrg(node *a,node *b){
    pd(a);pd(b);
    if(!a)return b;
    if(!b)return a;
    a->c[0]=mrg(a->c[0],b->c[0]);
    a->c[1]=mrg(a->c[1],b->c[1]);
    a->typ|=b->typ;
    pu(a);
    return a;
}
void setp(node *rt,int k,int v){
    if(!rt)return;
    pd(rt);
    if(rt->ta>>k&1){
        if(v==0){rt->tg^=1<<k;pd(rt);}
    }else if(~rt->to>>k&1){
        if(v==1){rt->tg^=1<<k;pd(rt);}
    }else if(k==0){
        rt->c[v]=mrg(rt->c[0],rt->c[1]);
        rt->c[!v]=nullptr;
        pu(rt);
    }else{
        setp(rt->c[0],k-1,v);
        setp(rt->c[1],k-1,v);
        pu(rt);
    }
}
vector<pair<pair<int,int>,node*> > iv;

void insl(node *&rt,int rv,int x,node *pt){
    if(!rt)rt=nwnode(0);
    pd(rt);
    if(rv<0){
        rt=mrg(rt,pt);
    }else{
        int dir=(x>>rv)&1;
        insl(rt->c[dir],rv-1,x,pt);
        pd(rt->c[!dir]);pu(rt);
    }
}
void finins(){
    for(auto x:iv)insl(rt,maxl-x.first.first-1,x.first.second,x.second);
    iv.clear();
}
void chgx(node *&rt,int rv,int cz,int l,int r,int v){
    if(!rt)return;
    pd(rt);
    if(l==0&&r==1<<cz){
        rt->tg^=v;
        iv.push_back({{cz,rv},rt});
        rt=nullptr;
    }else if(r<=1<<cz>>1){
        chgx(rt->c[0],rv<<1|(v&1),cz-1,l,r,v>>1);
        pd(rt->c[1]);pu(rt);
    }else if(l>=1<<cz>>1){
        chgx(rt->c[1],rv<<1|(~v&1),cz-1,l-(1<<cz>>1),r-(1<<cz>>1),v>>1);
        pd(rt->c[0]);
        pu(rt);
    }else{
        chgx(rt->c[0],rv<<1|(v&1),cz-1,l,1<<cz>>1,v>>1);
        chgx(rt->c[1],rv<<1|(~v&1),cz-1,0,r-(1<<cz>>1),v>>1);
        pu(rt);
    }
}

void chga(node *&rt,int rv,int cz,int l,int r,int v){
    if(!rt)return;
    pd(rt);
    if(l==0&&r==1<<cz){
        for(int i=0;i<cz;i++)if(~v>>i&1)setp(rt,i,0);
        iv.push_back({{cz,rv},rt});
        rt=nullptr;
    }else if(r<=1<<cz>>1){
        chga(rt->c[0],rv<<1,cz-1,l,r,v>>1);
        pd(rt->c[1]);pu(rt);
    }else if(l>=1<<cz>>1){
        chga(rt->c[1],rv<<1|(v&1),cz-1,l-(1<<cz>>1),r-(1<<cz>>1),v>>1);
        pd(rt->c[0]);pu(rt);
    }else{
        chga(rt->c[0],rv<<1,cz-1,l,1<<cz>>1,v>>1);
        chga(rt->c[1],rv<<1|(v&1),cz-1,0,r-(1<<cz>>1),v>>1);
        pu(rt);
    }
}
void chgo(node *&rt,int rv,int cz,int l,int r,int v){
    if(!rt)return;
    pd(rt);
    if(l==0&&r==1<<cz){
        for(int i=0;i<cz;i++)if(v>>i&1)setp(rt,i,1);
        iv.push_back({{cz,rv},rt});
        rt=nullptr;
    }else if(r<=1<<cz>>1){
        chgo(rt->c[0],rv<<1|(v&1),cz-1,l,r,v>>1);
        pd(rt->c[1]);pu(rt);
    }else if(l>=1<<cz>>1){
        chgo(rt->c[1],rv<<1|1,cz-1,l-(1<<cz>>1),r-(1<<cz>>1),v>>1);
        pd(rt->c[0]);pu(rt);
    }else{
        chgo(rt->c[0],rv<<1|(v&1),cz-1,l,1<<cz>>1,v>>1);
        chgo(rt->c[1],rv<<1|1,cz-1,0,r-(1<<cz>>1),v>>1);
        pu(rt);
    }
}
int qry(node *rt,int cz,int l,int r){
    if(!rt)return 0;
    pd(rt);
    if(l==0&&r==1<<cz){
        return rt->sze;
    }else if(r<=1<<cz>>1){
        return qry(rt->c[0],cz-1,l,r);
    }else if(l>=1<<cz>>1){
        return qry(rt->c[1],cz-1,l-(1<<cz>>1),r-(1<<cz>>1));
    }else{
        return qry(rt->c[0],cz-1,l,1<<cz>>1)+qry(rt->c[1],cz-1,0,r-(1<<cz>>1));
    }
}
void ins(node*&rt,int cz,int v){
    if(cz>0){
        if(!rt)rt=nwnode(0);
        ins(rt->c[v&1],cz-1,v>>1);
        pu(rt);
    }else if(!rt)rt=nwnode(1);
}
void dfs(node *rt,int v,int p){
    if(!rt)return;
    for(int i=0;i<v;i++)cerr<<"-";
    cerr<<"("<<p<<")";
    cerr<<rt->sze<<' '<<rt->tg<<' '<<rt->ta<<' '<<rt->to<<endl;
    dfs(rt->c[0],v+1,p<<1);
    dfs(rt->c[1],v+1,p<<1|1);
}
int brev(int x){
    int u=0;
    for(int i=0;i<maxl;i++,x>>=1)u=u<<1|(x&1);
    return u;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        ins(rt,maxl,brev(a));
        //dfs(rt,0,0);cerr<<endl;
    }
    while(q--){
        int op,l,r,x;
        cin>>op>>l>>r;
        if(op!=4)cin>>x;
        if(op==1){
            chga(rt,0,maxl,l,r+1,brev(x));
            finins();
        }else if(op==2){
            chgo(rt,0,maxl,l,r+1,brev(x));
            finins();
        }else if(op==3){
            chgx(rt,0,maxl,l,r+1,brev(x));
            finins();
        }else{
            cout<<qry(rt,maxl,l,r+1)<<'\n';
        }
        //dfs(rt,0,0);cerr<<endl;
    }
    return 0;
}