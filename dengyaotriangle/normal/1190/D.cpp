#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
struct node{
    int val,sze,cnk;
    node* c[2];
};

node* nwnode(int v){
    node* nw=new node;
    nw->val=v;nw->sze=nw->cnk=1;nw->c[0]=nw->c[1]=NULL;
    return nw;
}

int gsz(node* rt){
    return rt?rt->sze:0;
}

void pu(node* rt){
    if(rt) rt->sze=gsz(rt->c[0])+rt->cnk+gsz(rt->c[1]);
}

int gcm(node* rt,int k,bool typ){
    if(typ){
        return ((rt->val==k)?-1:(k>rt->val));
    }else{
        return ((gsz(rt->c[0])<=k&&k<gsz(rt->c[0])+rt->cnk)?-1:(gsz(rt->c[0])+rt->cnk<=k));
    }
}

void rot(node*& rt,bool typ){
    node* trg=rt->c[typ];
    rt->c[typ]=trg->c[!typ];
    trg->c[!typ]=rt;
    pu(rt);
    rt=trg;
    pu(rt);
}

void splay(node*& rt,int k,bool typ){
    int d1=gcm(rt,k,typ);
    if(d1!=-1&&rt->c[d1]){
        if(d1&&!typ) k-=gsz(rt->c[0])+rt->cnk;
        int d2=gcm(rt->c[d1],k,typ);
        if(d2!=-1&&rt->c[d1]->c[d2]){
            if(d2&&!typ) k-=gsz(rt->c[d1]->c[0])+rt->c[d1]->cnk; 
            splay(rt->c[d1]->c[d2],k,typ);
            if(d1==d2){
                rot(rt,d1);rot(rt,d2);
            }else{
                rot(rt->c[d1],d2);rot(rt,d1);
            }
        }else{
            rot(rt,d1);
        }
    }
}

int rnk(node*& rt,int k){
    splay(rt,k,1);
    return gsz(rt->c[0]);
}

int kth(node*& rt,int k){
    splay(rt,k,0);
    return rt->val;
}

int prv(node*& rt,int k){
    node* u=rt;
    int ans=0x80000000;
    while(u){
        if(u->val<k){
            ans=max(ans,u->val);
            u=u->c[1];
        }else{
            u=u->c[0];
        }
    }
    splay(rt,ans,1);
    return ans;
}

int nxt(node*& rt,int k){
    node* u=rt;
    int ans=0x7fffffff;
    while(u){
        if(u->val>k){
            ans=min(ans,u->val);
            u=u->c[0];
        }else{
            u=u->c[1];
        }
    }
    splay(rt,ans,1);
    return ans;
}

void ins(node*& rt,int k){
    if(!rt) rt=nwnode(k);
    else if(gcm(rt,k,1)==-1) rt->cnk++;
    else ins(rt->c[gcm(rt,k,1)],k);
    pu(rt);
}

void del(node*& rt,int k){
    splay(rt,k,1);
    if(rt->val!=k) return;
    rt->cnk--;
    pu(rt);
    if(rt->cnk==0){
        if(!rt->c[0]) rt=rt->c[1];
        else{
            splay(rt->c[0],k,1);
            rt->c[0]->c[1]=rt->c[1];
            rt=rt->c[0];
        }
    }
}

void del(node* rt){
    if(!rt) return;
    del(rt->c[0]);
    del(rt->c[1]);
    delete rt;
}
struct poi{
    int x,y;
};

poi p[maxn];
node *s1=NULL,*s2=NULL;
int n;

bool cmp(poi a,poi b){
    return a.y>b.y;
}
int main(){
    long long cnt=0;
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
        //p[i].x=i;p[i].y=1;
    }
    sort(p+1,p+1+n,cmp);
    p[n+1].y=-1;
    int cp=1;
    ins(s1,-1);
    ins(s1,1000000009);
    int sz1=0,sz2=0;
    while(1){
        //cerr<<1;
        bool cc=0;
        del(s2);
        sz2=0;
        s2=NULL;
        ins(s2,-1);
        ins(s2,1000000009);
        int sz3=0;
        for(int i=cp;i<=n+1;i++){
            //if(i>n-100)cerr<<i<<endl;
            cp=i;
            if(cc&&p[i].y!=p[i-1].y) break;
            if(nxt(s2,p[i].x-1)!=p[i].x){
                ins(s2,p[i].x);
                splay(s2,p[i].x,1);
                sz2++;
                if(nxt(s1,p[i].x-1)==p[i].x)sz3--;
                splay(s1,p[i].x-1,1);
            }
            splay(s2,p[i].x-1,1);
            cc=1;
        }
        long long cad=sz1+sz2+sz3;
        long long cur=(cad*(cad+1))/2;
        int ps=1;
        for(int i=1;i<=sz2;i++){
            int c=kth(s2,i);
            splay(s2,i,1);
            int p1=rnk(s1,prv(s1,c)),p2=rnk(s1,nxt(s1,c));
            splay(s1,c,1);
            long long len=(p1-ps+1);
            cur-=(len*(len+1))/2;
            ps=p2;
        }
        
        long long len=sz1-ps+1;
        cur-=(len*(len+1))/2;
        cnt+=cur;
        for(int i=1;i<=sz2;i++){
            long long cpt=kth(s2,i);
            splay(s2,i,1);
            if(nxt(s1,cpt-1)!=cpt){
                ins(s1,cpt);
                splay(s1,cpt,1);
                sz1++;
            }
        }
        if(cp==n+1) break;
    }
    cout<<cnt;
    return 0;
}