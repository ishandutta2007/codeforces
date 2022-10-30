#include <bits/stdc++.h>
using namespace std;

int n;
int sz;
struct st{
    int x,y,z;
};
st a[600005];
int all;
int tree[30000000];
vector<int> v;
map<int,bool> used;
map<int,int> qwer;
inline bool cmp(st a,st b){
    return a.x>b.x;
}
//
void update(int x,int y){
    x+=sz-1;
    tree[x]=max(tree[x],y);
    x>>=1;
    while (x) {
        tree[x]=max(tree[x+x],tree[x+x+1]);
        x>>=1;
    }
}
int get(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)>>1;
    return max(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;++i){
        cin>>a[i].x;
        if (used[a[i].x]==false) {
            used[a[i].x]=true;
            v.push_back(a[i].x);
        }
    }
    for (int i=1;i<=n;++i){
        cin>>a[i].y;
        if (used[a[i].y]==false) {
            used[a[i].y]=true;
            v.push_back(a[i].y);
        }
    }
    for (int i=1;i<=n;++i){
        cin>>a[i].z;
        if (used[a[i].z]==false) {
            used[a[i].z]=true;
            v.push_back(a[i].z);
        }
    }
    sort(v.begin(),v.end());
    int last=0;
    for (int i=0;i<v.size();++i) {
        if (i==0 || v[i]!=v[i-1]) {
            ++last;
            qwer[v[i]]=last;
        }
    }
    for (int i=1;i<=n;++i) {
        a[i].x=qwer[a[i].x];
        a[i].y=qwer[a[i].y];
        a[i].z=qwer[a[i].z];
    }
    sort(a+1,a+n+1,cmp);
    sz=1;
    while (sz<1e6+5*1e5) sz+=sz;
    for (int i=1;i<=n;++i) {
        if (i<n && a[i].x==a[i+1].x) continue;
        int j=i;
        while (j && a[j].x==a[i].x) {
            int q=get(1,sz,a[j].y+1,1e6+5*1e5,1);
            if (q>a[j].z) ++ans;
            --j;
        }
        j=i;
        while (j && a[j].x==a[i].x) {
            update(a[j].y,a[j].z);
            --j;
        }
    }
    cout<<ans;
}