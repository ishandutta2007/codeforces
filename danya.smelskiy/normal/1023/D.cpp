#include <bits/stdc++.h>
using namespace std;



int n,m,sz;
int t[2][1000005];
int a[200005];
vector<int> v[200005];
int ans[200005];

void update(int l,int r,int ll,int rr,int x,int y,int z) {
    if (l>r || ll>r || l>rr || ll>rr) return;
    if (l==r) {
        t[x][y]=0;
        ans[l]=z;
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x,y+y,z);
    update(mid+1,r,ll,rr,x,y+y+1,z);
    t[x][y]=t[x][y+y]+t[x][y+y+1];
}

void update2(int l,int r,int ll,int rr,int x,int y,int z) {
    if (l>r || ll>r || l>rr || ll>rr || !t[x][y]) return;
    if (l==r) {
        t[x][y]=0;
        ans[l]=z;
        return;
    }
    int mid=(l+r)>>1;
    update2(l,mid,ll,rr,x,y+y,z);
    update2(mid+1,r,ll,rr,x,y+y+1,z);
    t[x][y]=t[x][y+y]+t[x][y+y+1];
}

int get(int l,int r,int ll,int rr,int x,int y) {
    if (l>r || ll>r || ll>rr || l>rr) return 0;
    if (l>=ll && r<=rr) return t[x][y];
    int mid=(l+r)>>1;
    return get(l,mid,ll,rr,x,y+y)+get(mid+1,r,ll,rr,x,y+y+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    bool tt=false;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]>m) {
            cout<<"NO";
            return 0;
        }
        if (a[i]==m) tt=true;
    }
    if (tt==false) {
        for (int i=1;i<=n;++i)
        if (a[i]==0) {
            a[i]=m;
            tt=true;
            break;
        }
        if (tt==false) {
            cout<<"NO";
            return 0;
        }
    }
    for (int i=1;i<=n;++i) {
        v[a[i]].push_back(i);
    }
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        if (a[i]==0) t[1][sz+i-1]=1;
        else t[0][sz+i-1]=1;
    }
    for (int i=sz-1;i>0;--i) {
        t[0][i]=t[0][i+i]+t[0][i+i+1];
        t[1][i]=t[1][i+i]+t[1][i+i+1];
    }
    int x;
    for (int i=m;i>0;--i) if (v[i].size()>0) {
        for (int j=0;j<v[i].size();++j) {
            x=v[i][j];
            update(1,sz,x,x,0,1,i);
        }
        update2(1,sz,v[i][0],v[i].back(),1,1,i);
        if (get(1,sz,v[i][0],v[i].back(),0,1)) {
            cout<<"NO";
            return 0;
        }
    }
    for (int i=1;i<=n;++i)
        if (!ans[i]) ans[i]=1;
        cout<<"YES"<<'\n';
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}