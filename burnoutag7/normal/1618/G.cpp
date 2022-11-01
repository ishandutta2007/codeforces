#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,q,l[400005],r[400005];
pair<int,int> a[400005],e[400005],qs[200005];
pair<ll,int> pre[400005];
ll ansv,ans[200005];

int fl(int x){return l[x]==x?x:l[x]=fl(l[x]);}

int fr(int x){return r[x]==x?x:r[x]=fr(r[x]);}

void link(int x){
    int lb,rb;
    lb=fl(x),rb=x;
    ansv-=pre[rb].first-pre[rb-(pre[rb].second-pre[lb-1].second)].first;
    lb=x+1,rb=fr(x+1);
    ansv-=pre[rb].first-pre[rb-(pre[rb].second-pre[lb-1].second)].first;
    lb=fl(x);
    r[x]=rb;
    l[x+1]=lb;
    ansv+=pre[rb].first-pre[rb-(pre[rb].second-pre[lb-1].second)].first;
}

void ascend(int k){
    static int i=1;
    for(;i<n+m&&e[i].first<=k;i++){
        link(e[i].second);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    iota(l+1,l+1+n+m,1);
    iota(r+1,r+1+n+m,1);
    for(int i=1;i<=n;i++){
        cin>>a[i].first;a[i].second=1;
        ansv+=a[i].first;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i+n].first;
    }
    sort(a+1,a+1+n+m);
    for(int i=1;i<=n+m;i++){
        pre[i]={pre[i-1].first+a[i].first,pre[i-1].second+a[i].second};
    }
    for(int i=1;i<n+m;i++){
        e[i].first=a[i+1].first-a[i].first;
        e[i].second=i;
    }
    sort(e+1,e+n+m);
    for(int i=1;i<=q;i++){
        cin>>qs[i].first;
        qs[i].second=i;
    }
    sort(qs+1,qs+1+q);
    for(int i=1;i<=q;i++){
        ascend(qs[i].first);
        ans[qs[i].second]=ansv;
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';

    return 0;
}