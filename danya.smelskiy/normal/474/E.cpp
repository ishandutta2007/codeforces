#include <bits/stdc++.h>
using namespace std;

int n,d,all;
long long sz,x;
int ans;
pair<int,int> tree[5000005];
int pred[100005];
int pos;
int l1[5000005];
int r1[5000005];
pair<int,int> get(long long l,long long r,long long ll,long long rr,int x){
    if (l>r || ll>r || l>rr || ll>rr) return make_pair(0,0);
    if (l>=ll && r<=rr) return tree[x];
    pair<int,int> res=make_pair(0,0);
    long long mid=(l+r)>>1;
    if (l1[x]) res=get(l,mid,ll,rr,l1[x]);
    if (r1[x]) res=max(res,get(mid+1,r,ll,rr,r1[x]));
    return res;
}
void update(long long l,long long r,long long ll,int x,pair<int,int> y){
    if (l==ll && r==ll) {
        tree[x]=max(tree[x],y);
        return;
    }
    tree[x]=max(tree[x],y);
    long long mid=(l+r)>>1;
    if (ll<=mid) {
        if (!l1[x]) l1[x]=++all;
        update(l,mid,ll,l1[x],y);
    } else {
        if (!r1[x]) r1[x]=++all;
        update(mid+1,r,ll,r1[x],y);
    }
}
int main(){
    //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>d;
    sz=1;
    while (sz<1e15) sz+=sz;
    all=1;
    for (int i=1;i<=n;++i) {
        cin>>x;
        pair<int,int> res=make_pair(1,i),res2;
        if (x>d) { res=get(1,sz,1,x-d,1); ++res.first; }
        res2=get(1,sz,x+d,sz,1);
        ++res2.first;
        res=max(res,res2);
        if (res.second==0) res=make_pair(1,i);
        pred[i]=res.second;
        res.second=i;
        update(1,sz,x,1,res);
        if (res.first>ans) {
            ans=res.first;
            pos=res.second;
        }
    }
    cout<<ans<<'\n';
    vector<int> q;
    while (true) {
        q.push_back(pos);
        if (pos==pred[pos]) break;
        pos=pred[pos];
    }
    reverse(q.begin(),q.end());
    for (int i=0;i<q.size();++i)
        cout<<q[i]<<" ";
}