#include <bits/stdc++.h>
using namespace std;


int kol,n,m,x,y,z;
int qq[400005];
pair<pair<int,int>,int> q[10005];
int a[100005];
int b[100005];
int sz;

inline void push(int x){
    if (!qq[x]) return;
    qq[x+x]=qq[x+x+1]=qq[x];
    qq[x]=0;
}
void update(int l,int r,int ll,int rr,int x,int y){
    if (l!=r) push(x);
    if (l>r || ll>r || l>rr || ll>rr) return;
    if (l>=ll && r<=rr) {
        qq[x]=y;
        if (l!=r) push(x);
        return;
    }
    int mid = (l+r)>>1;
    update(l,mid,ll,rr,x+x,y);
    update(mid+1,r,ll,rr,x+x+1,y);
}
inline int get_ans(int x){
    int res=b[x];
    for (int i=1;i<=kol;++i) {
        if (q[i].first.second<=x && q[i].first.second+q[i].second-1>=x) {
            int z=x-q[i].first.second;
            res=a[q[i].first.first+z];
        }
    }
    return res;
}
inline void rel() {
    for (int i=1;i<sz;++i)
        push(i);
    for (int i=1;i<=n;++i) {
        int z=qq[sz+i-1];
        if (!z) continue;
        int ll=q[z].first.first+(i-q[z].first.second);
        b[i]=a[ll];
    }
    kol=0;
    for (int i=sz;i<=sz+sz;++i)
        qq[i]=0;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    sz=1;
    while (sz<n) sz+=sz;
    int len=300;
    kol=0;
    for (int i=1;i<=m;++i) {
        int tp;
        cin>>tp;
        if (tp==2) {
            int x;
            cin>>x;
            cout<<get_ans(x)<<'\n';
        } else {
            cin>>x>>y>>z;
            ++kol;
            q[kol]=make_pair(make_pair(x,y),z);
            update(1,sz,y,y+z-1,1,kol);
        }
        if (i%len==0) rel();
    }
}