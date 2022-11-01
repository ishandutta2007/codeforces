#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegTree{
    int sz;
    vector<int> dat,laz;
    SegTree(const int& _sz){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        laz.resize(sz<<1);
    }
    void pushdown(const int& id){
        laz[id<<1]=max(laz[id<<1],laz[id]);
        dat[id<<1]=max(dat[id<<1],laz[id]);
        laz[id<<1|1]=max(laz[id<<1|1],laz[id]);
        dat[id<<1|1]=max(dat[id<<1|1],laz[id]);
    }
    int upd(const int& id,const int& l,const int& r,const int& ql,const int& qr,const int& val){
        if(qr<l||r<ql)return 1e9;
        if(ql<=l&&r<=qr){
            int res=dat[id];
            laz[id]=max(laz[id],val);
            dat[id]=max(dat[id],val);
            return res;
        }
        pushdown(id);
        int res=min(upd(id<<1,l,l+r>>1,ql,qr,val),upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val));
        dat[id]=min(dat[id<<1],dat[id<<1|1]);
        return res;
    }
    int upd(const int& l,const int& r,const int& v){
        return upd(1,1,sz,l,r,v);
    }
};

int n,vx,vy,a[1005][1005];
vector<ll> prjv;
inline ll proj(const int& i,const int& j){return (ll)j*vx-(ll)i*vy;}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>vx>>vy;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)prjv.emplace_back(proj(i,j));
    for(int i=0;i<n;i++)prjv.emplace_back(proj(i,n));
    for(int i=0;i<=n;i++)prjv.emplace_back(proj(n,i));
    sort(prjv.begin(),prjv.end());
    prjv.erase(unique(prjv.begin(),prjv.end()),prjv.end());
    int is=(vx<0)*(n-1),it=(vx>=0)*(n+1)-1,id=(vx>=0)-(vx<0);
    int js=(vy<0)*(n-1),jt=(vy>=0)*(n+1)-1,jd=(vy>=0)-(vy<0);
    ll ans=0;
    SegTree tree(prjv.size());
    for(int i=is;i!=it;i+=id)for(int j=js;j!=jt;j+=jd){
        static ll dl,dr,ul,ur;
        dl=proj(i,j);
        dr=proj(i+1,j);
        ul=proj(i,j+1);
        ur=proj(i+1,j+1);
        static ll plb,prb;
        plb=min(min(dl,dr),min(ul,ur));
        prb=max(max(dl,dr),max(ul,ur));
        int lb=upper_bound(prjv.begin(),prjv.end(),plb)-prjv.begin();
        int rb=upper_bound(prjv.begin(),prjv.end(),prb)-prjv.begin();
        ans+=max(0,a[i][j]-tree.upd(lb,rb-1,a[i][j]));
    }
    cout<<ans<<endl;

    return 0;
}