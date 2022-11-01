#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegTree{
    int sz;
    vector<int> dat;

    SegTree(int _sz){
        sz=1;while(sz<_sz)sz<<=1;
        dat.resize(sz<<1,-1);
    }

    void upd(int pos,int val){
        pos+=sz-1;
        dat[pos]=val;
        while(pos>1){
            pos>>=1;
            dat[pos]=max(dat[pos<<1],dat[pos<<1|1]);
        }
    }

    int qry(int id,int l,int r,int ql,int qr){
        if(qr<l||r<ql)return -1;
        if(ql<=l&&r<=qr)return dat[id];
        return max(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    int qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
};

int n,a[50005],x,pos[50005];
ll pre[50005];
vector<ll> vx;

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>x;
    vx.assign(1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i]-x;
        vx.emplace_back(pre[i]);
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    SegTree st(vx.size());
    vector<pair<int,int>> v;
    for(int i=0;i<=n;i++){
        pos[i]=upper_bound(vx.begin(),vx.end(),pre[i])-vx.begin();
        if(i>1){
            int q=st.qry(pos[i]+1,vx.size());
            if(q!=-1){
                v.emplace_back(q+1,i);
            }
        }
        if(i>=1)st.upd(pos[i-1],i-1);
    }
    int rm=-1,ans=n;
    for(auto &[l,r]:v)if(l>rm){
        ans--;
        rm=r;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}