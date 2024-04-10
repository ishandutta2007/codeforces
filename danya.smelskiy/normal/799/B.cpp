#include <bits/stdc++.h>
using namespace std;
int n;
long long p[200005];
long long a[200005];
long long b[200005];
long long x,y;
set<pair<long long,int> > s[5];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>p[i];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    for (int i=1;i<=n;++i) {
        x=a[i];
        y=b[i];
        s[x].insert(make_pair(p[i],i));
        s[y].insert(make_pair(p[i],i));
    }
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (s[x].empty()) {
            cout<<"-1 ";
            continue;
        }
        y=s[x].begin()->second;
        cout<<p[y]<<" ";
        s[x].erase(s[x].begin());
        if (x==a[y]) s[b[y]].erase(make_pair(p[y],y));
        else s[a[y]].erase(make_pair(p[y],y));
    }
}