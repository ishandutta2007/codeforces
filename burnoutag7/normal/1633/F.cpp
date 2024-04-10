#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> g[200005];
int hson[200005],fa[200005],dep[200005],sub[200005],top[200005],dfn[200005],dfc,fid[200005];

int hldprec(int x,int p,int d){
    dep[x]=d;
    sub[x]=1;
    for(auto &[y,z]:g[x])if(y!=p){
        fid[y]=z;
        sub[x]+=hldprec(y,x,d+1);
        fa[y]=x;
        if(sub[y]>sub[hson[x]]){
            hson[x]=y;
        }
    }
    return sub[x];
}

void hlddec(int x,int head){
    top[x]=head;
    dfn[x]=++dfc;
    if(hson[x]){
        hlddec(hson[x],head);
        for(auto &[y,z]:g[x])if(y!=fa[x]&&y!=hson[x]){
            hlddec(y,y);
        }
    }
}

const int sz=1<<18;
typedef long long ll;
int sum[sz<<1];
ll esum[sz<<1],etot[sz<<1];
bool tag[sz<<1],etag[sz<<1];

void push(int id){
    if(tag[id]){
        sum[id<<1]=-sum[id<<1];
        tag[id<<1]^=1;
        sum[id<<1|1]=-sum[id<<1|1];
        tag[id<<1|1]^=1;
        tag[id]=0;
    }
    if(etag[id]){
        esum[id<<1]=etot[id<<1]-esum[id<<1];
        etag[id<<1]^=1;
        esum[id<<1|1]=etot[id<<1|1]-esum[id<<1|1];
        etag[id<<1|1]^=1;
        etag[id]=0;
    }
}

void add(int id,int l,int r,int q,int qid){
    if(q<l||r<q)return;
    if(q<=l&&r<=q){
        sum[id]=1;
        esum[id]=etot[id]=qid;
        return;
    }
    push(id);
    add(id<<1,l,l+r>>1,q,qid);
    add(id<<1|1,(l+r>>1)+1,r,q,qid);
    sum[id]=sum[id<<1]+sum[id<<1|1];
    esum[id]=esum[id<<1]+esum[id<<1|1];
    etot[id]=etot[id<<1]+etot[id<<1|1];
}

int ask(int id,int l,int r,int q){
    if(q<l||r<q)return 0;
    if(q<=l&&r<=q){
        return esum[id];
    }
    push(id);
    return ask(id<<1,l,l+r>>1,q)+ask(id<<1|1,(l+r>>1)+1,r,q);
}

void rev(int id,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        sum[id]=-sum[id];
        tag[id]^=1;
        esum[id]=etot[id]-esum[id];
        etag[id]^=1;
        return;
    }
    push(id);
    rev(id<<1,l,l+r>>1,ql,qr);
    rev(id<<1|1,(l+r>>1)+1,r,ql,qr);
    sum[id]=sum[id<<1]+sum[id<<1|1];
    esum[id]=esum[id<<1]+esum[id<<1|1];
}

int path(int u){
    int v=u;
    while(u){
        rev(1,1,sz,dfn[top[u]],dfn[u]);
        u=fa[top[u]];
    }
    add(1,1,sz,dfn[v],fid[v]);
    return 0;
}

int main(){

    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b,i);
        g[b].emplace_back(a,i);
    }
    hldprec(1,-1,0);
    hlddec(1,1);
    path(1);
    int act=1;
    while(true){
        char typ;
        int u;
        cin>>typ;
        if(typ=='1'){
            cin>>u;
            path(u);act++;
            cout<<(sum[1]?0:esum[1])<<'\n';
        }else if(typ=='2'){
            if(sum[1]){
                cout<<"0\n";
                continue;
            }
            cout<<act/2<<' ';
            int tmp;
            static vector<int> ans;
            ans.clear();
            for(int i=1;i<=n;i++)if(tmp=ask(1,1,sz,dfn[i]))ans.emplace_back(tmp);
            sort(ans.begin(),ans.end());
            for(int x:ans)cout<<x<<' ';
            cout<<'\n';
        }else if(typ=='3')break;
    }

    return 0;
}