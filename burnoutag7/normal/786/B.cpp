#include<bits/stdc++.h>
using namespace std;

struct node{
    int ls,rs;
    long long d;
    vector<pair<int,int>> g;
};

int n,q,s,sz;
node a[600005];

void addto(const int &bk,const int &l,const int &r,const int &ql,const int &qr,const int &v,const int &w){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        a[v].g.emplace_back(bk,w);//cout<<v<<' '<<bk<<'\n';
        return;
    }
    addto(a[bk].ls,l,l+r>>1,ql,qr,v,w);
    addto(a[bk].rs,(l+r>>1)+1,r,ql,qr,v,w);
}

void addfrom(const int &bk,const int &l,const int &r,const int &ql,const int &qr,const int &v,const int &w){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        a[bk].g.emplace_back(v,w);//cout<<bk<<' '<<v<<'\n';
        return;
    }
    addfrom(a[bk].ls,l,l+r>>1,ql,qr,v,w);
    addfrom(a[bk].rs,(l+r>>1)+1,r,ql,qr,v,w);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q>>s;
    sz=1;
    while(sz<n)sz<<=1;
    for(int i=1;i<sz;i++){
        a[i].ls=i<<1;
        a[i].rs=i<<1|1;
        a[i].d=1e18;
        a[i].g.emplace_back(i<<1,0);//cout<<i<<' '<<(i<<1)<<'\n';
        a[i].g.emplace_back(i<<1|1,0);//cout<<i<<' '<<(i<<1|1)<<'\n';
        if(i<<1<sz){
            a[i+(sz<<1)-1].ls=(i<<1)+(sz<<1)-1;
            a[i+(sz<<1)-1].rs=(i<<1|1)+(sz<<1)-1;
            a[i+(sz<<1)-1].d=1e18;
            a[(i<<1)+(sz<<1)-1].g.emplace_back(i+(sz<<1)-1,0);//cout<<(i<<1)+(sz<<1)-1<<' '<<i+(sz<<1)-1<<'\n';
            a[(i<<1|1)+(sz<<1)-1].g.emplace_back(i+(sz<<1)-1,0);//cout<<(i<<1|1)+(sz<<1)-1<<' '<<i+(sz<<1)-1<<'\n';
        }else{
            a[i+(sz<<1)-1].ls=i<<1;
            a[i+(sz<<1)-1].rs=i<<1|1;
            a[i+(sz<<1)-1].d=1e18;
            a[i<<1].g.emplace_back(i+(sz<<1)-1,0);//cout<<(i<<1)<<' '<<i+(sz<<1)-1<<'\n';
            a[i<<1|1].g.emplace_back(i+(sz<<1)-1,0);//cout<<(i<<1|1)<<' '<<i+(sz<<1)-1<<'\n';
        }
    }
    for(int i=sz;i<=(sz<<1)-1;i++){
        a[i].ls=a[i].rs=-1;
        a[i].d=1e18;
    }
    while(q--){
        int typ,u,v,l,r,w;
        cin>>typ;
        if(typ==1){
            cin>>v>>u>>w;
            a[v+sz-1].g.emplace_back(u+sz-1,w);//cout<<v+sz-1<<' '<<u+sz-1<<'\n';
        }else{
            cin>>v>>l>>r>>w;
            if(typ==2){
                addto(1,1,sz,l,r,v+sz-1,w);
            }else{
                addfrom(sz+sz,1,sz,l,r,v+sz-1,w);
            }
        }
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.emplace(0ll,s+sz-1);
    a[s+sz-1].d=0;
    while(!pq.empty()){
        int x=pq.top().second;
        long long cd=pq.top().first;
        pq.pop();
        if(cd>a[x].d)continue;
        for(pair<int,int> &e:a[x].g){
            if(a[e.first].d>cd+e.second){
                a[e.first].d=cd+e.second;
                pq.emplace(a[e.first].d,e.first);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i+sz-1].d<1e18){
            cout<<a[i+sz-1].d<<' ';
        }else{
            cout<<"-1 ";
        }
    }

    return 0;
}