#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

int n,m,sz;
int a[200005];
ll dat[800005];
ll lazy[800005];

void build(int bk,int l,int r){
    if(l==r){
        if(l<=n){
            dat[bk]=a[l];
        }else{
            dat[bk]=1145141919810;
        }
        return;
    }
    build(bk<<1,l,(l+r)>>1);
    build(bk<<1|1,((l+r)>>1)+1,r);
    dat[bk]=min(dat[bk<<1],dat[bk<<1|1]);
}

void upd(int bk,int l,int r,int ql,int qr,ll val){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        lazy[bk]+=val;
        dat[bk]+=val;
        return;
    }
    lazy[bk<<1]+=lazy[bk];
    dat[bk<<1]+=lazy[bk];
    lazy[bk<<1|1]+=lazy[bk];
    dat[bk<<1|1]+=lazy[bk];
    lazy[bk]=0;
    upd(bk<<1,l,(l+r)>>1,ql,qr,val);
    upd(bk<<1|1,((l+r)>>1)+1,r,ql,qr,val);
    dat[bk]=min(dat[bk<<1],dat[bk<<1|1]);
}

ll qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 1145141919810;
    if(ql<=l&&r<=qr){
        return dat[bk];
    }
    lazy[bk<<1]+=lazy[bk];
    dat[bk<<1]+=lazy[bk];
    lazy[bk<<1|1]+=lazy[bk];
    dat[bk<<1|1]+=lazy[bk];
    lazy[bk]=0;
    return min(qry(bk<<1,l,(l+r)>>1,ql,qr),qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;sz=1;while(sz<n)sz<<=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,sz);
    cin>>m;
    string s;
    getline(cin,s);
    while(m--){
        vector<int> v;
        {
            getline(cin,s);
            istringstream ss(s);
            int t;
            while(ss>>t)v.push_back(t);
        }
        if(v.size()==2){
            int l=v[0]+1,r=v[1]+1;
            if(l>r){
                cout<<min(qry(1,1,sz,l,n),qry(1,1,sz,1,r))<<endl;
            }else{
                cout<<qry(1,1,sz,l,r)<<endl;
            }
        }else{
            int l=v[0]+1,r=v[1]+1,val=v[2];
            if(l>r){
                upd(1,1,sz,l,n,val);
                upd(1,1,sz,1,r,val);
            }else{
                upd(1,1,sz,l,r,val);
            }
        }
    }

    return 0;
}