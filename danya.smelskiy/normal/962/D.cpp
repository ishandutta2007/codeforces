#include <bits/stdc++.h>
using namespace std;


int n;
bool used[150005];
long long a[150005];
set<pair<long long,long long> > s;
set<long long> s2;
map<long long,int> cnt;


inline void add(long long x,long long y) {
    ++cnt[x];
    s.insert(make_pair(x,y));
    if (cnt[x]==2) s2.insert(x);
}

inline void del(long long x,long long y) {
    --cnt[x];
    s.erase(make_pair(x,y));
    if (cnt[x]==1) s2.erase(x);
}

inline long long get_f(long long x) {
    set<pair<long long,long long> > ::iterator q=s.lower_bound(make_pair(x,0));
    return q->second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        add(a[i],i);
    }
    long long x;
    long long y,z;
    while (!s2.empty()) {
        x=*s2.begin();
        y=get_f(x);
        del(x,y);
        z=get_f(x);
        del(x,z);
        add(x+x,z);
    }
    int m=s.size();
    cout<<m<<'\n';
    while (!s.empty()) {
        x=s.begin()->first;
        y=s.begin()->second;
        used[y]=true;
        a[y]=x;
        s.erase(s.begin());
    }
    for (int i=1;i<=n;++i)
        if (used[i]) cout<<a[i]<<" ";


}