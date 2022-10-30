#include <bits/stdc++.h>
using namespace std;


long long n,m,x;
long long a[200005];
set<pair<long long,long long> > s;
vector<long long> v;
long long cnt,cnt2;


main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>x;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        if (a[i]==0) v.push_back(i);
        else if (a[i]<0) ++cnt2;
    }
    long long cnt=0;
    while (cnt<v.size() && m) {
        long long y=v[cnt];
        if (cnt2&1) a[y]+=x;
        else a[y]-=x,++cnt2;
        ++cnt;
        --m;
    }
    cnt=0;
    long long pos;
    long long mn=2e9;
    for (int i=1;i<=n;++i) {
        if (a[i]<0) ++cnt;
        if (abs(a[i])<mn) {
            mn=abs(a[i]);
            pos=i;
        }
    }
    if (cnt%2==0) {
        long long kol=mn/x+1ll;
        kol=min(kol,m);
        if (kol<=m) {
            m-=kol;
            mn=a[pos];
            if (mn<0) mn+=kol*x;
            else mn-=kol*x;
            a[pos]=mn;
        }
    }
    for (int i=1;i<=n;++i)
        s.insert(make_pair(abs(a[i]),i));
    while (!s.empty() && m) {
        --m;
        long long y=s.begin()->second;
        s.erase(s.begin());
        if (a[y]<0) a[y]-=x;
        else a[y]+=x;
        s.insert(make_pair(abs(a[y]),y));
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}