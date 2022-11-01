#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    int sz;
    vector<int> dat;

    SegTree(int _sz=1){
        sz=1;while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
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
        if(qr<l||r<ql)return 0;
        if(ql<=l&&r<=qr)return dat[id];
        return max(qry(id<<1,l,l+r>>1,ql,qr),qry(id<<1|1,(l+r>>1)+1,r,ql,qr));
    }

    int qry(int l,int r){
        return qry(1,1,sz,l,r);
    }
}segx,segy;

int n,m,V;
set<pair<int,int>> tph,thp;

void plant(int p,int h){
    vector<pair<int,int>> v;
    for(auto it=thp.begin();it!=thp.end()&&it->first<h;it++){
        v.emplace_back(it->second,it->first);
    }
    thp.emplace(h,p);
    tph.emplace(p,h);
    v.emplace_back(p,h);
    reverse(v.begin(),v.end());
    for(auto p:v){
        segx.upd(p.first,0);
    }
    for(auto p:v){
        int lis=segx.qry(p.first+1,n)+1;
        segx.upd(p.first,lis);
        segy.upd(p.second,lis);
    }
}

void cutdown(int id){
    vector<pair<int,int>> v;
    for(auto it=tph.begin();id--;it++){
        if(id)v.emplace_back(it->first,it->second);
        else{
            thp.erase(make_pair(it->second,it->first));
            segx.upd(it->first,0);
            segy.upd(it->second,0);
            tph.erase(it);
        }
    }
    reverse(v.begin(),v.end());
    for(auto p:v){
        segy.upd(p.second,0);
    }
    for(auto p:v){
        int lis=segy.qry(p.second+1,V)+1;
        segx.upd(p.first,lis);
        segy.upd(p.second,lis);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    segx=SegTree(n);
    segy=SegTree(V=m+10);
    while(m--){
        int typ,x,y;
        cin>>typ>>x;
        if(typ==1){
            cin>>y;
            plant(x,y+m);
        }else{
            cutdown(x);
        }
        cout<<segx.qry(1,n)<<'\n';
    }

    return 0;
}