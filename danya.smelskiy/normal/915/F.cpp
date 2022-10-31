#include <bits/stdc++.h>
using namespace std;


int n;
pair<long long,int >a[1000005];
int x,y;
long long sz[1000005];
int p[1000005];
bool used[1000005];
vector<int> v[1000005];

int get(int x) {
    if (x==p[x]) return x;
    return p[x]=get(p[x]);
}
long long ans;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first;
        a[i].second=i;
    }
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        p[i]=i;
    for (int i=1;i<=n;++i) {
        x=a[i].second;
        used[x]=true;
        sz[x]=1;
        long long kol=1;
        for (int j=0;j<v[x].size();++j) {
            int to=v[x][j];
            if (used[to]==false) continue;
            to=get(to);
            ans+=sz[to]*kol*a[i].first;
            kol+=sz[to];
            sz[x]+=sz[to];
            p[to]=x;
        }
    }
    memset(used,false,sizeof(used));
    for (int i=1;i<=n;++i) {
        p[i]=i;
        sz[i]=1;
    }
    for (int i=n;i>0;--i) {
        x=a[i].second;
        used[x]=true;
        sz[x]=1;
        long long kol=1;
        for (int j=0;j<v[x].size();++j) {
            int to=v[x][j];
            if (used[to]==false) continue;
            to=get(to);
            ans-=sz[to]*kol*a[i].first;
            kol+=sz[to];
            sz[x]+=sz[to];
            p[to]=x;
        }
    }
    cout<<ans;
}