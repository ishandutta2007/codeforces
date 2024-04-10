#include<bits/stdc++.h>

using namespace std;

const int maxn=1000005;

struct qry{
    int l,r,i;
};

struct lsh{
    int v,i;
};

bool cmp(lsh a,lsh b){
    return a.v<b.v;
}
bool cmp1(qry a,qry b){
    return a.r<b.r;
}

lsh l[maxn];
int n,m;
int a[maxn];
int d[maxn];
qry q[maxn];
int pfx[maxn];
int lap[maxn],loc[maxn];
int rsl[maxn];
int bit[maxn];

int lbt(int n){
    return n&(-n);
}
void chg(int i,int v){
    while(i<=n){
        bit[i]^=v;
        i+=lbt(i);
    }
}
int qry(int i){
    int ans=0;
    while(i){
        ans^=bit[i];
        i-=lbt(i);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;q[i].i=i;
    }
    for(int i=1;i<=n;i++){
        l[i].i=i;
        l[i].v=a[i];
    }
    sort(l+1,l+1+n,cmp);
    int cur=1;
    for(int i=1;i<=n;i++){
        if(i!=1&&l[i].v!=l[i-1].v)cur++;
        d[l[i].i]=cur;
    }
    for(int i=1;i<=n;i++){
        loc[i]=lap[d[i]];
        lap[d[i]]=i;
    }
    for(int i=1;i<=n;i++)pfx[i]=pfx[i-1]^a[i];
    sort(q+1,q+1+m,cmp1);
    int cr=0;
    for(int i=1;i<=m;i++){
        while(cr<q[i].r){
            cr++;
            chg(cr,a[cr]);
            if(loc[cr])chg(loc[cr],a[cr]);
        }
        int ans=qry(q[i].l-1)^qry(q[i].r);
        rsl[q[i].i]=pfx[q[i].r]^pfx[q[i].l-1]^ans;
    }
    for(int i=1;i<=m;i++)cout<<rsl[i]<<'\n';
    return 0;
}