#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y;
vector<long long> q;
long long xx,yy;
set<pair<long long,long long> > s;
long long last;
map<long long,long long> ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (long long i=1;i<=n;++i) {
        cin>>x>>y;
        q.push_back(x);
        while (!s.empty()){
            xx=s.begin()->first;
            yy=s.begin()->second;
            long long  last2=max(last+yy,xx+yy-1);
            if (last2<x) {
                last=max(last+yy,xx+yy-1);
                ans[xx]=last+1;
                s.erase(s.begin());
            } else break;
        }
            if (s.size()==m+1) {
                ans[x]=-1;
                continue;
            } else {
                s.insert(make_pair(x,y));
            }
    }
    while (!s.empty()) {
        xx=s.begin()->first;
        yy=s.begin()->second;
        last=max(last+yy,xx+yy-1);
        ans[xx]=last+1;
        s.erase(s.begin());
    }
    for (long long i=0;i<q.size();++i)
        cout<<ans[q[i]]<<" ";
}