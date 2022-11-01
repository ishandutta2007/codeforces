#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q,gre,red,sec,sz;
ll pre[100005];
ll suf[100005];
vector<int> mp;
int dat[400005];

void upd(int pos,int val){
    pos+=sz-1;
    dat[pos]=val;
    while(pos>1){
        pos>>=1;
        dat[pos]=min(dat[pos<<1],dat[pos<<1|1]);
    }
}

int qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0x3f3f3f3f;
    if(ql<=l&&r<=qr)return dat[bk];
    return min(qry(bk<<1,l,(l+r)>>1,ql,qr),qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>gre>>red;
    sec=gre+red;
    for(int i=1;i<=n+1;i++){
        int a;
        cin>>a;
        pre[i]=pre[i-1]+a;
    }

    mp.resize(n+1);
    for(int i=0;i<=n;i++){
        mp[i]=pre[i]%sec;
    }
    sort(mp.begin(),mp.end());
    mp.erase(unique(mp.begin(),mp.end()),mp.end());

    sz=1;while(sz<mp.size())sz<<=1;
    memset(dat,0x3f,sizeof(dat));

    for(int i=n;i>=1;i--){
        int from=(pre[i]+gre)%sec,to=(pre[i]+sec-1)%sec;
        int nxt,l=lower_bound(mp.begin(),mp.end(),from)-mp.begin()+1,r=upper_bound(mp.begin(),mp.end(),to)-mp.begin();
        if(from<=to){
            nxt=qry(1,1,sz,l,r);
        }else{
            nxt=min(qry(1,1,sz,l,mp.size()),qry(1,1,sz,1,r));
        }
        if(nxt==0x3f3f3f3f)suf[i]=pre[n+1]-pre[i];
        else{
            suf[i]=suf[nxt]+pre[nxt]-pre[i]+sec-(pre[nxt]-pre[i])%sec;
        }
        upd(lower_bound(mp.begin(),mp.end(),pre[i]%sec)-mp.begin()+1,i);
    }

    cin>>q;
    while(q--){
        int t;
        cin>>t;
        int ot=t;
        t%=sec;
        int from=(gre-t+sec)%sec,to=(sec-t-1)%sec;
        int nxt,l=lower_bound(mp.begin(),mp.end(),from)-mp.begin()+1,r=upper_bound(mp.begin(),mp.end(),to)-mp.begin();
        if(from<=to){
            nxt=qry(1,1,sz,l,r);
        }else{
            nxt=min(qry(1,1,sz,l,mp.size()),qry(1,1,sz,1,r));
        }
        if(nxt==0x3f3f3f3f)cout<<pre[n+1]+ot<<'\n';
        else{
            cout<<suf[nxt]+pre[nxt]+ot+sec-(pre[nxt]+ot)%sec<<'\n';
        }
    }

    return 0;
}