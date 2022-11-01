#include<bits/stdc++.h>
using namespace std;

int n,a[100005],tr[3000005][2],tot;
vector<int> b[3000005];

void add(int x,int y){
    int u=0;
    b[u].emplace_back(y);
    for(int i=29;i>=0;i--){
        if(!tr[u][x>>i&1])tr[u][x>>i&1]=tot++;
        u=tr[u][x>>i&1];
        b[u].emplace_back(y);
    }
}

int ask(int u,int l,int r){
    return upper_bound(b[u].begin(),b[u].end(),r)-lower_bound(b[u].begin(),b[u].end(),l);
}

int get(int u,int l){
    return *lower_bound(b[u].begin(),b[u].end(),l);
}

void deal(int u,int d,int l,int r,vector<int> &v){
    if(!d){
        v.emplace_back(a[get(u,l)]);
        if(ask(u,l,r)>=2)v.emplace_back(v.back());
        return;
    }
    int ls=tr[u][0]?ask(tr[u][0],l,r):0;
    if(ls>=2)deal(tr[u][0],d-1,l,r,v);
    else{
        if(ls)v.emplace_back(a[get(tr[u][0],l)]);
        if(tr[u][1]&&ask(tr[u][1],l,r))deal(tr[u][1],d-1,l,r,v);
    }
}

void mian(){
    memset(tr,0,tot<<3);
    for(int i=0;i<tot;i++)b[i].clear();
    tot=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(a[i],i);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        vector<int> v;
        deal(0,30,l,r,v);
        int ans=1<<30;
        for(int i=0;i<v.size();i++)for(int j=i+1;j<v.size();j++)ans=min(ans,v[i]|v[j]);
        cout<<ans<<'\n';
    }
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