#include <bits/stdc++.h>
using namespace std;


int n;
multiset<pair<long long,long long> > s;
multiset<long long> ss;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int res=1e9;
    long long fx,fy;
    cin>>fx>>fy;
    --n;
    for (int i=1;i<=n;++i) {
        long long x,y;
        cin>>x>>y;
        s.insert(make_pair(-x,y));
    }
    while (!s.empty()) {
        pair<long long,long long> q=*s.begin();
        q.first*=-1ll;
        if (q.first<=fx) break;
        s.erase(s.begin());
        ss.insert(q.second-q.first+1ll);
    }
    res=ss.size();
    while (!ss.empty()) {
        long long x=*ss.begin();
        ss.erase(ss.begin());
        if (x>fx) break;
        fx-=x;
        while (!s.empty()) {
            pair<long long,long long> q=*s.begin();
            q.first*=-1ll;
            if (q.first<=fx) break;
            s.erase(s.begin());
            ss.insert(q.second-q.first+1ll);
        }
        res=min(res,(int)ss.size());
    }
    cout<<res+1;
}