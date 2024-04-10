#include<bits/stdc++.h>
using namespace std;

int n,ans,mpc;
pair<int,pair<int,int>> a[500005];
queue<pair<int,int>> q;
map<int,int> mp;
int sz;
int dat[2000005];

void upd(int pos,int val){
    pos+=sz-1;
    if(dat[pos]>val)return;
    dat[pos]=val;
    while(pos>1){
        pos>>=1;
        dat[pos]=max(dat[pos<<1],dat[pos<<1|1]);
    }
}

int qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql||l>r)return 0;
    if(ql<=l&&r<=qr)return dat[bk];
    return max(qry(bk<<1,l,(l+r)>>1,ql,qr),qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr));
}

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].first);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].second.first);
        mp[a[i].second.first]=0;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].second.second);
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        it->second=++mpc;
    }
    sz=1;while(sz<mpc)sz<<=1;
    sort(a,a+n,[](const pair<int,pair<int,int>> &i,const pair<int,pair<int,int>> &j){
        if(i.first!=j.first)return i.first>j.first;
        if(i.second.first!=j.second.first)return i.second.first>j.second.first;
        return i.second.second>j.second.second;
    });
    for(int i=0;i<n;i++){
        if(i&&a[i].first!=a[i-1].first){
            while(!q.empty()){
                upd(q.front().first,q.front().second);
                q.pop();
            }
        }
        ans+=qry(1,1,sz,mp[a[i].second.first]+1,mpc)>a[i].second.second;
        q.push(make_pair(mp[a[i].second.first],a[i].second.second));
    }
    cout<<ans<<endl;

    return 0;
}