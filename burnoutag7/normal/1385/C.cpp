#include<bits/stdc++.h>
using namespace std;

int n,sz,a[200005];
int pre[200005];
int suf[200005];
int dat[800005];

void upd(int pos,int val){
    pos+=sz-1;
    dat[pos]=val;
    while(pos>1){
        pos>>=1;
        dat[pos]=max(dat[pos<<1],dat[pos<<1|1]);
    }
}

int qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr)return dat[bk];
    return max(qry(bk<<1,l,(l+r)>>1,ql,qr),qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;sz=1;while(sz<n)sz<<=1;
        pre[0]=suf[n+1]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=max(pre[i-1],a[i]);
        }
        for(int i=n;i>=1;i--){
            suf[i]=max(suf[i+1],a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            upd(a[i],i);
            if(pre[i]>a[i]&&suf[i]>a[i]){
                ans=max(ans,qry(1,1,sz,a[i]+1,200000));
            }
        }
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++){
            upd(a[i],0);
        }
    }

    return 0;
}