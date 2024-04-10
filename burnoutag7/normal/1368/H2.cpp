#include<bits/stdc++.h>
using namespace std;

struct segtreesum{
    int sz;
    vector<int> dat,laz;

    void build(char *a,int n,int id,int l,int r){
        if(l==r){
            if(l<=n){
                dat[id]=a[l]=='R';
            }
            return;
        }
        build(a,n,id<<1,l,l+r>>1);
        build(a,n,id<<1|1,(l+r>>1)+1,r);
        dat[id]=dat[id<<1]+dat[id<<1|1];
    }

    segtreesum(char *a,int _sz){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        laz.resize(sz<<1);
        build(a,_sz,1,1,sz);
    }

    void upd(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            laz[id]^=1;
            dat[id]=r-l+1-dat[id];
            return;
        }
        if(laz[id]){
            laz[id<<1]^=1;
            dat[id<<1]=(r-l+1>>1)-dat[id<<1];
            laz[id<<1|1]^=1;
            dat[id<<1|1]=(r-l+1>>1)-dat[id<<1|1];
            laz[id]=0;
        }
        upd(id<<1,l,l+r>>1,ql,qr);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr);
        dat[id]=dat[id<<1]+dat[id<<1|1];
    }

    void rev(int l,int r){
        upd(1,1,sz,l,r);
    }

    int qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        if(laz[id]){
            laz[id<<1]^=1;
            dat[id<<1]=(r-l+1>>1)-dat[id<<1];
            laz[id<<1|1]^=1;
            dat[id<<1|1]=(r-l+1>>1)-dat[id<<1|1];
            laz[id]=0;
        }
        return qry(id<<1,l,l+r>>1,ql,qr)+qry(id<<1|1,(l+r>>1)+1,r,ql,qr);
    }

    int sum(int l,int r){
        return qry(1,1,sz,l,r);
    }
};

const int inf=1e9;

struct dpnode{
    int wid,dat[1<<4];
    dpnode(int _wid=0){
        wid=_wid;
        for(int rev=0;rev<4;rev++){
            for(int st=0;st<2;st++){
                dat[rev<<2|st<<1|st]=0;
                dat[rev<<2|st<<1|st^1]=inf;
            }
        }
    }
    dpnode(int _wid,int lb,int rb){
        wid=_wid;
        for(int revl=0;revl<2;revl++)for(int revr=0;revr<2;revr++){
            for(int st=0;st<2;st++){
                dat[revl<<3|revr<<2|st<<1|st]=((lb^revl)!=st)+((rb^revr)!=st);
                dat[revl<<3|revr<<2|st<<1|st^1]=inf;
            }
        }
    }
    void revl(){
        for(int i=0;i<8;i++)swap(dat[i],dat[i^1<<3]);
    }
    void revr(){
        for(int i=0;i<16;i++)if(i>>2&1)swap(dat[i],dat[i^1<<2]);
    }
    dpnode operator+(const dpnode &a)const{
        dpnode res(max(wid,a.wid));
        fill(res.dat,res.dat+16,inf);
        for(int rev=0;rev<4;rev++){
            for(int st=0;st<2;st++)for(int ed=0;ed<2;ed++){
                for(int mid=0;mid<2;mid++){
                    res.dat[rev<<2|st<<1|ed]=min(res.dat[rev<<2|st<<1|ed],dat[rev<<2|st<<1|mid]+a.dat[rev<<2|mid<<1|ed]);
                    res.dat[rev<<2|st<<1|ed]=min(res.dat[rev<<2|st<<1|ed],dat[rev<<2|st<<1|mid^1]+a.dat[rev<<2|mid<<1|ed]+res.wid);
                }
            }
        }
        return res;
    }
};

struct segtreedp{
    int sz,wid;
    vector<dpnode> dat;
    vector<int> tagl,tagr;

    void build(char *a,char *b,int n,int id,int l,int r){
        if(l==r){
            if(l<=n){
                dat[id]=dpnode(wid,a[l]=='R',b[l]=='R');
            }
            return;
        }
        build(a,b,n,id<<1,l,l+r>>1);
        build(a,b,n,id<<1|1,(l+r>>1)+1,r);
        dat[id]=dat[id<<1]+dat[id<<1|1];
    }

    segtreedp(char *a,char *b,int _sz,int _wid){
        wid=_wid;
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1,wid);
        tagl.resize(sz<<1);
        tagr.resize(sz<<1);
        build(a,b,_sz,1,1,sz);
    }

    template<bool rit> void upd(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            if constexpr(rit){
                dat[id].revr();
                tagr[id]^=1;
            }else{
                dat[id].revl();
                tagl[id]^=1;
            }
            return;
        }
        if(tagl[id]){
            tagl[id<<1]^=1;
            dat[id<<1].revl();
            tagl[id<<1|1]^=1;
            dat[id<<1|1].revl();
            tagl[id]=0;
        }
        if(tagr[id]){
            tagr[id<<1]^=1;
            dat[id<<1].revr();
            tagr[id<<1|1]^=1;
            dat[id<<1|1].revr();
            tagr[id]=0;
        }
        upd<rit>(id<<1,l,l+r>>1,ql,qr);
        upd<rit>(id<<1|1,(l+r>>1)+1,r,ql,qr);
        dat[id]=dat[id<<1]+dat[id<<1|1];
    }

    dpnode qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return dpnode(wid);
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        if(tagl[id]){
            tagl[id<<1]^=1;
            dat[id<<1].revl();
            tagl[id<<1|1]^=1;
            dat[id<<1|1].revl();
            tagl[id]=0;
        }
        if(tagr[id]){
            tagr[id<<1]^=1;
            dat[id<<1].revr();
            tagr[id<<1|1]^=1;
            dat[id<<1|1].revr();
            tagr[id]=0;
        }
        return qry(id<<1,l,l+r>>1,ql,qr)+qry(id<<1|1,(l+r>>1)+1,r,ql,qr);
    }

    void revl(int l,int r){
        upd<0>(1,1,sz,l,r);
    }

    void revr(int l,int r){
        upd<1>(1,1,sz,l,r);
    }

    array<array<int,2>,2> ask(int l,int r){
        array<array<int,2>,2> res;
        auto dp=qry(1,1,sz,l,r);
        for(int i=0;i<2;i++)for(int j=0;j<2;j++){
            res[i][j]=dp.dat[i<<1|j];
        }
        return res;
    }
};

int n,m,q;
char buf1[500005],buf2[500005];

int deal(segtreesum &st,segtreesum &ed,segtreedp &dp,int len,int wid){
    int res=inf,sts=st.sum(1,wid),eds=ed.sum(1,wid);
    array<array<int,2>,2> f=dp.ask(1,len);
    for(int i=0;i<2;i++)for(int j=0;j<2;j++){
        res=min(res,(i?wid-sts:sts)+(j?wid-eds:eds)+f[i][j]);
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    cin>>buf1+1;
    segtreesum lsum(buf1,n);
    cin>>buf2+1;
    segtreesum rsum(buf2,n);
    segtreedp ver(buf1,buf2,n,m);
    cin>>buf1+1;
    segtreesum usum(buf1,m);
    cin>>buf2+1;
    segtreesum dsum(buf2,m);
    segtreedp hor(buf1,buf2,m,n);
    cout<<min(deal(lsum,rsum,hor,m,n),deal(usum,dsum,ver,n,m))<<'\n';
    while(q--){
        char op;
        int l,r;
        cin>>op>>l>>r;
        switch(op){
        case 'L':
            lsum.rev(l,r);
            ver.revl(l,r);
            break;
        case 'R':
            rsum.rev(l,r);
            ver.revr(l,r);
            break;
        case 'U':
            usum.rev(l,r);
            hor.revl(l,r);
            break;
        case 'D':
            dsum.rev(l,r);
            hor.revr(l,r);
            break;
        default:
            break;
        }
        cout<<min(deal(lsum,rsum,hor,m,n),deal(usum,dsum,ver,n,m))<<'\n';
    }

    return 0;
}