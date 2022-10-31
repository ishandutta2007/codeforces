#include <bits/stdc++.h>
using namespace std;


int n,m;
int a[(1<<22)+5];
int p[(1<<22)+5];
int c[(1<<22)+5];
int x,y,ans;
int msk2;
bool slit[(1<<22)+5];
bool used[(1<<22)+5];

int get(int x) {
    if (x==p[x]) return x;
    return p[x]=get(p[x]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>a[i];
        ++c[a[i]];
    }
    for (int i=0;i<(1<<n);++i)
        p[i]=i;
    for (int i=0;i<n;++i) {
        for (int j=0;j<(1<<n);++j)
        if (j&(1<<i)) {
            x=(j^(1<<i));
            c[j]+=c[x];
        }
    }
    vector<pair<int,int> > qq;

    int msk=(1<<n)-1;
    for (int i=1;i<=m;++i) {
        x=a[i];
        msk2=(msk^a[i]);
        if (c[msk2]) {
            slit[msk2]=true;
            qq.push_back(make_pair(msk2,x));
        }
    }
    for (int i=(1<<n)-1;i>=0;--i) if (slit[i]) {
        for (int j=0;j<n;++j)
        if ((i&(1<<j))) {
            x=(i^(1<<j));
            if (!c[x]) continue;
            slit[x]=true;
            x=get(x);
            y=get(i);
            if (x!=y) p[x]=y;
        }
    }

    for (int i=0;i<qq.size();++i) {
        x=qq[i].first;
        y=qq[i].second;
        x=get(x);
        y=get(y);
        if (x!=y) p[x]=y;
    }
    for (int i=1;i<=m;++i) {
        x=a[i];
        x=get(x);
        if (!used[x]) {
            ++ans;
            used[x]=true;
        }
    }
    cout<<ans;
}