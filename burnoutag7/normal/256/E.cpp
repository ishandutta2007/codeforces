#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=777777777;

struct SegTree{
    int sz;
    array<array<int,3>,3> w,d0;
    vector<array<array<int,3>,3>> dat;
    SegTree(const int& _sz){
        sz=1;
        while(sz<_sz)sz<<=1;
        dat.resize(sz<<1);
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)d0[i][j]=-1;
    }
    void upd(int p,const int& v){
        p+=sz-1;
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)dat[p][i][j]=(v==-1||v==i)&&i==j;
        while(p>1){
            p>>=1;
            for(int i=0;i<3;i++)for(int j=0;j<3;j++){
                dat[p][i][j]=0;
                for(int k=0;k<3;k++)for(int l=0;l<3;l++){
                    dat[p][i][j]=(dat[p][i][j]+(ll)dat[p<<1][i][k]*w[k][l]*dat[p<<1|1][l][j])%mod;
                }
            }
        }
    }
    array<array<int,3>,3> qry(const int& id,const int& l,const int& r,const int& ql,const int& qr){
        if(qr<l||r<ql)return d0;
        if(ql<=l&&r<=qr)return dat[id];
        const array<array<int,3>,3>& dl=qry(id<<1,l,l+r>>1,ql,qr),& dr=qry(id<<1|1,(l+r>>1)+1,r,ql,qr);
        array<array<int,3>,3> d;
        if(dl==d0)return dr;
        else if(dr==d0)return dl;
        for(int i=0;i<3;i++)for(int j=0;j<3;j++){
            d[i][j]=0;
            for(int k=0;k<3;k++)for(int l=0;l<3;l++){
                d[i][j]=(d[i][j]+(ll)dl[i][k]*w[k][l]*dr[l][j])%mod;
            }
        }
        return d;
    }
    int qry(const int& ql,const int& qr){
        const array<array<int,3>,3>& d=qry(1,1,sz,ql,qr);
        assert(d!=d0);
        int res=0;
        for(int i=0;i<3;i++)for(int j=0;j<3;j++){
            res=(res+d[i][j])%mod;
        }
        return res;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    SegTree tree(n);
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>>tree.w[i][j];
    for(int i=1;i<=n;i++)tree.upd(i,-1);
    while(m--){
        static int p,x;
        cin>>p>>x;
        tree.upd(p,x-1);
        cout<<tree.qry(1,n)<<'\n';
    }

    return 0;
}