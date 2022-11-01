#include<bits/stdc++.h>
using namespace std;

int n,sz,a[300005],b[300005],d[1500000],fa[1500000];
vector<pair<int,int>> g[1500000];

void add(int id,int l,int r,int ql,int qr,int val){
    if(r<ql||qr<l)return;
    if(ql<=l&&r<=qr){
        g[val].emplace_back(id,0);
        return;
    }
    add(id*2,l,l+r>>1,ql,qr,val);
    add(id*2|1,(l+r>>1)+1,r,ql,qr,val);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sz=1;
    while(sz<n)sz<<=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=i)g[i+sz*2].emplace_back(sz*2,1);
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        g[i+sz-1].emplace_back(sz*2+i+b[i],1);
    }
    for(int i=1;i<sz;i++){
        g[i].emplace_back(i*2,0);
        g[i].emplace_back(i*2|1,0);
    }
    for(int i=1;i<=n;i++){
        add(1,1,sz,i-a[i],i,i+sz*2);
    }
    deque<int> q;
    q.emplace_back(n+sz*2);
    memset(d,0x3f,sizeof(d));
    d[n+sz*2]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop_front();
        for(auto &[y,z]:g[x])if(d[y]>d[x]+z){
            d[y]=d[x]+z;
            fa[y]=x;
            if(z)q.emplace_back(y);
            else q.emplace_front(y);
        }
    }
    if(d[sz*2]==0x3f3f3f3f){
        cout<<-1;
        return 0;
    }
    cout<<d[sz*2]<<'\n';
    int x=sz*2;
    stack<int> s;
    while(x!=n+sz*2){
        if(d[fa[x]]!=d[x])s.emplace(fa[x]-sz+1);
        x=fa[x];
    }
    while(s.size()>1){
        cout<<s.top()<<' ';
        s.pop();
    }
    cout<<0<<'\n';

    return 0;
}