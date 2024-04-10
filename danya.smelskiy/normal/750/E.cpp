#include <bits/stdc++.h>
using namespace std;

int pos[20];
struct nd{
    int a[6][6];
};
nd t[600005];
int n,m;
int sz;
inline void add_node(int x,int y){
    for (int i=0;i<5;++i)
        for (int j=0;j<5;++j)
            t[x].a[i][j]=1e9;
    for (int i=0;i<5;++i)
        t[x].a[i][i]=0;
    int z=pos[y];
    if (!z) return;
    if (z==5){
        t[x].a[3][3]=1;
        t[x].a[4][4]=1;
        return;
    }
    t[x].a[z-1][z-1]=1;
    t[x].a[z-1][z]=0;
}
inline nd mrg(nd a,nd b){
    nd c;
    for (int i=0;i<5;++i) {
        for (int j=i;j<5;++j) {
            c.a[i][j]=1e9;
            for (int k=i;k<=j;++k)
                c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
        }
    }
    return c;
}
nd get(int l,int r,int ll,int rr,int x){
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    if (rr<=mid) return get(l,mid,ll,rr,x+x);
    else if (ll>mid) return get(mid+1,r,ll,rr,x+x+1);
    else return mrg(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pos[0]=2;
    pos[1]=3;
    pos[2]=1;
    pos[7]=4;
    pos[6]=5;
    cin>>n>>m;
    string s;
    cin>>s;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=0;i<n;++i)
        add_node(sz+i,s[i]-'0');
    for (int i=sz-1;i>0;--i){
        t[i]=mrg(t[i+i],t[i+i+1]);
    }
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        nd res=get(1,sz,x,y,1);
        if (res.a[0][4]==1e9) cout<<"-1"<<'\n';
        else cout<<res.a[0][4]<<'\n';
    }
}