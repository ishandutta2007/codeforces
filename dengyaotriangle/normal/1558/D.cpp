#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=600005;
const int mdn=998244353;

inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}


int n,m;
int fac[maxn],ifac[maxn];

struct node{
    int sze,cnt,rnd,sze0;
    node*c[2];
};

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
node pool[maxn*3];int ps;
node* nwnode(int x){
    node* nw=pool+ps++;
    nw->c[0]=nw->c[1]=NULL;nw->sze=nw->cnt=x;nw->rnd=rng();nw->sze0=1;
    return nw;
}
void pu(node* rt){
    if(rt){
        rt->sze=rt->cnt+(rt->c[0]?rt->c[0]->sze:0)+(rt->c[1]?rt->c[1]->sze:0);
        rt->sze0=1+(rt->c[0]?rt->c[0]->sze0:0)+(rt->c[1]?rt->c[1]->sze0:0);
    }
}

void spl(node* rt,int k,node*&a,node*&b){
    if(!rt){a=b=NULL;}
    else{
        int szl=(rt->c[0]?rt->c[0]->sze:0)+rt->cnt;
        if(k<szl){
            b=rt;spl(rt->c[0],k,a,b->c[0]);pu(b);
        }else{
            a=rt;spl(rt->c[1],k-szl,a->c[1],b);pu(a);
        }
    }
}
void spk(node* rt,int k,node*&a,node*&b){
    if(!rt){a=b=NULL;}
    else{
        int szl=(rt->c[0]?rt->c[0]->sze0:0);
        if(k<=szl){
            b=rt;spk(rt->c[0],k,a,b->c[0]);pu(b);
        }else{
            a=rt;spk(rt->c[1],k-szl-1,a->c[1],b);pu(a);
        }
    }
}
node* mrg(node*l,node*r){
    if(!l||!r)return l?:r;
    if(l->rnd>r->rnd){
        l->c[1]=mrg(l->c[1],r);pu(l);return l;
    }else{
        r->c[0]=mrg(l,r->c[0]);pu(r);return r;
    }
}

int main(){
    fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*(long long)i%mdn;
    ifac[maxn-1]=qpw(fac[maxn-1],mdn-2);
    for(int i=maxn-1;i>0;i--)ifac[i-1]=ifac[i]*(long long)i%mdn;
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ps=0;
        node* rt=nwnode(1);
        int lp=1;
        for(int i=1;i<=m;i++){
            int x,y;cin>>x>>y;
            int dif=x-lp-1;
            if(dif!=0){
                node *a,*b;spk(rt,rt->sze0-1,a,b);
                b->cnt+=dif;pu(b);
                rt=mrg(a,b);
            }
            node *a,*b;
            spl(rt,y-1,a,b);
            int u=a?a->sze:0;
            if(u!=y-1){
                node *c,*d;spk(b,1,c,d);
                int ls=y-u,rs=c->cnt-ls+1;
                rt=mrg(mrg(a,nwnode(ls)),mrg(nwnode(rs),d));
            }else{
                if(u==0){
                    rt=mrg(nwnode(1),b);
                }else{
                    node *c,*d;
                    spk(a,a->sze0-1,c,d);
                    d->cnt++;pu(d);
                    rt=mrg(mrg(c,d),b);
                }
            }
            lp=x;
        }
        int ans=n-rt->sze0;
        cout<<fac[n+ans]*(long long)ifac[ans]%mdn*ifac[n]%mdn<<'\n';
    }
    return 0;
}