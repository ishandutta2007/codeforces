#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

struct SegTree{
    int sz;
    vector<int> dat,mul,len,sub;
    vector<bool> tag;

    SegTree(int _sz,const vector<int> &a){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        mul.resize(sz<<1);
        len.resize(sz<<1);
        sub.resize(sz<<1,mod-1);
        tag.resize(sz<<1);
        for(int i=sz;i<sz*2;i++)len[i]=(i-sz+1<a.size()?(a[i-sz+1]-a[i-sz])%mod:0);
        for(int i=sz-1;i>=1;i--)len[i]=(len[i<<1]+len[i<<1|1])%mod;
    }

    void set(int id,int val,int isb){
        dat[id]=((ll)val*len[id]-(ll)isb*dat[id]%mod+mod)%mod;
        mul[id]=(val-(ll)isb*mul[id]%mod+mod)%mod;
        sub[id]=(mod-(ll)sub[id]*isb%mod)%mod;
        tag[id]=1;
    }

    void upd(int id,int l,int r,int ql,int qr,int val,bool isb){
        if(qr<l||r<ql)return;
        if(ql<=l&&r<=qr){
            set(id,val,isb);
            return;
        }
        if(tag[id]){
            tag[id]=0;
            set(id<<1,mul[id],sub[id]);
            set(id<<1|1,mul[id],sub[id]);
            mul[id]=0;
            sub[id]=mod-1;
        }
        upd(id<<1,l,l+r>>1,ql,qr,val,isb);
        upd(id<<1|1,(l+r>>1)+1,r,ql,qr,val,isb);
        dat[id]=(dat[id<<1]+dat[id<<1|1])%mod;
    }

    void upd(int l,int r,int val,bool isb){
        upd(1,1,sz,l,r,val,isb);
    }

    int qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr){
            return dat[id];
        }
        if(tag[id]){
            tag[id]=0;
            set(id<<1,mul[id],sub[id]);
            set(id<<1|1,mul[id],sub[id]);
        }
        return (qry(id<<1,l,l+r>>1,ql,qr)+qry(id<<1|1,(l+r>>1)+1,r,ql,qr))%mod;
    }

    int qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
};

int n,m,a[200005];
vector<int> vx(1,0);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vx.emplace_back(a[i]);
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    m=vx.size()-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(vx.begin(),vx.end(),a[i])-vx.begin();
    SegTree s(m,vx);
    s.upd(1,a[1],1,1);
    for(int i=2;i<=n;i++){
        int sum=s.dat[1];
        s.upd(1,a[i],sum,1);
        s.upd(a[i]+1,m,0,0);
    }
    cout<<s.dat[1];

    return 0;
}