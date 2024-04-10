#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=400005;
const int maxp=62;
const long long mdn=1000000007;

vector<int> prm;
struct node{
    node* c[2];
    int l,r;
    long long v,tg;
    long long v2,tg2;
};
node* nwnode(int l,int r){
    node* nw=new node;
    nw->l=l;nw->r=r;nw->c[0]=nw->c[1]=NULL;
    nw->v=nw->v2=nw->tg2=0;nw->tg=1;
    return nw;
}

long long ksm(long long bse,long long ex){
    if(ex==0)return 1;
    long long ans=ksm(bse,ex>>1);ans=(ans*ans)%mdn;
    if(ex&1)ans=(ans*bse)%mdn;
    return ans;
}
void pd(node* rt){
    if(!rt)return;
    if(rt->tg!=1){
        rt->v=(rt->v*ksm(rt->tg,rt->r-rt->l+1))%mdn;
        if(rt->l!=rt->r){
            rt->c[0]->tg=(rt->c[0]->tg*rt->tg)%mdn;
            rt->c[1]->tg=(rt->c[1]->tg*rt->tg)%mdn;
        }
        rt->tg=1;
    }
    if(rt->tg2){
        rt->v2|=rt->tg2;
        if(rt->l!=rt->r){
            rt->c[0]->tg2|=rt->tg2;
            rt->c[1]->tg2|=rt->tg2;
        }
        rt->tg2=0;
    }
}
void pu(node* rt){
    if(rt->l!=rt->r){
        rt->v=(rt->c[0]->v*rt->c[1]->v)%mdn;
        rt->v2=rt->c[0]->v2|rt->c[1]->v2;
    }
}
void chg(node* rt,int l,int r,node op){
    int cl=rt->l,cr=rt->r,cm=(cl+cr)>>1;
    pd(rt);
    if(cl==l&&cr==r){
        rt->tg=(rt->tg*op.v)%mdn;
        rt->tg2|=op.v2;
        pd(rt);
    }else if(r<=cm)chg(rt->c[0],l,r,op);
    else if(l>cm)chg(rt->c[1],l,r,op);
    else {
        chg(rt->c[0],l,cm,op);chg(rt->c[1],cm+1,r,op);
    }
    pd(rt->c[0]);pd(rt->c[1]);pu(rt);
}

node qry(node* rt,int l,int r){
    int cl=rt->l,cr=rt->r,cm=(cl+cr)>>1;
    pd(rt);
    if(cl==l&&cr==r){
        return (*rt);
    }else if(r<=cm)return qry(rt->c[0],l,r);
    else if(l>cm)return qry(rt->c[1],l,r);
    else {
        node r1=qry(rt->c[0],l,cm),r2=qry(rt->c[1],cm+1,r),r3;
        r3.l=-1;r3.r=1;r3.c[0]=(&r1);r3.c[1]=(&r2);pu(&r3);
        return r3;
    }
}

int n;
int a[maxn];

node* bt(int l,int r){
    node* nw=nwnode(l,r);
    if(l==r){
        nw->v=a[l];
        for(int i=0;i<maxp;i++){
            while(a[l]%prm[i]==0){
                nw->v2|=(1ll<<i);
                a[l]/=prm[i];
            }
        }
    }else{
        nw->c[0]=bt(l,(l+r)>>1);
        nw->c[1]=bt(((l+r)>>1)+1,r);
        pu(nw);
    }
    return nw;
}

long long inv[maxp];

int main(){
    for(int i=2;i<302;i++){
        bool ok=1;for(int j=2;j*j<=i;j++)if(i%j==0)ok=0;
        if(ok)prm.push_back(i);
    }
    for(int i=0;i<maxp;i++)inv[i]=ksm(prm[i],mdn-2);
    ios::sync_with_stdio(0);
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    node* rt=bt(1,n);
    while(q--){
        char op[12];
        cin>>op;
        node cg,a;
        long long ans=1;
        int l,r,v;
        switch(op[0]){
            case 'T':
                cin>>l>>r;
                a=qry(rt,l,r);
                ans=a.v;
                for(int j=0;j<maxp;j++){
                    if((a.v2>>j)&1){
                        ans=(ans*(1-inv[j]+mdn))%mdn;
                    }
                }
                cout<<ans<<'\n';
                break;
            case 'M':
                cin>>l>>r>>v;
                cg.v=v;cg.v2=0;
                for(int j=0;j<maxp;j++){
                    while(v%prm[j]==0){
                        v/=prm[j];
                        cg.v2|=(1ll<<j);
                    }
                }
                chg(rt,l,r,cg);
                break;
        }
    }
    return 0;
}