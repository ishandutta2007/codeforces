#include<bits/stdc++.h>
using namespace std;

int n,a[200005],pre[200005],suf[200005],sz,dat[800005];

void upd(int pos,int val){
    pos+=sz-1;
    dat[pos]=val;
    while(pos>1){
        pos>>=1;
        dat[pos]=min(dat[pos<<1],dat[pos<<1|1]);
    }
}

int qry(int id,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 1e9;
    if(ql<=l&&r<=qr)return dat[id];
    return min(qry(id<<1,l,(l+r)>>1,ql,qr),qry(id<<1|1,((l+r)>>1)+1,r,ql,qr));
};

void mian(){
    cin>>n;
    sz=1;
    while(sz<n)sz<<=1;
    memset(dat,0x3f,sz<<2);
    pre[0]=suf[n+1]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        upd(i,a[i]);
        pre[i]=max(pre[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)suf[i]=max(suf[i+1],a[i]);
    for(int i=1,jl=n,jr=n;i<=n;i++){
        while(jl-1>i+1&&suf[jl-1]<=pre[i])jl--;
        while(jr>jl&&suf[jr]<pre[i])jr--;
        jl=max(jl,i+2);
        if(suf[jl]!=pre[i]||suf[jr]!=pre[i]||jr<=i+1)continue;
        int l=jl-1,r=jr-1,m,res=jl-1;
        while(l<=r){
            m=l+r>>1;
            if(qry(1,1,sz,i+1,m)<pre[i]){
                r=m-1;
            }else{
                l=m+1;
                res=m;
            }
        }
        if(qry(1,1,sz,i+1,res)==pre[i]){
            cout<<"YES\n"<<i<<' '<<res-i<<' '<<n-res<<'\n';
            return;
        }
    }
    cout<<"NO\n";
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