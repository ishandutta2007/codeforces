#include<bits/stdc++.h>
using namespace std;

int n,m,k,sz;
int dat[1600005];
int laz[1600005];

void upd(int bk,int l,int r,int ql,int qr,int val){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        laz[bk]+=val;
        dat[bk]+=val;
        return;
    }
    laz[bk<<1]+=laz[bk];
    dat[bk<<1]+=laz[bk];
    laz[bk<<1|1]+=laz[bk];
    dat[bk<<1|1]+=laz[bk];
    laz[bk]=0;
    upd(bk<<1,l,(l+r)>>1,ql,qr,val);
    upd(bk<<1|1,((l+r)>>1)+1,r,ql,qr,val);
    dat[bk]=max(dat[bk<<1],dat[bk<<1|1]);
}

int qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr){
        return dat[bk];
    }
    laz[bk<<1]+=laz[bk];
    dat[bk<<1]+=laz[bk];
    laz[bk<<1|1]+=laz[bk];
    dat[bk<<1|1]+=laz[bk];
    laz[bk]=0;
    return max(qry(bk<<1,l,(l+r)>>1,ql,qr),qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr));
}

set<pair<int,int>> ps;
int cnt[400005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>m;
    sz=1;
    while(sz<n<<1)sz<<=1;
    for(int i=1;i<=m;i++){
        int x,y,nd;
        cin>>x>>y;
        nd=abs(x-k)+y;
        if(ps.find(make_pair(x,y))==ps.end()){
            ps.insert(make_pair(x,y));
            if(!cnt[nd-1])upd(1,1,sz,nd-1,nd-1,nd-1);
            cnt[nd-1]++;
            upd(1,1,sz,1,nd-1,1);
            cout<<max(qry(1,1,sz,1,n<<1),n)-n<<endl;
        }else{
            ps.erase(make_pair(x,y));
            cnt[nd-1]--;
            if(!cnt[nd-1])upd(1,1,sz,nd-1,nd-1,1-nd);
            upd(1,1,sz,1,nd-1,-1);
            cout<<max(qry(1,1,sz,1,n<<1),n)-n<<endl;
        }
    }

    return 0;
}