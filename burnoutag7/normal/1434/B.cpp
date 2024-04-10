#include<bits/stdc++.h>
using namespace std;

inline void NO(){
    cout<<"NO\n";
    exit(0);
}

struct SegTree{
    int sz;
    vector<int> dat,laz;

    SegTree(const int &_sz){
        sz=1;while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        laz.resize(sz<<1);
    }

    void upd(const int &id,const int &l,const int &r,const int &ql,const int &qr,const int &val){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            laz[id]=max(laz[id],val);
            dat[id]=max(dat[id],laz[id]);
            return;
        }
        laz[id<<1]=max(laz[id<<1],laz[id]);
        dat[id<<1]=max(dat[id<<1],laz[id<<1]);
        laz[id<<1|1]=max(laz[id<<1|1],laz[id]);
        dat[id<<1|1]=max(dat[id<<1|1],laz[id<<1|1]);
        upd(id<<1,l,l+r>>1,ql,qr,val);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val);
        dat[id]=max(dat[id<<1],dat[id<<1|1]);
    }

    int qry(const int &id,const int &l,const int &r,const int &ql,const int &qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        laz[id<<1]=max(laz[id<<1],laz[id]);
        dat[id<<1]=max(dat[id<<1],laz[id<<1]);
        laz[id<<1|1]=max(laz[id<<1|1],laz[id]);
        dat[id<<1|1]=max(dat[id<<1|1],laz[id<<1|1]);
        return max(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    void upd(const int &l,const int &r,const int &v){
        upd(1,1,sz,l,r,v);
    }

    int qry(const int &l,const int &r){
        return qry(1,1,sz,l,r);
    }

    int qry(const int &p){
        return qry(1,1,sz,p,p);
    }
};

struct BIT{
    int sz;
    vector<int> bit;

    BIT(const int &_sz){
        sz=_sz;
        bit.resize(sz+1);
    }

    int sum(int pos){
        int res=0;
        while(pos>0){
            res+=bit[pos];
            pos-=pos&-pos;
        }
        return res;
    }

    void add(int pos,int val){
        while(pos<=sz){
            bit[pos]+=val;
            pos+=pos&-pos;
        }
    }
};

int n,p,res[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    SegTree index(n);
    BIT occ(n);
    for(int i=1;i<=n<<1;i++){
        static char typ;
        cin>>typ;
        if(typ=='+')p++;
        else{
            static int x;
            cin>>x;
            int l=1,r=p,m,cp=-1;
            while(l<=r){
                m=l+r>>1;
                if(index.qry(m)>x){
                    l=m+1;
                }else{
                    r=m-1;
                    cp=m;
                }
            }
            if(cp==-1)NO();
            int lb=cp;
            l=lb,r=p,cp=-1;
            while(l<=r){
                m=l+r>>1;
                if(occ.sum(m)-occ.sum(lb-1)==m-lb+1){
                    l=m+1;
                }else{
                    r=m-1;
                    cp=m;
                }
            }
            if(cp==-1)NO();
            res[cp]=x;
            occ.add(cp,1);
            index.upd(1,p,x);
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)cout<<res[i]<<' ';

    return 0;
}